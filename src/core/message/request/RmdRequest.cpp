#include "core/message/request/RmdRequest.h"

using namespace FTP;

RmdRequest::RmdRequest(const std::string& name) : Request(RmdRequest::CommandName), _name(name) {

}

const std::string& RmdRequest::getName() const {
	return _name;
}
