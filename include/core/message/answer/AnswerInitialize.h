#ifndef _FURETTP_ANSWER_INITIALIZE_H
#define _FURETTP_ANSWER_INITIALIZE_H

#include "core/message/answer/Answer.h"

#include <vector>
#include <string>

namespace FuretTP {

	/// \brief 150 file status okay; about to open data connection.

	class AnswerFileStatusOK : public Answer {

	public:
		 AnswerFileStatusOK();

		static const unsigned int Code = 150;
	};
}

#endif
