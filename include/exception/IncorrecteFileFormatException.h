#ifndef _FTP_INCORRECTE_FILE_FORMAT_EXCEPTION_H
#define _FTP_INCORRECTE_FILE_FORMAT_EXCEPTION_H

#include <string>

#include "exception/Exception.h"

namespace FTP {

    ///
    /// \class ftp::IncorrecteFileFormatException
    /// \ingroup exception
    /// \brief Exception launched when a file format is incorrect
    ///
	class IncorrecteFileFormatException : public Exception {

	public:

        ///
        /// \brief IncorrecteFileFormatException constructor
        /// \param message A message to print
        /// \param line The line of the error in the file
        /// \param file The name of the incorrect file
        ///
		IncorrecteFileFormatException(const std::string& message, unsigned int line, const std::string& file);
	};
}

#endif
