#ifndef _FURETTP_PASS_REQUEST_H
#define _FURETTP_PASS_REQUEST_H

#include "core/message/request/Request.h"

namespace FuretTP {

	/// \brief Request send for end the login process. this message contains the user's passwors as first argument
	class PassRequest : public Request {

	public:
		PassRequest(const std::string& password);

		const std::string& getPassword() const;

		static constexpr const char* CommandName = "PASS";

	private:
		std::string _password;

	};
}

#endif
