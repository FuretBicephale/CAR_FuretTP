#include "core/Client.h"
#include "core/FTPServer.h"

using namespace FuretTP;

unsigned int Client::_uidCounter(0);

Client::Client(FTPServer* server, TCP::Socket& socket) : _uid(_uidCounter++), _socket(std::move(socket)), _server(server) {

}

void Client::run() {
	std::cout << "New client connected width id=" << _uid << " [" << _socket.getAddress() << "]" << std::endl;

	Packet packet;

	MSG::ConnectionInitialization(_server->getConfiguration().getMOTD()).generatePacket(packet);

	std::cout << packet << std::endl;

	_socket.send(packet);

	while(_socket.isOpen()) {
		Packet packet;

		_socket.receive(packet);

		std::cout << "Received buffer (" << packet.getSize() << ")" << std::endl;
		std::cout <<  packet << std::endl;
		//FTPMessage* message = FTPMessageFactoy::eval(packet);
	}

	std::cout << "[Client " << _uid << "] Disconnected " << std::endl;
}
