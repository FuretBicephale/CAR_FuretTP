#include "core/message/request/RequestFactory.h"

using namespace FuretTP;

Request* RequestFactory::eval(Packet& packet) {

	std::string message_command;

	packet >> message_command;

	if(message_command == UserRequest::CommandName) {
		std::string username;
		packet >> username;
		return new UserRequest(username);
	}
	else if(message_command == PassRequest::CommandName) {
		std::string password;
		packet >> password;
		return new PassRequest(password);
	}

	THROW(UnrecognizedMessageException, message_command)
}
