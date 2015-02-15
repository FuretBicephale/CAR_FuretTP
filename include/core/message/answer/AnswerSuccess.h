#ifndef _FURETTP_ANSWER_SUCCESS_H
#define _FURETTP_ANSWER_SUCCESS_H

#include "core/message/answer/Answer.h"

#include <vector>
#include <string>

namespace FuretTP {

	/// \brief 200 OK
	class AnswerSuccess : public Answer {

	public:
		AnswerSuccess();

		static const unsigned int Code = 200;

	};

	/// \brief 211 System status
	class AnswerSystemStatus : public Answer {

	public:
		AnswerSystemStatus();

		static const unsigned int Code = 211;

	};

	/// \brief 215 system name
	class AnswerSystemName: public Answer {

	public:
		AnswerSystemName(const std::string& systemName);

		static const unsigned int Code = 215;

	};

	/// \brief 221 server close connection
	class AnswerServerCloseConnection: public Answer {

	public:
		AnswerServerCloseConnection();

		static const unsigned int Code = 221;

	};

	/// \brief 225 Data connection open, no transfert in progress
	class AnswerDataConnectionOpen: public Answer {

	public:
		AnswerDataConnectionOpen();

		static const unsigned int Code = 225;

	};

	/// \brief 226 File transfert success
	class AnswerTransfertSuccess: public Answer {

	public:
		AnswerTransfertSuccess();

		static const unsigned int Code = 226;

	};

	/// \brief 227 entering passive mode
	class AnswerEnteringPassiveMode: public Answer {

	public:
		AnswerEnteringPassiveMode();

		static const unsigned int Code = 227;

	};


	/// \brief 230 user identifiant ok
	class AnswerLoginOk : public Answer {

	public:
		AnswerLoginOk();

		static const unsigned int Code = 230;
	};

	/// \brief 257 system name
	class AnswerPathnameCreated: public Answer {

	public:
		AnswerPathnameCreated();

		static const unsigned int Code = 257;

	};

}

#endif
