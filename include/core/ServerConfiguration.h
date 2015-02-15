#ifndef _FTP_SERVER_CONFIGURATION_H
#define _FTP_SERVER_CONFIGURATION_H

#include "core/User.h"

#include <string>

namespace FTP {

    ///
    /// \class ftp::ServerConfiguration
    /// \ingroup core
    /// \brief Current configuration of the server
    ///
    /// Contains user's account informations, communication port and message of the day
    ///
    class ServerConfiguration {

    public:

        ///
        /// \brief ServerConfiguration constructor
        ///
        ServerConfiguration();

        ///
        /// \brief loadDefault
        ///
        void loadDefault();

		UserList& getUserList();
        const UserList& getUserList() const;
		const std::string& getUserConfigurationPathname() const;

        unsigned int getBindPort() const;
		const std::string& getMOTD() const;

		void setBindPort(unsigned int port);


    private:

        std::string _userConfigurationPathname; ///< The name of the file which contains user's account informations
        unsigned int _bindPort; ///< Communication port
        std::string _motd; ///< Message displayed when an user is connected to the server

        UserList _userList; ///< Contains every connected user

    };
}

#endif
