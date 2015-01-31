#include "network/ip/Address.h"

using namespace FuretTP;
using namespace ip;

Address::Address(const std::string& hostname) : _host(nullptr) {
    _host = gethostbyname(hostname.c_str());

    if(_host == nullptr) {
        throw AddressNotFoundException(hostname);
    }
}
