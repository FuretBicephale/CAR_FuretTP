#ifndef _FTP_PASS_REQUEST_H
#define _FTP_PASS_REQUEST_H

#include "core/message/request/Request.h"

namespace FTP {

///
/// \class PassRequest
/// \ingroup request
/// \brief Pass request.
///
/// Request sent to end the login process. Contains the user's password as first argument.
///
class PassRequest : public Request {

public:

    ///
    /// \brief PassRequest constructor
    /// \param password User's password
    ///
    PassRequest(const std::string& password);

    const std::string& getPassword() const;

    static constexpr const char* CommandName = "PASS";

private:
    std::string _password; ///< User's password

};
}

#endif
