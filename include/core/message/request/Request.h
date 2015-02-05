#ifndef _FURETTP_REQUEST_H
#define _FURETTP_REQUEST_H

#include <string>

namespace FuretTP {

	class Request {

	public:
		Request(const std::string& command);

		const std::string& getCommandName() const;

	private:
		std::string _command;
	};
}
#endif
