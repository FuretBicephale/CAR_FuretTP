#include "core/Client.h"
#include "core/FTPServer.h"

using namespace FuretTP;

unsigned int Client::_uidCounter(0);

Client::Client(FTPServer* server, TCP::Socket& socket) : _uid(_uidCounter++), _socket(std::move(socket)), _server(server), _user(), _currDir("./") {

}

void Client::run() {
	std::cout << "New client connected width id=" << _uid << " [" << _socket.getAddress() << "]" << std::endl;

	Packet packet;

	ConnectionInitializationAnswer(_server->getConfiguration().getMOTD()).generatePacket(packet);

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

bool Client::openConnection(const IP::Address& address, unsigned int port) {
	_activeSocket.connect(address, port);

	return true;
}

void Client::setCurrentDirectory(const std::string& pathname) {

}

const User& Client::getUser() const {
	return _user;
}

const std::string& Client::getCurrentDir() const {
    return _currDir;
}

TCP::Socket& Client::getSocket() {
	return _socket;
}
