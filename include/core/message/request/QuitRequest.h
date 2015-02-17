#ifndef _FTP_QUIT_REQUEST_H
#define _FTP_QUIT_REQUEST_H

#include "core/message/request/Request.h"

namespace FTP {

///
/// \class ftp::QuitRequest
/// \ingroup request
/// \brief Quit request.
///
/// Command sent to the server when an user quit it.
///
class QuitRequest : public Request {

public:

    ///
    /// \brief QuitRequest constructor
    ///
    QuitRequest();

    static constexpr const char* CommandName = "QUIT";

private:

};
}

#endif
