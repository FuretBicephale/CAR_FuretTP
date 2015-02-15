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

    class AnswerCWDOk : public Answer {

    public:
        AnswerCWDOk();

        static const unsigned int Code = 250;
    };

    class AnswerCWDFail : public Answer {

    public:
        AnswerCWDFail();

        static const unsigned int Code = 550;
    };

}

#endif
