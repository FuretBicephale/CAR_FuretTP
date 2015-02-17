#ifndef _NETWORK_IP_ADDRESS_H
#define _NETWORK_IP_ADDRESS_H

#include <iostream>

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

#include "exception/AddressNotFoundException.h"

namespace FTP {

	namespace IP {

		///
		/// \class Address
		/// \ingroup network
		/// \brief Represents an IP address
		///
		/// Represents an IP address by encapuling the Unix representation
		///
        class Address {

        public:
			/// \brief Constructor
			/// create an empty address
			Address();

			/// \brief create the address with the 'hostname' parameter
			/// \throw AddressNotFoundException if the address is invalide or can not be found
            Address(const std::string& hostname);

			/// \brief copy the address from 'model'
			Address(const Address& model);

			/// \brief assign an address from 'model'
			Address& operator=(const Address& model);

			const char* getRawAddress() const;
			int getAddressType() const;

			friend std::ostream& operator<<(std::ostream& stream, const Address& address);


        private:
            struct hostent* _host;

        };

		/// \brief display the address on the stream
		std::ostream& operator<<(std::ostream& stream, const Address& address);

    }
}

#endif
