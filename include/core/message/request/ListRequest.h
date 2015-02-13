#ifndef _FURETTP_LIST_REQUEST_H
#define _FURETTP_LIST_REQUEST_H

#include "core/message/request/Request.h"

namespace FuretTP {

    class ListRequest : public Request {

    public:
        ListRequest();

        static constexpr const char* CommandName = "LIST";

    private:

    };
}

#endif
