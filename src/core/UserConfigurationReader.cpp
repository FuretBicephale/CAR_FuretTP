#include "core/UserConfigurationReader.h"

using namespace FTP;

void UserConfigurationReader::process(const std::string& pathname, ServerConfiguration& configuration) {

	std::ifstream file(pathname, std::ios::in);

	if(!file)
		THROW(FileNotFoundException, pathname);

	std::string current_line;
	unsigned int line_number = 1;

	while(getline(file, current_line)) {
#define FILE_FORMAT_LINE "Syntax : \"<Username> <Password> <HomeDir> <mode>\""
#define LINE_MAX_SIZE 1024
		char c_str[LINE_MAX_SIZE];
#define USER_INFO_NUMBER 4
		char* user_information[USER_INFO_NUMBER];

		memcpy(c_str, current_line.c_str(), current_line.size()+1);

		char* token = strtok(c_str, " ");
		unsigned int i;
		for(i=0; token != nullptr; i++) {

			if(i == USER_INFO_NUMBER) {
				THROW(IncorrecteFileFormatException, FILE_FORMAT_LINE, line_number, pathname)
			}
			user_information[i] = token;
			token = strtok(NULL, " ");
		}

		if(i != USER_INFO_NUMBER) {
			THROW(IncorrecteFileFormatException, FILE_FORMAT_LINE, line_number, pathname)
		}

		int mode = 0;

		if(std::string(user_information[3]).at(0) == 'r') {
			mode |= User::ReadFlag;
		}

		if(std::string(user_information[3]).at(1) == 'w') {
			mode |= User::WriteFlag;
		}

		configuration.getUserList().addUser(User(std::string(user_information[0]), std::string(user_information[1]), std::string(user_information[2]), mode));

		line_number++;
	}

	std::cout << (line_number-1) << " user loaded !" << std::endl;

	file.close();

}
