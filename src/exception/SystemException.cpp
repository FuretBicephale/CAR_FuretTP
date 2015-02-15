#include "exception/SystemException.h"

using namespace FTP;

SystemException::SystemException(const std::string& message, int error) : Exception("[System Exception] "+message+" | System message : "+strerror(error)+" [Code="+std::to_string(error)+"]") {

}
