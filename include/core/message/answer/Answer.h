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

		virtual void fillPacket(Packet& packet);

	private:
		unsigned int _code;
	};

	/*
	 *	Standart answers
	 */

	/// \brief 200 OK
	class AnswerSuccess : public Answer {

	public:
		AnswerSuccess();
	};

	/// \brief 331 Right user require password
	class AnswerWaitPassword : public Answer {

	public:
		AnswerWaitPassword();
	};

}





#endif
