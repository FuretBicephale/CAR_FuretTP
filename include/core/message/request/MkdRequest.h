#ifndef _FTP_MKD_REQUEST_H
#define _FTP_MKD_REQUEST_H

#include "core/message/request/Request.h"

namespace FTP {

///
/// \class MkdRequest
/// \ingroup request
/// \brief Mkd request.
///
/// Asks the server to create a new folder in the current directory.
///
class MkdRequest : public Request {

public:

    ///
    /// \brief MkdRequest constructor
    /// \param name The name of the folder
    ///
    MkdRequest(const std::string& name);

    const std::string& getName() const;

    static constexpr const char* CommandName = "MKD";

private:
    std::string _name; ///< The name of the folder the user wants to create

};
}

#endif
