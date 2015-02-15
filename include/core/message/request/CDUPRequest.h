#ifndef _FURETTP_CDUP_REQUEST_H
#define _FURETTP_CDUP_REQUEST_H

#include "core/message/request/Request.h"

namespace FuretTP {

    class CDUPRequest : public Request {

    public:
        CDUPRequest();

        static constexpr const char* CommandName = "CDUP";

    private:

    };
}

#endif
