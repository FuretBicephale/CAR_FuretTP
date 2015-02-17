#ifndef _EXCEPTION_ADDRESS_NOT_FOUND_H
#define _EXCEPTION_ADDRESS_NOT_FOUND_H

#include "exception/Exception.h"

#include <stdexcept>
#include <cstring>

namespace FTP {


///
/// \class ftp::AddressNotFoundException
/// \ingroup exception
/// \brief Exception for Operating system error
///
class AddressNotFoundException : public Exception {

public:

    ///
    /// \brief AddressNotFoundException constructor
    /// \param address The address which is not found
    ///
    AddressNotFoundException(const std::string& address);
};

}

#endif
