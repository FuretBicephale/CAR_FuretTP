#ifndef _MESSAGE_CONNECTION_INITIALIZATION_H
#define _MESSAGE_CONNECTION_INITIALIZATION_H

#include <string>

#include "core/message/FTPMessage.h"

namespace FuretTP {

	namespace MSG {

		class ConnectionInitialization : public FTPMessage {

		public:
			ConnectionInitialization(const std::string& motd);
			void fillPacket(Packet& packet);

			static const unsigned int Code = 200;

		private:

			std::string _motd;
		};
	}
}

#endif
