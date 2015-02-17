#ifndef _FTP_RMD_REQUEST_H
#define _FTP_RMD_REQUEST_H

#include "core/message/request/Request.h"

namespace FTP {

    ///
    /// \class ftp::RmdRequest
    /// \ingroup request
    /// \brief Rmd request.
    ///
    /// Asks the server to delete a folder in the current directory.
    ///
	class RmdRequest : public Request {

	public:

        ///
        /// \brief RmdRequest constructor
        /// \param name The name of the folder to delete.
        ///
		RmdRequest(const std::string& name);

		const std::string& getName() const;

        static constexpr const char* CommandName = "RMD";

	private:
        std::string _name; ///< The name of the folder the user wants to delete.

	};
}

#endif
