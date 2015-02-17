#include "exception/Exception.h"

using namespace FTP;

Exception::Exception() : _file(nullptr), _line(-1), _message()  {

}

Exception::Exception(const std::string& message) : _file(nullptr), _line(-1), _message(message) {

}

void Exception::setLocalisation(const char* file, int line) {
    _file = file;
    _line = line;
}

const std::string& Exception::getMessage() const throw() {
    return _message;
}

const char* Exception::getFile() const throw() {
    return _file;
}

int Exception::getLine() const throw() {
    return _line;
}
