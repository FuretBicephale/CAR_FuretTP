#ifndef _FURETTP_INCORRECTE_FILE_FORMAT_EXCEPTION_H
#define _FURETTP_INCORRECTE_FILE_FORMAT_EXCEPTION_H

#include <string>

#include "exception/Exception.h"

namespace FuretTP {

	class IncorrecteFileFormatException : public Exception {

	public:
		IncorrecteFileFormatException(const std::string& message, unsigned int line, const std::string& file);
	};
}

#endif
