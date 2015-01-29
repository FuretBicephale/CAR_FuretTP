#ifndef _EXCEPTION_SYSTEM_H
#define _EXCEPTION_SYSTEM_H

#include <stdexcept>
#include <cstring>

namespace FuretTP {

	/// \brief Exception for Operating system error
	class SystemException : public std::runtime_error {

	public:
		SystemException(const std::string& message, int error);
	};

}

#endif
