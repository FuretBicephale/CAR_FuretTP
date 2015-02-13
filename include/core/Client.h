#ifndef _FURETTP_CLIENT_H
#define _FURETTP_CLIENT_H

#include "core/User.h"
#include "network/tcp/Socket.h"
#include "exception/SystemException.h"

#include "message/answer/ConnectionInitializationAnswer.h"
#include "core/RequestHandler.h"
#include "core/message/request/RequestFactory.h"

namespace FuretTP {

    class FTPServer;

    class Client {

    public:
        Client(FTPServer* server, TCP::Socket& socket);

        void run();

		/// \brief set username of the client
		bool setUsername(const std::string& username);

		/// \brief try to loggin with the previous username.
		bool login(const std::string& password);

		/// \brief reset loggin information
		void resetLogin();

		/// \brief open new connection with client
		bool openConnection(const IP::Address& address, unsigned int port);

		/// \brief set client current directory from it root directory
		void setCurrentDirectory(const std::string& pathname);

		const User& getUser() const;

        const std::string& getCurrentDir() const;

		TCP::Socket& getSocket();

    private:
        unsigned int _uid;
        TCP::Socket _socket;
        FTPServer* _server;
        std::string _currDir;

		TCP::Socket _activeSocket;

        static unsigned int _uidCounter;

		User _user;
    };
}

#endif
