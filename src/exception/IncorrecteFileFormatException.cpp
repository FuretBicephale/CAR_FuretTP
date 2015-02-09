#include "exception/IncorrecteFileFormatException.h"

using namespace FuretTP;

IncorrecteFileFormatException::IncorrecteFileFormatException(const std::string& message, unsigned int line, const std::string& file) : Exception("Incorrecte file format : "+message+" | At line "+std::to_string(line)+" in file \""+file+"\"") {

}
