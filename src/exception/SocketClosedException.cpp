#include "exception/SocketClosedException.h"

using namespace FTP;

SocketClosedException::SocketClosedException(const std::string& message) : Exception("Socket  Closed : \""+message+"\"") {

}
