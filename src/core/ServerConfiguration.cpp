#include "core/ServerConfiguration.h"

using namespace FuretTP;

ServerConfiguration::ServerConfiguration() {
	loadDefault();
}

void ServerConfiguration::loadDefault() {
	_bindPort = 4224;
	_motd = "Welcome on FuretTP Server V1.0";
}

unsigned int ServerConfiguration::getBindPort() const {
	return _bindPort;
}

const std::string& ServerConfiguration::getMOTD() const {
	return _motd;
}
