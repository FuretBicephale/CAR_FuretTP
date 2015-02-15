#include "core/message/answer/AnswerSuccess.h"

using namespace FTP;

AnswerSuccess::AnswerSuccess() : Answer(AnswerSuccess::Code) {

}

AnswerSystemStatus::AnswerSystemStatus() : Answer(AnswerSystemStatus::Code) {

}

AnswerSystemName::AnswerSystemName(const std::string& systemName) : Answer(AnswerSystemName::Code){
	addArgument(systemName);
}

AnswerDataConnectionOpen::AnswerDataConnectionOpen() : Answer(AnswerDataConnectionOpen::Code) {

}

AnswerTransfertSuccess::AnswerTransfertSuccess() : Answer(AnswerTransfertSuccess::Code) {

}

AnswerEnteringPassiveMode::AnswerEnteringPassiveMode() : Answer(AnswerEnteringPassiveMode::Code) {

}

AnswerLoginOk::AnswerLoginOk() : Answer(AnswerLoginOk::Code) {

}

AnswerPathnameCreated::AnswerPathnameCreated(const std::string& pathname) : Answer(AnswerPathnameCreated::Code) {
	addArgument(pathname);
}
