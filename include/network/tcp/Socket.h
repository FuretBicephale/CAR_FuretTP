#ifndef _NETWORK_TCP_SOCKET_H
#define _NETWORK_TCP_SOCKET_H

#include "network/tcp/TCP.h"

namespace FuretTP {

	namespace tcp {

		class Socket {

			friend class Listener;

		private:
			void _initialize(SocketDescriptor socket);

		};
	}
}

#endif
