#include "exception/FileNotFoundException.h"

using namespace FTP;

FileNotFoundException::FileNotFoundException(const std::string& file) : Exception("File not found : \""+file+"\"") {

}
