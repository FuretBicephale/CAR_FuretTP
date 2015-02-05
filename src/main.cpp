#include "core/FTPServer.h"

#include <iostream>

using namespace FuretTP;

int main() {

	try {
		std::cout << ".: FuretTP :." << std::endl;

		ServerConfiguration configuration;

		FTPServer server(configuration);

		server.run();

	}
	catch(const Exception& e) {
		std::cerr << e.getMessage() << std::endl;
		std::cerr << "Exception caught in main thread" << std::endl;
		if(e.getFile() != nullptr)
			std::cerr << "Line " << e.getLine() << " in file " << e.getFile() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
