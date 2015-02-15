#ifndef _FTP_REQUEST_H
#define _FTP_REQUEST_H

#include <string>

namespace FTP {

	class Request {

	public:
		Request(const std::string& command);

		const std::string& getCommandName() const;

	private:
		std::string _command;
	};
}
#endif
