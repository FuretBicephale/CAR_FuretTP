#include "exception/UserNotFoundException.h"

using namespace FTP;

UserNotFoundException::UserNotFoundException(const std::string& file) : Exception("User not found : \""+file+"\"") {

}
