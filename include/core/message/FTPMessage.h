#ifndef _FTP_MESSAGE_H
#define _FTP_MESSAGE_H

#include "network/Packet.h"

#include <string>

namespace FuretTP {

	class FTPMessage {

	public:
		FTPMessage(unsigned int code);
		virtual ~FTPMessage();

		void generatePacket(Packet& packet);

		virtual void fillPacket(Packet& packet) = 0;

	private:
		unsigned int _code;
	};
}

#endif
