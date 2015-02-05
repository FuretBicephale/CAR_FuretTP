#include "core/message/answer/ConnectionInitializationAnswer.h"

using namespace FuretTP;

ConnectionInitializationAnswer::ConnectionInitializationAnswer(const std::string& motd) : Answer(ConnectionInitializationAnswer::Code), _motd(motd) {

}

void ConnectionInitializationAnswer::fillPacket(Packet& packet) {
	packet << " " << _motd;
}
