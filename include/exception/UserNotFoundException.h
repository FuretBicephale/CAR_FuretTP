#ifndef _FTP_USER_NOT_FOUND_EXCEPTION_H
#define _FTP_USER_NOT_FOUND_EXCEPTION_H

#include <string>

#include "exception/Exception.h"

namespace FTP {

///
/// \class UserNotFoundException
/// \ingroup exception
/// \brief Exception launched when a user isn't found
///
class UserNotFoundException : public Exception {

public:

    ///
    /// \brief UserNotFoundException constructor
    /// \param username The name of the user
    ///
    UserNotFoundException(const std::string& username);
};
}

#endif
