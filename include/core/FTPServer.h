#ifndef _FTP_SERVER_H
#define _FTP_SERVER_H

#include "core/ServerConfiguration.h"

#include "network/tcp/Listener.h"
#include "system/Thread.h"
#include "core/Client.h"

#include <iostream>

namespace FTP {

///
/// \class ftp::FTPServer
/// \ingroup core
/// \brief Represents the FTP Server.
///
/// Represents the FTP Server.
/// It receives user connections then create a Client instance for each of them.
///
class FTPServer {

public:

    ///
    /// \brief FTPServer constructor.
    /// \param configuration Configuration of the server.
    ///
    FTPServer(const ServerConfiguration& configuration);

    ///
    /// \brief run the server while the application is launched
    ///
    /// Creates a Client instance each time the server receives a user connection and create a new thread.
    ///
    void run();

    ///
    /// \brief Close the server and every connection
    ///
    void close();

    const ServerConfiguration& getConfiguration() const;

private:
    const ServerConfiguration&  _configuration; ///< Current configuration of the server
    TCP::Listener _listener; ///<

};
}

#endif
