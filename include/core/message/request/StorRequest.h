#ifndef _FTP_STOR_REQUEST_H
#define _FTP_STOR_REQUEST_H

#include "core/message/request/Request.h"
#include "network/ip/Address.h"

namespace FTP {

///
/// \class StorRequest
/// \ingroup request
/// \brief Stor request.
///
/// Command sent by the client to upload a file on the server.
///
class StorRequest : public Request {

public:

    ///
    /// \brief StorRequest constructor
    /// \param filename the file to upload on the server
    ///
    StorRequest(const std::string& filename);

    const std::string& getFilename() const;

    static constexpr const char* CommandName = "STOR";

private:
    std::string _filename; ///< the file the user wants to upload on the server

};
}

#endif
