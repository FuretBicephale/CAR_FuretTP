#ifndef _FTP_USER_NOT_FOUND_EXCEPTION_H
#define _FTP_USER_NOT_FOUND_EXCEPTION_H

#include <string>

#include "exception/Exception.h"

namespace FTP {

	class UserNotFoundException : public Exception {

	public:
		UserNotFoundException(const std::string& username);
	};
}

#endif
