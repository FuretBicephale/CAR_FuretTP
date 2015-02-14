#ifndef _FURETTP_RETR_REQUEST_H
#define _FURETTP_RETR_REQUEST_H

#include "core/message/request/Request.h"
#include "network/ip/Address.h"

namespace FuretTP {

	/// Command send by the client for receive a remote file
	class RetrRequest : public Request {

	public:
		RetrRequest(const std::string& filename);

		const std::string& getFilename() const;

		static constexpr const char* CommandName = "RETR";

	private:
		std::string _filename;

	};
}

#endif
