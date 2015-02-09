#include "core/message/answer/Answer.h"

using namespace FuretTP;

Answer::Answer(unsigned int code) : _code(code) {

}

Answer::~Answer() {

}


void Answer::generatePacket(Packet& packet) {
	packet << std::to_string(_code);
	this->fillPacket(packet);
	packet << "\n";
}

void Answer::fillPacket(Packet& packet) {

}

/*
 *	Standart answers
 */

AnswerSuccess::AnswerSuccess() : Answer(AnswerSuccess::Code) {

}

AnswerUsernameOK::AnswerUsernameOK() : Answer(AnswerUsernameOK::Code) {

}

AnswerLoginOk::AnswerLoginOk() : Answer(AnswerLoginOk::Code), _message() {

}

AnswerLoginOk::AnswerLoginOk(const std::string& loginMessage) : Answer(AnswerLoginOk::Code), _message(loginMessage)  {

}

void AnswerLoginOk::fillPacket(Packet& packet) {
	packet << " " << _message;
}

AnswerLoginFail::AnswerLoginFail() : Answer(AnswerLoginFail::Code) {

}
