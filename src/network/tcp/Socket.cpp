#include "network/tcp/Socket.h"

using namespace FuretTP;
using namespace tcp;

Socket::Socket() : _socket(UNINITIALIZED_SOCKET) {

}

Socket::~Socket() {
	close();
}

void Socket::_initialize(SocketDescriptor socket) {
	_socket = socket;
}

void Socket::connect(const ip::Address& address, unsigned int port) {

}

void Socket::close() {
	if(_socket != UNINITIALIZED_SOCKET) {
		close(_socket);
		_socket = UNINITIALIZED_SOCKET;
	}
}
