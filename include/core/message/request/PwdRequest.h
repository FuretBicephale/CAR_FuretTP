#ifndef _FTP_PWD_REQUEST_H
#define _FTP_PWD_REQUEST_H

#include "core/message/request/Request.h"

namespace FTP {

///
/// \class PwdRequest
/// \ingroup request
/// \brief Pwd request.
///
/// Asks the server to send the current directory pathname.
///
class PwdRequest : public Request {

public:

    ///
    /// \brief PwdRequest constructor
    ///
    PwdRequest();

    static constexpr const char* CommandName = "PWD";

};
}

#endif
