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
		std::string raw_address;
		packet >> raw_address;

		char* c_raw_addr = new char[raw_address.size()+1];

		strcpy(c_raw_addr, raw_address.c_str());

		char* token = strtok(c_raw_addr, ",");
		unsigned int i;

		std::string address;
		unsigned int port = 0;
		for(i=0; token != nullptr; i++) {

			int factor = 1;
			char* end_nb;

			switch(i) {
			case 0:
				address = token;
				break;
			case 1:
			case 2:
			case 3:
				address += "."+std::string(token);
				break;
			case 4:
				factor = 256;
			case 5:
				{
					int nb = strtol(token, &end_nb, 10);

					if(token == end_nb) {
						delete c_raw_addr;
						THROW(UnrecognizedMessageException, "PORT "+raw_address, std::string(token)+" is an incorrecte number");
					}
					port += factor*nb;
				}
				break;
			default:
				delete c_raw_addr;
				THROW(UnrecognizedMessageException, "PORT "+raw_address, "too many arguments");
			}

			token = strtok(NULL, ",");
		}
		delete c_raw_addr;
		if(i != 6)
			THROW(UnrecognizedMessageException, "PORT "+raw_address, "no enough argument");



		return new PortRequest(IP::Address(address), port);
    }
	else if(message_command == RetrRequest::CommandName) {
		std::string filename;
		packet >> filename;
		return new RetrRequest(filename);
	}
	else if(message_command == SystRequest::CommandName) {
		return new SystRequest();
	}
	else if(message_command == FeatRequest::CommandName) {
		return new FeatRequest();
	}
	else if(message_command == PwdRequest::CommandName) {
		return new PwdRequest();
	}
	else if(message_command == TypeRequest::CommandName) {
		std::string type_char;
		packet >> type_char;

		TypeRequest::Type type;
		switch(type_char.at(0)) {
		case 'A':
			type = TypeRequest::Ascii;
			break;
		case 'E':
			type = TypeRequest::Ebcdic;
			break;
		case 'I':
			type = TypeRequest::Image;
			break;
		case 'L':
			type = TypeRequest::Local;
			break;
		default:
			THROW(UnrecognizedMessageException, "TYPE", "Unrecognized type "+type_char)
		}

		return new TypeRequest(type);
	}
	else if(message_command == PasvRequest::CommandName) {
		return new PasvRequest();
	}

    std::cerr << "Unrecognized command \"" << message_command << "\"" << std::endl;

	return nullptr;
}
