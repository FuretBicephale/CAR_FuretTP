#ifndef _FTP_SYST_REQUEST_H
#define _FTP_SYST_REQUEST_H

#include "core/message/request/Request.h"
#include "network/ip/Address.h"

namespace FTP {

    ///
    /// \class ftp::SystRequest
    /// \ingroup request
    /// \brief Syst request.
    ///
    /// Command sent by the client to know server system.
    ///
	class SystRequest : public Request {

	public:

        ///
        /// \brief SystRequest constructor
        ///
		SystRequest();

		static constexpr const char* CommandName = "SYST";
	};
}

#endif
