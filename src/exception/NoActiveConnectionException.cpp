#include "exception/NoActiveConnectionException.h"

using namespace FTP;

NoActiveConnectionException::NoActiveConnectionException(const std::string& message) : Exception("Non active connection : "+message) {

}
