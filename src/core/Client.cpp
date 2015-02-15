#include "core/Client.h"
#include "core/FTPServer.h"

using namespace FTP;

unsigned int Client::_uidCounter(0);

Client::Client(FTPServer* server, TCP::Socket& socket) : _uid(_uidCounter++), _socket(std::move(socket)), _server(server), _user(), _currrentDirectory("/"),
	_inPassiveMode(false), _activeDataSocket(), _passiveDataSocket() {

}

void Client::run() {
	std::cout << "New client connected width id=" << _uid << " [" << _socket.getAddress() << "]" << std::endl;

	Packet packet;

	AnswerSuccess answer;
	answer.addArgument(_server->getConfiguration().getMOTD());
	answer.generatePacket(packet);

	std::cout << packet << std::endl;

	_socket.send(packet);

	while(_socket.isOpen()) {
		Packet packet;

		_socket.receive(packet);

		std::cout << "Received buffer (" << packet.getSize() << ")" << std::endl;
		std::cout <<  packet << std::endl;

		Request* message = RequestFactory::eval(packet);

		if(message != nullptr) {
			RequestHandler::process(*message, this);
			delete message;
		}
		else {
			Packet answer_packet;

			AnswerUnimplemented answer;
			answer.addArgument("Uninplemented command");
			answer.generatePacket(answer_packet);

			_socket.send(answer_packet);
		}
	}

	std::cout << "[Client " << _uid << "] Disconnected " << std::endl;
}
bool Client::setUsername(const std::string& username) {
	if(_server->getConfiguration().getUserList().hasUser(username)) {
		_user = User(_server->getConfiguration().getUserList().findUser(username));
		return true;
	}

	return false;
}

bool Client::login(const std::string& password) {
	if(password == _user.getPassword()) {
		return true;
	}
	return false;
}

void Client::resetLogin() {
	_user = User();
}

void Client::openActiveConnection() {
	if(_nextActivePort == 0)
		THROW(NoActiveConnectionException, "");

	_activeDataSocket.connect(_nextActiveAddress, _nextActivePort);
	std::cout << "[Client " << _uid << "] Open new active data connection (" << _nextActiveAddress << ":" << _nextActivePort << ") " << std::endl;
}

void Client::closeActiveConnection() {
	_activeDataSocket.close();
	std::cout << "[Client " << _uid << "] close active data connection" << std::endl;
}

void Client::setNextActiveConnection(const IP::Address& address, unsigned int port) {
	_nextActiveAddress = address;
	_nextActivePort = port;
}

void Client::setCurrentDirectory(const std::string& pathname) {
	_currrentDirectory = pathname;
}

void Client::switchPassiveMode() {
	_inPassiveMode = true;

	_passiveDataSocket.listen();
}

const User& Client::getUser() const {
	return _user;
}

const std::string& Client::getCurrentDirectory() const {
	return _currrentDirectory;
}

TCP::Socket& Client::getSocket() {
	return _socket;
}

TCP::Socket& Client::getActiveDataSocket() {
	return _activeDataSocket;
}

TCP::Listener& Client::getPassiveDataSocket() {
	return _passiveDataSocket;
}

