#ifndef _FTP_CWD_REQUEST_H
#define _FTP_CWD_REQUEST_H

#include "core/message/request/Request.h"

namespace FTP {

    ///
    /// \class ftp::CWDPRequest
    /// \ingroup request
    /// \brief CWD request.
    ///
    /// Asks the server to change the current directory.
    /// Only accept absolute path.
    ///
    class CWDRequest : public Request {

    public:

        ///
        /// \brief CWDRequest constructor
        /// \param directory New current directory
        ///
        /// The directory must be an absolute path and need to exists
        ///
        CWDRequest(const std::string& directory);

        const std::string& getDirectory() const;

        static constexpr const char* CommandName = "CWD";

    private:
        std::string _directory; ///< The new current directory

    };
}

#endif
