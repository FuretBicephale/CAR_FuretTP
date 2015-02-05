#include "exception/UnrecognizedMessageException.h"

using namespace FuretTP;

UnrecognizedMessageException::UnrecognizedMessageException(const std::string& command_name) : Exception("Unrecognized message \""+command_name+"\"") {

}
