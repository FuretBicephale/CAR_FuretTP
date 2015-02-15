#include "exception/NoActiveConnectionException.h"

using namespace FuretTP;

NoActiveConnectionException::NoActiveConnectionException(const std::string& message) : Exception("Non active connection : "+message) {

}
