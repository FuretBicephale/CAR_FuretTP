#ifndef _FTP_RETR_REQUEST_H
#define _FTP_RETR_REQUEST_H

#include "core/message/request/Request.h"
#include "network/ip/Address.h"

namespace FTP {

    ///
    /// \class ftp::RetrRequest
    /// \ingroup request
    /// \brief Retr request.
    ///
    /// Command sent by the client to receive a remote file.
    ///
	class RetrRequest : public Request {

	public:

        ///
        /// \brief RetrRequest constructor
        /// \param filename The file to receive
        ///
		RetrRequest(const std::string& filename);

		const std::string& getFilename() const;

		static constexpr const char* CommandName = "RETR";

	private:
        std::string _filename; ///< The name of the file the user wants to receive

	};
}

#endif
