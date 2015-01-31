#ifndef _FURETTP_EXCEPTION_H
#define _FURETTP_EXCEPTION_H

#define THROW(EXCEPTION_TYPE, ...) {\
			EXCEPTION_TYPE exception(__VA_ARGS__);\
			exception.setLocalisation(__FILE__, __LINE__);\
			throw exception;\
		}

#include <string>
#include <stdexcept>

namespace FuretTP {

	class Exception {

	public:
		Exception();
		Exception(const std::string& message);

		void setLocalisation(const char* file, int line);

		const std::string& getMessage() const throw();
		const char* getFile() const throw();
		int getLine() const throw();

	private:
		const char* _file;
		int _line;
		std::string _message;

	};
}

#endif
