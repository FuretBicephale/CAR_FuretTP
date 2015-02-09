#include "core/UserConfigurationReader.h"

using namespace FuretTP;

void UserConfigurationReader::process(const std::string& pathname, ServerConfiguration& configuration) {

	std::ifstream file(pathname, std::ios::in);

	if(!file)
		THROW(FileNotFoundException, pathname);

	std::string current_line;

	while(getline(file, current_line)) {

	}

}
