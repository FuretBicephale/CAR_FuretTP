#include "core/ServerConfiguration.h"

using namespace FuretTP;

ServerConfiguration::ServerConfiguration() {
	loadDefault();
}

void ServerConfiguration::loadDefault() {
	_userConfigurationPathname = "user.conf";
	_bindPort = 4224;
	_motd = "Welcome on FuretTP Server V1.0";
}

UserList& ServerConfiguration::getUserList() {
	return _userList;
}

const UserList& ServerConfiguration::getUserList() const {
	return _userList;
}

const std::string& ServerConfiguration::getUserConfigurationPathname() const {
	return _userConfigurationPathname;
}

unsigned int ServerConfiguration::getBindPort() const {
	return _bindPort;
}

const std::string& ServerConfiguration::getMOTD() const {
	return _motd;
}
