#include "core/message/request/Request.h"

using namespace FuretTP;

Request::Request(const std::string& command) : _command(command) {

}

const std::string& Request::getCommandName() const {
	return _command;
}
