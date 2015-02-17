#ifndef _FTP_PASV_REQUEST_H
#define _FTP_PASV_REQUEST_H

#include "core/message/request/Request.h"

namespace FTP {

///
/// \class PasvRequest
/// \ingroup request
/// \brief Pasv request.
///
/// Request sent in order to enter in passive mode.
///
class PasvRequest : public Request {

public:

    ///
    /// \brief PasvRequest constructor
    ///
    PasvRequest();

    static constexpr const char* CommandName = "PASV";

};
}

#endif
