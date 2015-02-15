#ifndef _FURETTP_CLIENT_H
#define _FURETTP_CLIENT_H

#include "core/User.h"
#include "network/tcp/Socket.h"
#include "network/tcp/Listener.h"
#include "exception/SystemException.h"
#include "exception/NoActiveConnectionException.h"

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
		void openDataConnection();

		void sendToDataConnection(const Packet& packet);

		void receiveFromDataConnection(Packet& packet);

		void closeDataConnection();

		void setNextActiveConnection(const IP::Address& address, unsigned int port);

		/// \brief set client current directory from it root directory. This pathname need to be absolute from root user (begin with a "/")
		void setCurrentDirectory(const std::string& pathname);

		/// \brief entering in passive mode
		void switchPassiveMode();

		/// \brief close the client connection and terminate client
		void close();


		const User& getUser() const;

		const std::string& getCurrentDirectory() const;

		TCP::Socket& getSocket();
		TCP::Listener& getPassiveDataListener();

    private:
        unsigned int _uid;
        TCP::Socket _socket;
        FTPServer* _server;
		std::string _currrentDirectory;

		bool _inPassiveMode;
		bool  _isOpen;
		TCP::Socket _activeDataSocket;

		TCP::Listener _passiveDataListener;
		TCP::Socket _passiveDataSocket;

		IP::Address _nextActiveAddress;
		unsigned int _nextActivePort;

        static unsigned int _uidCounter;

		User _user;
    };
}

#endif
