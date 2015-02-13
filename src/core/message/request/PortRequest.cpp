#include "core/message/request/PortRequest.h"

using namespace FuretTP;

PortRequest::PortRequest(const std::string& address) : Request(PortRequest::CommandName), _address(), _port(0) {

}

const std::string& PortRequest::getAddress() const {
	return _address;
}

unsigned int PortRequest::getPort() const {
	return _port;
}

void PortRequest::_parseArgument(const std::string& address) {
#define ADDRESS_MAX_LENGTH 1024
	//char c_str[LINE_MAX_SIZE];

}
