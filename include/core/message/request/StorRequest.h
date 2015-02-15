#ifndef _FURETTP_STOR_REQUEST_H
#define _FURETTP_STOR_REQUEST_H

#include "core/message/request/Request.h"
#include "network/ip/Address.h"

namespace FuretTP {

	/// Command send by the client for upload a file
	class StorRequest : public Request {

	public:
		StorRequest(const std::string& filename);

		const std::string& getFilename() const;

		static constexpr const char* CommandName = "STOR";

	private:
		std::string _filename;

	};
}

#endif
