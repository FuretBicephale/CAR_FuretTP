#include "core/message/answer/Answer.h"

using namespace FTP;

Answer::Answer(unsigned int code) : _code(code), _arguments() {

}

Answer::~Answer() {

}


void Answer::generatePacket(Packet& packet) {
    packet << std::to_string(_code);

    for(auto it = _arguments.begin(); it != _arguments.end(); ++it) {
        packet << " " << *it;
    }

    packet << "\n";
}

void Answer::addArgument(const std::string& argument) {
    _arguments.push_back(argument);
}

