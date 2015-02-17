#ifndef _FTP_REQUEST_H
#define _FTP_REQUEST_H

#include <string>

namespace FTP {

///
/// \class ftp::Request
/// \ingroup request
/// \brief Basic request.
///
/// Represents a packet send by user to the server.
///
class Request {

public:

    ///
    /// \brief Request constructor
    /// \param command Command name of the request
    ///
    Request(const std::string& command);

    const std::string& getCommandName() const;

private:
    std::string _command; ///< The command name of the request
};
}
#endif
