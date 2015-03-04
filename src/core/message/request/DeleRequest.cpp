#include "core/message/request/DeleRequest.h"

using namespace FTP;

DeleRequest::DeleRequest(const std::string& pathname) : Request(DeleRequest::CommandName), _pathname(pathname) {

}

const std::string& DeleRequest::getPathname() const {
	return _pathname;
}
