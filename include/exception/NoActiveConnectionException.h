#ifndef _FURETTP_NO_ACTIVE_CONNECTION_EXCEPTION_H
#define _FURETTP_NO_ACTIVE_CONNECTION_EXCEPTION_H

#include <string>

#include "exception/Exception.h"

namespace FuretTP {

	class NoActiveConnectionException : public Exception {

	public:
		NoActiveConnectionException(const std::string& message = "");
	};
}

#endif
