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
