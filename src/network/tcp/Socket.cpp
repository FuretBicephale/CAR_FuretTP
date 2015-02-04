#include "network/tcp/Socket.h"

using namespace FuretTP;
using namespace TCP;

Socket::Socket() : _socket(UNINITIALIZED_SOCKET), _address() {

}

Socket::Socket(Socket&& that) : _socket(that._socket), _address(that._address) {
	that._socket = UNINITIALIZED_SOCKET;


}

Socket::~Socket() {
	close();
}

void Socket::_initialize(SocketDescriptor socket) {
	_socket = socket;

	struct sockaddr_in address;
	socklen_t length = sizeof(struct sockaddr_in);
	getsockname(socket, (struct sockaddr*)&address, &length);

	_address._initialize();
}

void Socket::connect(const IP::Address& address, unsigned int port) {
	_address = address;

}

unsigned int Socket::receive(void* buffer, unsigned int bufferSize) {
	int size;

	std::cout << "w8 data..." << std::endl;
	if((size = recv(_socket, buffer, bufferSize, 0)) == -1) {
		THROW(SystemException, "Error during recv", errno);
	}
	return size;
}

void Socket::close() {
	if(_socket != UNINITIALIZED_SOCKET) {
        ::close(_socket);
		_socket = UNINITIALIZED_SOCKET;
	}
}

bool Socket::isOpen() const {
	return _socket != UNINITIALIZED_SOCKET;
}

const IP::Address& Socket::getAddress() const {
	return _address;
}
