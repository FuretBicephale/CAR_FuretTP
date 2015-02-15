#ifndef _FTP_QUIT_REQUEST_H
#define _FTP_QUIT_REQUEST_H

#include "core/message/request/Request.h"

namespace FTP {

	class QuitRequest : public Request {

	public:
		QuitRequest();

		static constexpr const char* CommandName = "QUIT";

	private:

	};
}

#endif
