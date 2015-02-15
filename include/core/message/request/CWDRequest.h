#ifndef _FTP_CWD_REQUEST_H
#define _FTP_CWD_REQUEST_H

#include "core/message/request/Request.h"

namespace FTP {

    class CWDRequest : public Request {

    public:
        CWDRequest(const std::string& directory);

        const std::string& getDirectory() const;

        static constexpr const char* CommandName = "CWD";

    private:
        std::string _directory;

    };
}

#endif
