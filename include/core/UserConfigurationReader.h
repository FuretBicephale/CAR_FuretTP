#ifndef _FURETTP_USER_CONFIGURATION_H
#define _FURETTP_USER_CONFIGURATION_H

#include <iostream>
#include <fstream>
#include <cstring>

#include "exception/FileNotFoundException.h"
#include "exception/IncorrecteFileFormatException.h"
#include "core/ServerConfiguration.h"
#include "core/User.h"

namespace FuretTP {

	class UserConfigurationReader {

	public:
		static void process(const std::string& pathname, ServerConfiguration& configuration);

	private:
		//static class
		UserConfigurationReader();
		UserConfigurationReader(const UserConfigurationReader& that);
		UserConfigurationReader& operator=(const UserConfigurationReader& that);

	};
}

#endif
