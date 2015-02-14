#ifndef _NETWORK_TCP_LISTENER_H
#define _NETWORK_TCP_LISTENER_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#include <cerrno>
#include <cstring>

#include "network/tcp/TCP.h"
#include "network/tcp/Socket.h"

#include "exception/SystemException.h"

namespace FuretTP {

	namespace TCP {

		///
		/// \brief TCP client listenner. Thi class use POSIX Socket.
		///
		class Listener {

		public:
			const int MaxSimultaneousConnection = 8;

			Listener();
			~Listener();

			/// \brief bind a port for listen client connections
			void listen(unsigned int port);


			/// \brief bind a free port for listen client connections and return port number
			unsigned int listen();

			/// \brief wait a client. When connection is etablished, this function return the client Socket
			void accept(Socket& socket);

			/// \brief close the socket
			void close();

			unsigned int getPort() const;

		private:
			SocketDescriptor _socket;

			IP::Address _address;
			unsigned int _port;


		};

	}
}

#endif
