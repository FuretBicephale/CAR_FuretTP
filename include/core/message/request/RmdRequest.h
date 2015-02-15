#ifndef _FURETTP_RMD_REQUEST_H
#define _FURETTP_RMD_REQUEST_H

#include "core/message/request/Request.h"

namespace FuretTP {

	class RmdRequest : public Request {

	public:
		RmdRequest(const std::string& name);

		const std::string& getName() const;

		static constexpr const char* CommandName = "Rmd";

	private:
		std::string _name;

	};
}

#endif
