#ifndef _FURETTP_PASV_REQUEST_H
#define _FURETTP_PASV_REQUEST_H

#include "core/message/request/Request.h"

namespace FuretTP {

	/// \brief Request send entering in passive mode
	class PasvRequest : public Request {

	public:
		PasvRequest();

		static constexpr const char* CommandName = "PASV";

	};
}

#endif
