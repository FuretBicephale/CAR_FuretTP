#include "core/message/request/StorRequest.h"

using namespace FTP;

StorRequest::StorRequest(const std::string& filename) : Request(StorRequest::CommandName), _filename(filename) {

}

const std::string& StorRequest::getFilename() const {
	return _filename;
}
