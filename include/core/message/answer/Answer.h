#ifndef _FTP_ANSWER_H
#define _FTP_ANSWER_H

#include "network/Packet.h"

#include <vector>
#include <string>

namespace FTP {

///
/// \class Answer
/// \ingroup answer
/// \brief Basic request's answer.
///
/// Represents a packet send by the server to the user in response of a request.
///
class Answer {

public:

    ///
    /// \brief Answer constructor.
    /// \param code Return code value of the answer
    ///
    Answer(unsigned int code);

    ///
    /// \brief Answer desctructor.
    ///
    virtual ~Answer();

    ///
    /// \brief generatePacket generate a packet to send to the user from the answer class.
    /// \param packet Packet which will contains the generated packet
    ///
    /// The packet will have the following format : <_code> <_arguments>.
    ///
    void generatePacket(Packet& packet);

    ///
    /// \brief Add a string argument to the answer.
    /// \param argument the string to add
    ///
    void addArgument(const std::string& argument);

private:
    unsigned int _code; ///< Return code of the answer
    std::vector<std::string> _arguments; ///< The sequence of string to be send with the return code
};

}

#endif
