#ifndef _FTP_FILE_NOT_FOUND_EXCEPTION_H
#define _FTP_FILE_NOT_FOUND_EXCEPTION_H

#include <string>

#include "exception/Exception.h"

namespace FTP {

///
/// \class FileNotFoundException
/// \ingroup exception
/// \brief Exception launched when a file is needed but not found
///
class FileNotFoundException : public Exception {

public:

    ///
    /// \brief FileNotFoundException constructor
    /// \param file The file which is not found
    ///
    FileNotFoundException(const std::string& file);
};
}

#endif
