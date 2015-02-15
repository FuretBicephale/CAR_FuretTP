#ifndef _FURETTP_QUIT_REQUEST_H
#define _FURETTP_QUIT_REQUEST_H

#include "core/message/request/Request.h"

namespace FuretTP {

	class QuitRequest : public Request {

	public:
		QuitRequest();

		static constexpr const char* CommandName = "QUIT";

	private:

	};
}

#endif
