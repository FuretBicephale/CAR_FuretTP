#ifndef _FURETTP_CLIENT_H
#define _FURETTP_CLIENT_H

#include "network/tcp/Socket.h"
#include "exception/SystemException.h"

#include "message/answer/ConnectionInitializationAnswer.h"
#include "core/FTPRequestHandler.h"
#include "core/message/request/RequestFactory.h"

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
