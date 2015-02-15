#include "exception/AddressNotFoundException.h"

using namespace FTP;

AddressNotFoundException::AddressNotFoundException(const std::string& address) : Exception("Address not found : \""+address+"\"") {

}
