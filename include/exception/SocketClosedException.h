#ifndef _FURETTP_SOCKET_CLOSED_EXCEPTION_H
#define _FURETTP_SOCKET_CLOSED_EXCEPTION_H

#include <string>

#include "exception/Exception.h"

namespace FuretTP {

	class SocketClosedException : public Exception {

	public:
		SocketClosedException(const std::string& message);
	};
}

#endif
