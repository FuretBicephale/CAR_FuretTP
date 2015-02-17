#ifndef _FTP_CWD_REQUEST_H
#define _FTP_CWD_REQUEST_H

#include "core/message/request/Request.h"

namespace FTP {

///
/// \class CWDPRequest
/// \ingroup request
/// \brief CWD request.
///
/// Asks the server to change the current directory.
/// Accept absolute and relative path
///
class CWDRequest : public Request {

public:

    ///
    /// \brief CWDRequest constructor
    /// \param directory New current directory
    ///
    /// The directory needs to exist
    ///
    CWDRequest(const std::string& directory);

    const std::string& getDirectory() const;

    static constexpr const char* CommandName = "CWD";

private:
    std::string _directory; ///< The new current directory

};
}

#endif
