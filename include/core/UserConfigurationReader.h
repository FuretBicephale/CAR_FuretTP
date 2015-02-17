#ifndef _FTP_USER_CONFIGURATION_H
#define _FTP_USER_CONFIGURATION_H

#include <iostream>
#include <fstream>
#include <cstring>

#include "exception/FileNotFoundException.h"
#include "exception/IncorrecteFileFormatException.h"
#include "core/ServerConfiguration.h"
#include "core/User.h"

namespace FTP {

///
/// \class UserConfigurationReader
/// \ingroup core
/// \brief A class used to read a file which contains user's account information
///
/// UserConfigurationReader is a static class.
/// It reads a file to retrieve information about server users accounts and add them to the server configuration UserList
///
class UserConfigurationReader {

public:

    ///
    /// \brief Read the file pathname and add the users to configuration
    /// \param pathname the file to read
    /// \param configuration the configuration where the methods will add users
    ///
    /// The read must contains n lines for n user.
    /// Each lines must be in the following format : <username> <password> <home_dir>
    /// If the file doesn't respect this syntax, the method will throw an IncorrecteFileFormatException
    ///
    static void process(const std::string& pathname, ServerConfiguration& configuration);

private:
    //static class
    UserConfigurationReader();
    UserConfigurationReader(const UserConfigurationReader& that);
    UserConfigurationReader& operator=(const UserConfigurationReader& that);

};
}

#endif
