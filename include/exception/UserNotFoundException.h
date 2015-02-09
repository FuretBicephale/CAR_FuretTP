#ifndef _FURETTP_USER_NOT_FOUND_EXCEPTION_H
#define _FURETTP_USER_NOT_FOUND_EXCEPTION_H

#include <string>

#include "exception/Exception.h"

namespace FuretTP {

	class UserNotFoundException : public Exception {

	public:
		UserNotFoundException(const std::string& username);
	};
}

#endif
