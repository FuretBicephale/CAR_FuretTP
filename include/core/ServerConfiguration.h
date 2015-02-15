#ifndef _FTP_SERVER_CONFIGURATION_H
#define _FTP_SERVER_CONFIGURATION_H

#include "core/User.h"

#include <string>

namespace FTP {

    class ServerConfiguration {

    public:
        ServerConfiguration();
        void loadDefault();

		UserList& getUserList();
		const UserList& getUserList() const;

		const std::string& getUserConfigurationPathname() const;

        unsigned int getBindPort() const;
		const std::string& getMOTD() const;


    private:
		std::string _userConfigurationPathname;
        unsigned int _bindPort;
		std::string _motd;

		UserList _userList;

    };
}

#endif
