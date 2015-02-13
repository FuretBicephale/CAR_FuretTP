#ifndef _EXCEPTION_UNRECOGNIZED_MESSAGE_H
#define _EXCEPTION_UNRECOGNIZED_MESSAGE_H

#include "exception/Exception.h"

namespace FuretTP {

	class UnrecognizedMessageException 	: public Exception {

	public:
		UnrecognizedMessageException(const std::string& command, const std::string& reason = "");
	};
}

#endif
