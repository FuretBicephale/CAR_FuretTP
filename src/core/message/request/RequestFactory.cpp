#include "core/message/request/RequestFactory.h"

using namespace FuretTP;

std::unique_ptr<Request> RequestFactory::eval(Packet& packet) {

	std::string message_command;

	packet >> message_command;

	if(message_command == "USER") {
		std::string username;
		packet >> username;
		return std::unique_ptr<Request>(new UserRequest(username));
	}


	THROW(UnrecognizedMessageException, message_command)
}
