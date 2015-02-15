#include "core/message/request/MkdRequest.h"

using namespace FuretTP;

MkdRequest::MkdRequest(const std::string& name) : Request(MkdRequest::CommandName), _name(name) {

}

const std::string& MkdRequest::getName() const {
	return _name;
}
