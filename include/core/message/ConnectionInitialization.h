#ifndef _MESSAGE_CONNECTION_INITIALIZATION_H
#define _MESSAGE_CONNECTION_INITIALIZATION_H

#include <string>

namespace FuretTP {

	namespace MSG {

		class ConnectionInitialization {

		public:
			ConnectionInitialization(const std::string& motd);
		};
	}
}

#endif
