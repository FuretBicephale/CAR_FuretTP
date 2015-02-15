#ifndef _FTP_SYST_REQUEST_H
#define _FTP_SYST_REQUEST_H

#include "core/message/request/Request.h"
#include "network/ip/Address.h"

namespace FTP {

	/// Command send by the client for known server system
	class SystRequest : public Request {

	public:
		SystRequest();

		static constexpr const char* CommandName = "SYST";
	};
}

#endif
