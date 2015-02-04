#include "core/FTPServerConfiguration.h"

using namespace FuretTP;

FTPServerConfiguration::FTPServerConfiguration() {
	loadDefault();
}

void FTPServerConfiguration::loadDefault() {
	_bindPort = 4223;
}

unsigned int FTPServerConfiguration::getBindPort() const {
	return _bindPort;
}
