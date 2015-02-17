#ifndef _FTP_LIST_REQUEST_H
#define _FTP_LIST_REQUEST_H

#include "core/message/request/Request.h"

namespace FTP {

///
/// \class ListRequest
/// \ingroup request
/// \brief List request.
///
/// Display every files present in the current directory.
///
class ListRequest : public Request {

public:

    ///
    /// \brief ListRequest constructor
    ///
    ListRequest();

    static constexpr const char* CommandName = "LIST";

private:

};
}

#endif
