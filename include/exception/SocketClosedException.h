#ifndef _FTP_SOCKET_CLOSED_EXCEPTION_H
#define _FTP_SOCKET_CLOSED_EXCEPTION_H

#include <string>

#include "exception/Exception.h"

namespace FTP {

	class SocketClosedException : public Exception {

	public:
		SocketClosedException(const std::string& message);
	};
}

#endif
