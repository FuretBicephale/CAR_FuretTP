#ifndef _FURETTP_CLIENT_H
#define _FURETTP_CLIENT_H

#include "network/tcp/Socket.h"
#include "exception/SystemException.h"

#include "message/ConnectionInitialization.h"

namespace FuretTP {

	class FTPServer;

	class Client {

	public:
		Client(FTPServer* server, TCP::Socket& socket);

		void run();

	private:
		unsigned int _uid;
		TCP::Socket _socket;
		FTPServer* _server;

		static unsigned int _uidCounter;
	};
}

#endif
