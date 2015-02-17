#ifndef _FTP_SOCKET_CLOSED_EXCEPTION_H
#define _FTP_SOCKET_CLOSED_EXCEPTION_H

#include <string>

#include "exception/Exception.h"

namespace FTP {

///
/// \class ftp::SocketClosedException
/// \ingroup exception
/// \brief Exception launched when a socket close at an unexpected moment
///
class SocketClosedException : public Exception {

public:

    ///
    /// \brief SocketClosedException constructor
    /// \param message A message to print
    ///
    SocketClosedException(const std::string& message);
};
}

#endif
