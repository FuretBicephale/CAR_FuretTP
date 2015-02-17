#ifndef _FTP_NO_ACTIVE_CONNECTION_EXCEPTION_H
#define _FTP_NO_ACTIVE_CONNECTION_EXCEPTION_H

#include <string>

#include "exception/Exception.h"

namespace FTP {

///
/// \class NoActiveConnectionException
/// \ingroup exception
/// \brief Exception launched when there isn't Active connection when it's needed
///
class NoActiveConnectionException : public Exception {

public:

    ///
    /// \brief NoActiveConnectionException constructor
    /// \param message A message to print
    ///
    NoActiveConnectionException(const std::string& message = "");
};
}

#endif
