#ifndef _FURETTP_USER_REQUEST_H
#define _FURETTP_USER_REQUEST_H

#include "core/message/request/Request.h"

namespace FuretTP {

	class UserRequest : public Request {

	public:
		UserRequest(const std::string& username);

		const std::string& getUsername() const;

		static constexpr const char* CommandName = "USER";

	private:
		std::string _username;

	};
}

#endif
