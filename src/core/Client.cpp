#include "core/Client.h"
#include "core/FTPServer.h"

using namespace FuretTP;

unsigned int Client::_uidCounter(0);

Client::Client(FTPServer* server, TCP::Socket& socket) : _uid(_uidCounter++), _socket(std::move(socket)), _server(server), _user() {

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

		RequestHandler::process(*message, this);

		delete message;
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

const User& Client::getUser() const {
	return _user;
}

TCP::Socket& Client::getSocket() {
	return _socket;
}
