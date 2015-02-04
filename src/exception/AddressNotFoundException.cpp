#include "exception/AddressNotFoundException.h"

using namespace FuretTP;

AddressNotFoundException::AddressNotFoundException(const std::string& address) : Exception("Address not found : \""+address+"\"") {

}
