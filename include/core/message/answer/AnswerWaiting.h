#ifndef _FURETTP_ANSWER_WAITING_H
#define _FURETTP_ANSWER_WAITING_H

#include "core/message/answer/Answer.h"

#include <vector>
#include <string>

namespace FuretTP {

	/// \brief 331 username OK, require password
	class AnswerUsernameOK : public Answer {

	public:
		AnswerUsernameOK();

		static const unsigned int Code = 331;
	};

}

#endif
