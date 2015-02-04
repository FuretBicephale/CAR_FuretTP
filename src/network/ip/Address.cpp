#include "network/ip/Address.h"

using namespace FuretTP;
using namespace IP;

Address::Address() : _host(nullptr) {

}

Address::Address(const std::string& hostname) : _host(nullptr) {
    _host = gethostbyname(hostname.c_str());

    if(_host == nullptr) {
		THROW(AddressNotFoundException, hostname);
    }
}

void Address::_initialize() {

}

Address::Address(const Address& model) : _host(model._host) {

}

Address& Address::operator=(const Address& model) {
		_host = model._host;
}


std::ostream& FuretTP::IP::operator<<(std::ostream& stream, const Address& address) {
	if(address._host == nullptr) {
	   stream << "Unknown";
	}
	else {
		stream << "Unknown";
	}
	return stream;
}
