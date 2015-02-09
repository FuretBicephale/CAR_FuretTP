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

		static const unsigned int Code = 200;
	};

	/// \brief 331 username exist, require password
	class AnswerUsernameOK : public Answer {

	public:
		AnswerUsernameOK();

		static const unsigned int Code = 331;
	};

	/// \brief 330 user identifiant ok
	class AnswerLoginOk : public Answer {

	public:
		AnswerLoginOk();
		AnswerLoginOk(const std::string& loginMessage);

		void fillPacket(Packet& packet);

		static const unsigned int Code = 330;

	private:
		std::string _message;
	};

	/// \brief 430 username or password incorrect
	class AnswerLoginFail : public Answer {

	public:
		AnswerLoginFail();

		static const unsigned int Code = 430;
	};



}





#endif
