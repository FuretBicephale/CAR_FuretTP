#include "core/message/request/RetrRequest.h"

using namespace FTP;

RetrRequest::RetrRequest(const std::string& filename) : Request(RetrRequest::CommandName), _filename(filename) {

}

const std::string& RetrRequest::getFilename() const {
    return _filename;
}
