#ifndef _FURETTP_PORT_REQUEST_H
#define _FURETTP_PORT_REQUEST_H

#include "core/message/request/Request.h"
#include "network/ip/Address.h"

namespace FuretTP {

	/// Command send by the client when he want open a new connection.
	class PortRequest : public Request {

	public:
		PortRequest(const IP::Address& address, unsigned int port);

		const IP::Address& getAddress() const;
		unsigned int getPort() const;

		static constexpr const char* CommandName = "PORT";

	private:
		IP::Address _address;
		unsigned int _port;

	};
}

#endif
