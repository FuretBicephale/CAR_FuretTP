#ifndef _FTP_ANSWER_COMMAND_ERROR_H
#define _FTP_ANSWER_COMMAND_ERROR_H

#include "core/message/answer/Answer.h"

#include <vector>
#include <string>

namespace FTP {

	/// \brief 502 unimplemented command

	class AnswerUnimplemented : public Answer {

	public:
		AnswerUnimplemented();

		static const unsigned int Code = 502;
	};

	/// \brief 550 file unavailable

	class AnswerFileUnavailable : public Answer {

	public:
		AnswerFileUnavailable();

		static const unsigned int Code = 550;
	};

}

#endif
