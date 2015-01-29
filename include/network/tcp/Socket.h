#ifndef _NETWORK_TCP_SOCKET_H
#define _NETWORK_TCP_SOCKET_H

#include "network/tcp/TCP.h"

namespace FuretTP {

	namespace tcp {

		class Socket {

			friend class Listener;

		public:
			Socket();
			~Socket();

			void connect(const IPAddress& address, unsigned int port);

			void close();

		private:
			void _initialize(SocketDescriptor socket);

			SocketDescriptor _socket;

		};
	}
}

#endif
