#ifndef _FTP_LIST_REQUEST_H
#define _FTP_LIST_REQUEST_H

#include "core/message/request/Request.h"

namespace FTP {

    class ListRequest : public Request {

    public:
        ListRequest();

        static constexpr const char* CommandName = "LIST";

    private:

    };
}

#endif
