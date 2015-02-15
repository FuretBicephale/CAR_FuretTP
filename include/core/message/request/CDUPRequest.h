#ifndef _FTP_CDUP_REQUEST_H
#define _FTP_CDUP_REQUEST_H

#include "core/message/request/Request.h"

namespace FTP {

    class CDUPRequest : public Request {

    public:
        CDUPRequest();

        static constexpr const char* CommandName = "CDUP";

    private:

    };
}

#endif
