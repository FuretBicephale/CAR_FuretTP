#ifndef _FURETTP_FILE_NOT_FOUND_EXCEPTION_H
#define _FURETTP_FILE_NOT_FOUND_EXCEPTION_H

#include <string>

#include "exception/Exception.h"

namespace FuretTP {

	class FileNotFoundException : public Exception {

	public:
		FileNotFoundException(const std::string& file);
	};
}

#endif
