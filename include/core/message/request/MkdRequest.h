#ifndef _FURETTP_MKD_REQUEST_H
#define _FURETTP_MKD_REQUEST_H

#include "core/message/request/Request.h"

namespace FuretTP {

	class MkdRequest : public Request {

	public:
		MkdRequest(const std::string& name);

		const std::string& getName() const;

		static constexpr const char* CommandName = "MKD";

	private:
		std::string _name;

	};
}

#endif
