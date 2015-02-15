#ifndef _EXCEPTION_SYSTEM_H
#define _EXCEPTION_SYSTEM_H

#include "exception/Exception.h"

#include <stdexcept>
#include <cstring>

namespace FTP {

	/// \brief Exception for Operating system error
	class SystemException : public Exception {

	public:
		SystemException(const std::string& message, int error);
	};

}

#endif
