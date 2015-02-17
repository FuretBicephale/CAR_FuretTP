#ifndef _FTP_PORT_REQUEST_H
#define _FTP_PORT_REQUEST_H

#include "core/message/request/Request.h"
#include "network/ip/Address.h"

namespace FTP {

///
/// \class ftp::PortRequest
/// \ingroup request
/// \brief Port request.
///
/// Command sent by the client when he wants to open a new connection.
///
class PortRequest : public Request {

public:

    ///
    /// \brief PortRequest constructor
    /// \param address the new address to connect to
    /// \param port the new port to connect to
    ///
    PortRequest(const IP::Address& address, unsigned int port);

    const IP::Address& getAddress() const;
    unsigned int getPort() const;

    static constexpr const char* CommandName = "PORT";

private:
    IP::Address _address; ///< the new address to connect to
    unsigned int _port; ///< the new port to connect to

};
}

#endif
