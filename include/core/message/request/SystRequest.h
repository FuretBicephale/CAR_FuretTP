#ifndef _FURETTP_SYST_REQUEST_H
#define _FURETTP_SYST_REQUEST_H

#include "core/message/request/Request.h"
#include "network/ip/Address.h"

namespace FuretTP {

	/// Command send by the client for known server system
	class SystRequest : public Request {

	public:
		SystRequest();

		static constexpr const char* CommandName = "SYST";
	};
}

#endif
