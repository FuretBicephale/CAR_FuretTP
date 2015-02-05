#include "core/message/ConnectionInitialization.h"

using namespace FuretTP;
using namespace MSG;

ConnectionInitialization::ConnectionInitialization(const std::string& motd) : Message(ConnectionInitialization::Code), _motd(motd) {

}

void ConnectionInitialization::fillPacket(Packet& packet) {
	packet << " " << _motd << "\n";
}
