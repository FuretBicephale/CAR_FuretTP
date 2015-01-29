#ifndef _NETWORK_TCP_LISTENER_H
#define _NETWORK_TCP_LISTENER_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#include <cerrno>
#include <cstring>

#include "network/tcp/TCP.h"
#include "network/tcp/Socket.h"

#include "exception/SystemException.h"

namespace FuretTP {

	namespace tcp {

		///
		/// \brief TCP client listenner. Thi class use POSIX Socket.
		///
		class Listener {

		public:
			const int MaxSimultaneousConnection = 8;

			Listener();

			/// \brief bind a port for listen client connections
			void listen(unsigned int port);

			/// \brief wait a client. When connection is etablished, this function return the client Socket
			void accept(Socket& socket);

		private:
			SocketDescriptor _socket;


		};

	}
}

#endif
