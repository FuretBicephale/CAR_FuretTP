#include "core/message/request/PassRequest.h"

using namespace FuretTP;

PassRequest::PassRequest(const std::string& password) : Request(PassRequest::CommandName), _password(password) {

}

const std::string& PassRequest::getPassword() const {
	return _password;
}
