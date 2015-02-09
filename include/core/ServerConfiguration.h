#ifndef _FTP_SERVER_CONFIGURATION_H
#define _FTP_SERVER_CONFIGURATION_H

#include <string>

namespace FuretTP {

    class ServerConfiguration {

    public:
        ServerConfiguration();
        void loadDefault();

		const std::string& getUserConfigurationPathname() const;

        unsigned int getBindPort() const;
		const std::string& getMOTD() const;


    private:
		std::string _userConfigurationPathname;
        unsigned int _bindPort;
		std::string _motd;

    };
}

#endif
