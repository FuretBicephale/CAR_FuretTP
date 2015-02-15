#include "exception/SocketClosedException.h"

using namespace FuretTP;

SocketClosedException::SocketClosedException(const std::string& message) : Exception("Socket  Closed : \""+message+"\"") {

}
