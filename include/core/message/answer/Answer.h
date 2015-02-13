#ifndef _FURETTP_ANSWER_H
#define _FURETTP_ANSWER_H

#include "network/Packet.h"

#include <vector>
#include <string>

namespace FuretTP {

	class Answer {

	public:
		Answer(unsigned int code);
		virtual ~Answer();

		void generatePacket(Packet& packet);

		virtual void fillPacket(Packet& packet);

		void addArgument(const std::string& argument);

	private:
		unsigned int _code;
		std::vector<std::string> _arguments;
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

	/// \brief 230 user identifiant ok
	class AnswerLoginOk : public Answer {

	public:
		AnswerLoginOk();
		AnswerLoginOk(const std::string& loginMessage);

		void fillPacket(Packet& packet);

		static const unsigned int Code = 230;

	private:
		std::string _message;
	};

	/// \brief 430 username or password incorrect
	class AnswerLoginFail : public Answer {

	public:
		AnswerLoginFail();

		static const unsigned int Code = 430;
	};

    class AnswerListOk : public Answer {

    public:
        AnswerListOk();

        static const unsigned int Code = 150;
    };

    class AnswerListFail : public Answer {

    public:
        AnswerListFail();

        static const unsigned int Code = 550;
    };


	/// \brief 502 unimplemented command

	class AnswerUnimplemented : public Answer {

	public:
		AnswerUnimplemented();

		static const unsigned int Code = 502;
	};


}





#endif
