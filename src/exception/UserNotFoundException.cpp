#include "exception/UserNotFoundException.h"

using namespace FuretTP;

UserNotFoundException::UserNotFoundException(const std::string& file) : Exception("User not found : \""+file+"\"") {

}
