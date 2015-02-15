#ifndef _NETWORK_TCP_SOCKET_H
#define _NETWORK_TCP_SOCKET_H

#include "network/tcp/TCP.h"
#include "network/ip/Address.h"
#include "network/Packet.h"
#include "exception/SystemException.h"
#include "exception/SocketClosedException.h"

#include <unistd.h>

namespace FTP {

	namespace TCP {

		class Socket {

			friend class Listener;

		public:
			Socket();
			Socket(Socket&& that);
			~Socket();

			void connect(const IP::Address& address, unsigned int port);

			void receive(Packet& packet);
			void send(const Packet& packet);

			void close();

			bool isOpen() const;

			const IP::Address& getAddress() const;

		private:
			void _initialize(SocketDescriptor socket);

			//Noncopyable
			Socket(const Socket& model);
			Socket& operator=(const Socket& model);

			SocketDescriptor _socket;
			IP::Address _address;
			unsigned int _port;

		};
	}
}

#endif
