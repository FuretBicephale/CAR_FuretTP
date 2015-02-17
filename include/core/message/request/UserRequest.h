#ifndef _FTP_USER_REQUEST_H
#define _FTP_USER_REQUEST_H

#include "core/message/request/Request.h"

namespace FTP {

///
/// \class ftp::UserRequest
/// \ingroup request
/// \brief User request.
///
/// Request sent when user begins login. This command contains the username as first argument.
///
class UserRequest : public Request {

public:

    ///
    /// \brief UserRequest constructor
    /// \param username User's username
    ///
    UserRequest(const std::string& username);

    const std::string& getUsername() const;

    static constexpr const char* CommandName = "USER";

private:
    std::string _username; ///< User's username

};
}

#endif
