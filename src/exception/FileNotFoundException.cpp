#include "exception/FileNotFoundException.h"

using namespace FuretTP;

FileNotFoundException::FileNotFoundException(const std::string& file) : Exception("File not found : \""+file+"\"") {

}
