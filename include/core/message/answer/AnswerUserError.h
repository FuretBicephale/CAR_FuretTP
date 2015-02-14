#ifndef _FURETTP_ANSWER_USER_ERROR_H
#define _FURETTP_ANSWER_USER_ERROR_H

#include "core/message/answer/Answer.h"

#include <vector>
#include <string>

namespace FuretTP {

	/// \brief 425 can't open a data connection

	class AnswerOpenConnectionFailed : public Answer {

	public:
		AnswerOpenConnectionFailed();

		static const unsigned int Code = 425;
	};


	/// \brief 430 username or password incorrect
	class AnswerLoginFail : public Answer {

	public:
		AnswerLoginFail();

		static const unsigned int Code = 430;
	};



}

#endif
