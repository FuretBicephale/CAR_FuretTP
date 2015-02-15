#include "core/message/request/PortRequest.h"

using namespace FTP;

PortRequest::PortRequest(const IP::Address& address, unsigned int port) : Request(PortRequest::CommandName), _address(address), _port(port) {

}

const IP::Address& PortRequest::getAddress() const {
	return _address;
}

unsigned int PortRequest::getPort() const {
	return _port;
}
