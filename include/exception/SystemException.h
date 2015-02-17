#ifndef _EXCEPTION_SYSTEM_H
#define _EXCEPTION_SYSTEM_H

#include "exception/Exception.h"

#include <stdexcept>
#include <cstring>

namespace FTP {

///
/// \class SystemException
/// \ingroup exception
/// \brief Exception for Operating system error
///
class SystemException : public Exception {

public:

    ///
    /// \brief SystemException constructor
    /// \param message A message to print
    /// \param error The system error's number
    ///
    SystemException(const std::string& message, int error);
};

}

#endif
