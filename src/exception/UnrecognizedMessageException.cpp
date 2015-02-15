#include "exception/UnrecognizedMessageException.h"

using namespace FTP;

UnrecognizedMessageException::UnrecognizedMessageException(const std::string& command_name, const std::string& reason) : Exception("Unrecognized message \""+command_name+"\""+(reason != "" ? " | "+reason : "")) {

}
