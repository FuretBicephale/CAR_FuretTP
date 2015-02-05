#ifndef _FTP_MESSAGE_H
#define _FTP_MESSAGE_H

#include "network/Packet.h"

#include <string>

namespace FuretTP {

    class Message {

	public:
        Message(unsigned int code, std::string name);
        virtual ~Message();

        std::string getName() const;

		void generatePacket(Packet& packet);

		virtual void fillPacket(Packet& packet) = 0;

	private:
        std::string _name;
		unsigned int _code;
	};
}

#endif
