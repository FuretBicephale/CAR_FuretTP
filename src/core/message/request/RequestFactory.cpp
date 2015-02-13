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
    else if(message_command == ListRequest::CommandName) {
        return new ListRequest();
    }
	else if(message_command == PortRequest::CommandName) {
		std::string address;
		packet >> address;
		return new PortRequest(address);
    }

    std::cerr << "Unrecognized command \"" << message_command << "\"" << std::endl;

	return nullptr;
}
