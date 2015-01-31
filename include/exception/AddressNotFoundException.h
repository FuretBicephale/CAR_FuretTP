#ifndef _EXCEPTION_ADDRESS_NOT_FOUND_H
#define _EXCEPTION_ADDRESS_NOT_FOUND_H

#include <stdexcept>
#include <cstring>

namespace FuretTP {

    /// \brief Exception for Operating system error
    class AddressNotFoundException : public std::runtime_error {

    public:
        AddressNotFoundException(const std::string& address);
    };

}

#endif
