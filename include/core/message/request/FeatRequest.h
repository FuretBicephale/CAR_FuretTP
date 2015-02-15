#ifndef _FTP_FEAT_REQUEST_H
#define _FTP_FEAT_REQUEST_H

#include "core/message/request/Request.h"

namespace FTP {

	/// \brief Request send for know extra command supported by server (undefined in RFC 959)
	class FeatRequest : public Request {

	public:
		FeatRequest();

		static constexpr const char* CommandName = "FEAT";

	};
}

#endif
