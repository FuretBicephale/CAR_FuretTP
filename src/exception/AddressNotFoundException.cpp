#include "exception/AddressNotFoundException.h"

using namespace FuretTP;

AddressNotFoundException::AddressNotFoundException(const std::string& address) : std::runtime_error("Address not found : \""+address+"\"") {

}
