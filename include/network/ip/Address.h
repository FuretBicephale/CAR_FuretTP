#ifndef _NETWORK_IP_ADDRESS_H
#define _NETWORK_IP_ADDRESS_H

#include <iostream>

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#include "exception/AddressNotFoundException.h"

namespace FuretTP {

	namespace IP {

        class Address {

        public:
			Address();
            Address(const std::string& hostname);
			Address(const Address& model);

			Address& operator=(const Address& model);

			const char* getRawAddress() const;
			int getAddressType() const;

			friend std::ostream& operator<<(std::ostream& stream, const Address& address);

			void _initialize();

        private:
            struct hostent* _host;

        };

		std::ostream& operator<<(std::ostream& stream, const Address& address);

    }
}

#endif
