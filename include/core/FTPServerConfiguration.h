#ifndef _FTP_SERVER_CONFIGURATION_H
#define _FTP_SERVER_CONFIGURATION_H

namespace FuretTP {

    class FTPServerConfiguration {

    public:
        FTPServerConfiguration();
        void loadDefault();

        unsigned int getBindPort() const;

    private:
        unsigned int _bindPort;
    };
}

#endif
