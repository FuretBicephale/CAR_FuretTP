#include "core/Client.h"
#include "core/FTPServer.h"

using namespace FuretTP;

unsigned int Client::_uidCounter(0);

Client::Client(FTPServer* server, TCP::Socket& socket) : _uid(_uidCounter++), _socket(std::move(socket)), _server(server) {

}

void Client::run() {
	std::cout << "New client connected width id=" << _uid << " [" << _socket.getAddress() << "]" << std::endl;

	_socket.send(MSG::ConnectionInitialization(_server.getConfiguration().getMOTD()).getPacket());

	while(_socket.isOpen()) {

#define RECEIVE_BUFFER_SIZE 4096
		char buffer[RECEIVE_BUFFER_SIZE];
		int size;

		size = _socket.receive(buffer, RECEIVE_BUFFER_SIZE);

		std::cout << "Received buffer (" << size << ")" << std::endl;
		std::cout <<  buffer << std::endl;
	}

	std::cout << "[Client " << _uid << "] Disconnected " << std::endl;
}
