#include "core/message/request/UserRequest.h"

using namespace FuretTP;

UserRequest::UserRequest(const std::string& username) : Request("USER"), _username(username) {

}
