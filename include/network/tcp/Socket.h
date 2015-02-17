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

			/// \class Listener
			/// \ingroup network
			/// \brief TCP socket
			///
			/// Represent a tcp socket for communicate with another socket on local or remote machine . This class use a POSIX Socket.
		class Socket {

			friend class Listener;

		public:
			/// \brief create on non connected socket
			Socket();
			/// \brief move the socket from 'that'
			Socket(Socket&& that);
			/// \brief destroy socket and close it connection if he is connected
			~Socket();

			/// \brief connect the socket to the target 'address' : 'port' socket
			/// \throw SystemException if the connection fail
			void connect(const IP::Address& address, unsigned int port);


			/// \brief wait and receive a packet and transfere it content into 'packet'
			/// \param packet is an packet for store the received message. this one need to be allocated during all the receive execution
			/// \throw SocketClosedException if the socket is closed
			void receive(Packet& packet);

			/// \brief send a packet with the content of 'packet'
			/// \param packet is an packet which contain the message. this one need to be allocated during all the receive execution
			/// \throw SocketClosedException if the socket is closed
			void send(const Packet& packet);


			/// \brief close the socket connection
			void close();

			/// \brief return true if the socket is currently connected with another socket, false otherwhise
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
