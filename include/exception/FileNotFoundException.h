#ifndef _FTP_FILE_NOT_FOUND_EXCEPTION_H
#define _FTP_FILE_NOT_FOUND_EXCEPTION_H

#include <string>

#include "exception/Exception.h"

namespace FTP {

	class FileNotFoundException : public Exception {

	public:
		FileNotFoundException(const std::string& file);
	};
}

#endif
