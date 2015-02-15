#ifndef _FTP_CLIENT_H
#define _FTP_CLIENT_H

#include "core/User.h"
#include "network/tcp/Socket.h"
#include "network/tcp/Listener.h"
#include "exception/SystemException.h"
#include "exception/NoActiveConnectionException.h"

#include "core/RequestHandler.h"
#include "core/message/request/RequestFactory.h"

namespace FTP {

    class FTPServer;

    ///
    /// \class ftp::Client
    /// \ingroup core
    /// \brief User connexion to the Server.
    ///
    /// Represents the connexion between the user and the server.
    /// It's used to receive and send the different packet between the both entities.
    ///
    class Client {

    public:

        ///
        /// \brief Client constructor.
        /// \param server Server which the user is connecting.
        /// \param socket User's socket.
        ///
        Client(FTPServer* server, TCP::Socket& socket);

        ///
        /// \brief Runs the connexion between Client and Server.
        ///
        /// Runs the connexion between Client and Server while the socket is open.
        /// Receives each packet from the user and interprets them.
        /// If the received packet is a known request, it calls the RequestHandler, else it sends an unimplemented command packet.
        ///
        void run();

        /// \brief set username of the client.
        bool setUsername(const std::string& username);

        ///
		/// \brief try to loggin with the previous username.
        /// \param password Password send by the user.
        /// \return True if the client is logged in, false otherwise.
        ///
        /// Try to login the client, if an username had been setted.
        /// If the password is corresponding with the username, the user is logged in and the method return true.
        /// If not, the method return false.
        ///
        bool login(const std::string& password);

        /// \brief Reset login informations.
        void resetLogin();

        /// \brief Open a new connection with the client.
		void openActiveConnection();

        /// \brief Close the current connection with the client.
		void closeActiveConnection();

        /// \brief
		void setNextActiveConnection(const IP::Address& address, unsigned int port);

        ///
        /// \brief Set client current directory from its root directory.
        ///
        /// This pathname need to be absolute considering client root directory as root
        ///
        void setCurrentDirectory(const std::string& pathname);

        /// \brief Entering in passive mode
		void switchPassiveMode();

		const User& getUser() const;

		const std::string& getCurrentDirectory() const;

		TCP::Socket& getSocket();
		TCP::Socket& getActiveDataSocket();
		TCP::Listener& getPassiveDataSocket();

    private:

        unsigned int _uid; ///< Client id
        TCP::Socket _socket; ///< Client socket
        FTPServer* _server; ///< Server which client is connected to
        std::string _currrentDirectory; ///< Current directory of the server for this client

        bool _inPassiveMode; ///< True if the client is in passive mode, false otherwise

        TCP::Socket _activeDataSocket; ///<
        TCP::Listener _passiveDataSocket; ///<

        IP::Address _nextActiveAddress; ///<
        unsigned int _nextActivePort; ///<

        static unsigned int _uidCounter; ///<

        User _user; ///< User linked to this connexion
    };
}

#endif
