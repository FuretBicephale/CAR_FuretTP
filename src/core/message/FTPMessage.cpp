#include "core/message/FTPMessage.h"

using namespace FuretTP;

FTPMessage::FTPMessage(unsigned int code) : _code(code) {

}

FTPMessage::~FTPMessage() {

}


void FTPMessage::generatePacket(Packet& packet) {
	packet << std::to_string(_code);
	this->fillPacket(packet);
}
