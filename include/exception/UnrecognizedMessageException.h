#ifndef _EXCEPTION_UNRECOGNIZED_MESSAGE_H
#define _EXCEPTION_UNRECOGNIZED_MESSAGE_H

#include "exception/Exception.h"

namespace FTP {

    ///
    /// \class ftp::UnrecognizedMessageException
    /// \ingroup exception
    /// \brief Exception launched when a message send by user isn't recognized
    ///
	class UnrecognizedMessageException 	: public Exception {

	public:

        ///
        /// \brief UnrecognizedMessageException constructor
        /// \param command The command send by user
        /// \param reason The reason of unrecognition
        ///
		UnrecognizedMessageException(const std::string& command, const std::string& reason = "");
	};
}

#endif
