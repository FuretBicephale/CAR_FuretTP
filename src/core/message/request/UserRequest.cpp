#include "core/message/request/UserRequest.h"

using namespace FTP;

UserRequest::UserRequest(const std::string& username) : Request(UserRequest::CommandName), _username(username) {

}

const std::string& UserRequest::getUsername() const {
    return _username;
}
