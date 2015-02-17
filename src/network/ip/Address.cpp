#include "network/ip/Address.h"

using namespace FTP;
using namespace IP;

Address::Address() : _host(nullptr) {

}

Address::Address(const std::string& hostname) : _host(nullptr) {
    _host = gethostbyname(hostname.c_str());

    if(_host == nullptr) {
		THROW(AddressNotFoundException, hostname);
    }
}

Address::Address(const Address& model) : _host(model._host) {

}

Address& Address::operator=(const Address& model) {
		_host = model._host;
}

const char* Address::getRawAddress() const {
	return _host->h_addr;
}

int Address::getAddressType() const {
	return _host->h_addrtype;
}

std::ostream& FTP::IP::operator<<(std::ostream& stream, const Address& address) {
	if(address._host == nullptr) {
	   stream << "Unknown";
	}
	else {
		char* buffer = inet_ntoa(*((struct in_addr *)address._host->h_addr_list[0]));
		stream << buffer;
	}
	return stream;
}
