#ifndef _NETWORK_IP_ADDRESS_H
#define _NETWORK_IP_ADDRESS_H

#include <string>

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#include "exception/AddressNotFoundException.h"

namespace FuretTP {

    namespace ip {

        class Address {

        public:
            Address(const std::string& hostname);

        private:
            struct hostent* _host;

        };
    }
}

#endif
