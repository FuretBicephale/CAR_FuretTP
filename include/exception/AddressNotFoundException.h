#ifndef _EXCEPTION_ADDRESS_NOT_FOUND_H
#define _EXCEPTION_ADDRESS_NOT_FOUND_H

#include "exception/Exception.h"

#include <stdexcept>
#include <cstring>

namespace FuretTP {

    /// \brief Exception for Operating system error
	class AddressNotFoundException : public Exception {

    public:
        AddressNotFoundException(const std::string& address);
    };

}

#endif
