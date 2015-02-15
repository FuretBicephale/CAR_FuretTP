#ifndef _FTP_ANSWER_WAITING_H
#define _FTP_ANSWER_WAITING_H

#include "core/message/answer/Answer.h"

#include <vector>
#include <string>

namespace FTP {

    /// \brief 331 Username OK, require password
	class AnswerUsernameOK : public Answer {

	public:
		AnswerUsernameOK();

		static const unsigned int Code = 331;
	};

}

#endif
