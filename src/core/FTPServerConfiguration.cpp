#include "core/FTPServerConfiguration.h"

using namespace FuretTP;

FTPServerConfiguration::FTPServerConfiguration() {
	loadDefault();
}

void FTPServerConfiguration::loadDefault() {
	_bindPort = 4224;
	_motd = "Welcome on FuretTP Server V1.0";
}

unsigned int FTPServerConfiguration::getBindPort() const {
	return _bindPort;
}

const std::string& FTPServerConfiguration::getMOTD() const {
	return _motd;
}
