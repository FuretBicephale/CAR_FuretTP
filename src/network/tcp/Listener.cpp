#include "network/tcp/Listener.h"

using namespace FuretTP;
using namespace TCP;

Listener::Listener() : _socket(UNINITIALIZED_SOCKET) {

	if((_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		THROW(SystemException, "Unable to create socket", errno);
	}

}

Listener::~Listener() {
	close();
}

void Listener::listen(unsigned int port) {
	struct sockaddr_in address;
	memset(&address, 0, sizeof(struct sockaddr_in));

	address.sin_addr.s_addr = htonl(INADDR_ANY);
	address.sin_family = AF_INET;
	address.sin_port = htons(port);

	if(bind(_socket, (struct sockaddr*)&address, sizeof(struct sockaddr_in)) == -1) {
		THROW(SystemException, "Unable to bind socket", errno);
	}

	if(::listen(_socket, MaxSimultaneousConnection) == -1) {
		THROW(SystemException, "Unable to listen socket", errno);
	}
}

void Listener::accept(Socket& socket) {
	struct sockaddr_in address;
	SocketDescriptor client_socket = UNINITIALIZED_SOCKET;

	memset(&address, 0, sizeof(struct sockaddr_in));

	unsigned int struct_size = sizeof(struct sockaddr_in);

	if((client_socket = ::accept(_socket, (struct sockaddr*)&address, &struct_size)) == -1) {
		THROW (SystemException, "Error on client connection", errno);
	}

	socket._initialize(client_socket);
}

void Listener::close() {
	if(_socket != UNINITIALIZED_SOCKET) {
        ::close(_socket);
		_socket = UNINITIALIZED_SOCKET;
	}
}
