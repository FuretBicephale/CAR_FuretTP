#ifndef _FURETTP_USER_H
#define _FURETTP_USER_H

#include "exception/UserNotFoundException.h"

#include <vector>
#include <string>

namespace FuretTP {

	struct User {

	public:
		User();
		User(const std::string& username, const std::string& password, const std::string& homeDir);

		const std::string& getUsername() const;
		const std::string& getPassword() const;
		const std::string& getHomeDir() const;

	private:
		std::string _username;
		std::string _password;
		std::string _homeDir;
	};

	class UserList {

	public:
		UserList();

		bool addUser(const User& user);
		const User& findUser(const std::string& username) const;
		bool hasUser(const std::string& username) const;

	private:
		UserList(const User& that);
		UserList& operator=(const User& that);

		std::vector<User> _userList;
	};
}

#endif
