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
    /// \brief User connection to the Server.
    ///
    /// Represents the connection between the user and the server.
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
        /// \brief Runs the connection between Client and Server.
        ///
        /// Runs the connection between Client and Server while the socket is open.
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

		/// \brief open new data connection with client
		void openDataConnection();

        /// \brief send packet on data connection
		void sendToDataConnection(const Packet& packet);

        /// \brief receive packet on data connection
		void receiveFromDataConnection(Packet& packet);

		/// \brief Close the current data connection with the client.
		void closeDataConnection();

        /// \brief Set next port and address for active connection
		void setNextActiveConnection(const IP::Address& address, unsigned int port);

        ///
        /// \brief Set client current directory from its root directory.
        ///
        /// This pathname need to be absolute considering client root directory as root
        ///
        void setCurrentDirectory(const std::string& pathname);

        /// \brief Entering in passive mode
		void switchPassiveMode();

		/// \brief close the client connection and terminate client
		void close();


		const User& getUser() const;

		const std::string& getCurrentDirectory() const;

		TCP::Socket& getSocket();
		TCP::Listener& getPassiveDataListener();

    private:

		bool  _isOpen; ///< True if the client is running, false otherwise
        unsigned int _uid; ///< Client id
        TCP::Socket _socket; ///< Client socket
        FTPServer* _server; ///< Server which client is connected to
        std::string _currrentDirectory; ///< Current directory of the server for this client

        bool _inPassiveMode; ///< True if the client is in passive mode, false otherwise

		TCP::Socket _activeDataSocket; ///< current data socket used in active mode

		TCP::Listener _passiveDataListener; ///< the socket listener used in passive mode
		TCP::Socket _passiveDataSocket; ///< current data socket used in passive mode

        IP::Address _nextActiveAddress; ///< Next address for active connection
        unsigned int _nextActivePort; ///< Next port for active connection

        static unsigned int _uidCounter; ///< connection counter

        User _user; ///< User linked to this connection
    };
}

#endif
