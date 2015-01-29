#include "exception/SystemException.h"

using namespace FuretTP;

SystemException::SystemException(const std::string& message, int error) : std::runtime_error("[System Exception] "+message+" | System message : "+strerror(error)) {

}
