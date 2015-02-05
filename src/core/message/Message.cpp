#include "core/message/Message.h"

using namespace FuretTP;

Message::Message(unsigned int code, std::string name) : _code(code), _name(name) {

}

std::string Message::getName() const {
    return _name;
}

Message::~Message() {

}


void Message::generatePacket(Packet& packet) {
	packet << std::to_string(_code);
	this->fillPacket(packet);
}
