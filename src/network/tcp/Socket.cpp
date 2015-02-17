#include "network/tcp/Socket.h"

using namespace FTP;
using namespace TCP;

Socket::Socket() : _socket(UNINITIALIZED_SOCKET), _address(), _port(0) {

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
}

void Socket::connect(const IP::Address& address, unsigned int port) {
	close();

	_socket = ::socket(AF_INET, SOCK_STREAM, 0);
	if(_socket == -1) {
		_socket = UNINITIALIZED_SOCKET;
		THROW(SystemException, "Unable to create socket", errno);
	}

	struct sockaddr_in addr_in;
	memset(&addr_in, 0, sizeof(struct sockaddr_in));

	addr_in.sin_addr = *(struct in_addr*)address.getRawAddress();
	addr_in.sin_port = htons(port);
	addr_in.sin_family = address.getAddressType();


	if(::connect(_socket,(struct sockaddr*) &addr_in, sizeof(struct sockaddr_in)) == -1) {
		_socket = UNINITIALIZED_SOCKET;
		THROW(SystemException, "Unable to connect socket", errno);
	}

	_address = address;
	_port = port;
}

void Socket::receive(Packet& packet) {
	if(_socket == UNINITIALIZED_SOCKET)
		THROW(SocketClosedException, "Trying receive packet on closed socket");

#define RECEIVE_BUFFER_SIZE 4096
	char buffer[RECEIVE_BUFFER_SIZE];
	int size;

	do {
		if((size = recv(_socket, buffer, RECEIVE_BUFFER_SIZE, 0)) == -1) {
			THROW(SystemException, "Error during recv", errno);
		}
	}
	while(size == 0);

	packet.rawWrite(buffer, size);
}

void Socket::send(const Packet& packet) {
	if(_socket == UNINITIALIZED_SOCKET)
		THROW(SocketClosedException, "Trying receive packet on closed socket");

	if(::send(_socket, packet.getBuffer(), packet.getSize(), 0) == -1) {
		THROW(SystemException, "Error during send", errno);
	}
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
