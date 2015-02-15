#ifndef _FTP_USER_REQUEST_H
#define _FTP_USER_REQUEST_H

#include "core/message/request/Request.h"

namespace FTP {

	/// \brief Request send when user begin login. this command contains the username as first argument
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
