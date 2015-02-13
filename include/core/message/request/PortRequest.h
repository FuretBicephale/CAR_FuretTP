#ifndef _FURETTP_PORT_REQUEST_H
#define _FURETTP_PORT_REQUEST_H

#include "core/message/request/Request.h"

namespace FuretTP {

	/// Command send by the client when he want open a new connection.
	class PortRequest : public Request {

	public:
		PortRequest(const std::string& address);

		const std::string& getAddress() const;
		unsigned int getPort() const;

		static constexpr const char* CommandName = "PORT";

	private:
		void _parseArgument(const std::string& address);

		std::string _address;
		unsigned int _port;

	};
}

#endif
