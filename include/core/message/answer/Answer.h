#ifndef _FURETTP_ANSWER_H
#define _FURETTP_ANSWER_H

#include "network/Packet.h"

#include <string>

namespace FuretTP {

	class Answer {

	public:
		Answer(unsigned int code);
		virtual ~Answer();

		void generatePacket(Packet& packet);

		virtual void fillPacket(Packet& packet) = 0;

	private:
		unsigned int _code;
	};
}

#endif
