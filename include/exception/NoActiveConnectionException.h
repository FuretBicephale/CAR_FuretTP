#ifndef _FTP_NO_ACTIVE_CONNECTION_EXCEPTION_H
#define _FTP_NO_ACTIVE_CONNECTION_EXCEPTION_H

#include <string>

#include "exception/Exception.h"

namespace FTP {

	class NoActiveConnectionException : public Exception {

	public:
		NoActiveConnectionException(const std::string& message = "");
	};
}

#endif
