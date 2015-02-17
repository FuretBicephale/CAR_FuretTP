#ifndef _FTP_CDUP_REQUEST_H
#define _FTP_CDUP_REQUEST_H

#include "core/message/request/Request.h"

namespace FTP {

///
/// \class CDUPRequest
/// \ingroup request
/// \brief CDUP request.
///
/// Asks the server to set the current directory to its parent folder.
///
class CDUPRequest : public Request {

public:

    ///
    /// \brief CDUPRequest constructor
    ///
    CDUPRequest();

    static constexpr const char* CommandName = "CDUP";

private:

};
}

#endif
