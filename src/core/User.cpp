#include "core/User.h"

using namespace FTP;

User::User() : _username(), _password(), _homeDir() {

}

User::User(const std::string& username, const std::string& password, const std::string& homeDir) : _username(username), _password(password), _homeDir(homeDir) {

}

const std::string& User::getUsername() const {
	return _username;
}

const std::string& User::getPassword() const {
	return _password;
}

const std::string& User::getHomeDir() const {
	return _homeDir;
}

UserList::UserList() : _userList() {

}

bool UserList::addUser(const User& user) {
	if(hasUser(user.getUsername())) {
		return false;
	}
	_userList.push_back(user);

	return true;
}

const User& UserList::findUser(const std::string& username) const {
	for(auto it = _userList.begin(); it != _userList.end(); ++it) {
		if(it->getUsername() == username) {
			return *it;
		}
	}

	THROW(UserNotFoundException, username);
}

bool UserList::hasUser(const std::string& username) const {
	for(auto it = _userList.begin(); it != _userList.end(); ++it) {
		if(it->getUsername() == username) {
			return true;
		}
	}

	return false;
}
