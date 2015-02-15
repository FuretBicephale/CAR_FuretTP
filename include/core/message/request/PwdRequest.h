#ifndef _FTP_PWD_REQUEST_H
#define _FTP_PWD_REQUEST_H

#include "core/message/request/Request.h"

namespace FTP {

	/// \brief Request send for know extra command supported by server (undefined in RFC 959)
	class PwdRequest : public Request {

	public:
		PwdRequest();

		static constexpr const char* CommandName = "PWD";

	};
}

#endif
