#include "core/FTPServer.h"

#include "core/UserConfigurationReader.h"

#include <iostream>

using namespace FTP;

int main() {

	try {
        std::cout << ".: FTP :." << std::endl;

		ServerConfiguration configuration;

		std::cout << "Read user list configuration (" << configuration.getUserConfigurationPathname() << ")" << std::endl;

		UserConfigurationReader::process(configuration.getUserConfigurationPathname(), configuration);

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
