#ifndef _FTP_USER_H
#define _FTP_USER_H

#include "exception/UserNotFoundException.h"

#include <vector>
#include <string>

namespace FTP {

///
/// \struct User
/// \ingroup core
/// \brief Represents an user.
///
/// Represents an user connected to the server.
///
struct User {

public:

    ///
    /// \brief User constructor
    ///
    User();

    ///
    /// \brief User constructor
    /// \param username User's username
    /// \param password User's password
    /// \param homeDir User's root directory
    /// \param user mode (read/write)
    User(const std::string& username, const std::string& password, const std::string& homeDir, int mode);

    const std::string& getUsername() const;
    const std::string& getPassword() const;
    const std::string& getHomeDir() const;
    int getMode() const;

    static const int ReadFlag = 0x1;
    static const int WriteFlag = 0x2;

private:
    std::string _username; ///< User's username
    std::string _password; ///< User's password
    std::string _homeDir; ///< User's root directory
    int _mode;
};

///
/// \class UserList
/// \ingroup core
/// \brief Represents a list of users.
///
/// Represents a list of users connected to the server.
///
class UserList {

public:

    ///
    /// \brief UserList constructor
    ///
    UserList();

    ///
    /// \brief Add an user to the list
    /// \param user The user to add
    /// \return True if the user is added, false otherwise
    ///
    bool addUser(const User& user);

    ///
    /// \brief Find an user with his username in the list
    /// \param username the username of the user we're searching for
    /// \return the user if he's finded, throw an UserNotFoundException otherwise
    ///
    const User& findUser(const std::string& username) const;

    ///
    /// \brief hasUser Says if the list contains an user with the username username
    /// \param username
    /// \return True if the list contains the user username, False otherwise
    ///
    bool hasUser(const std::string& username) const;

private:
    UserList(const User& that);
    UserList& operator=(const User& that);

    std::vector<User> _userList; ///< The list of users connected to the server
};
}

#endif
