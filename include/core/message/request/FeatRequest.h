#ifndef _FTP_FEAT_REQUEST_H
#define _FTP_FEAT_REQUEST_H

#include "core/message/request/Request.h"

namespace FTP {

    ///
    /// \class ftp::FeatRequest
    /// \ingroup request
    /// \brief Feat request.
    ///
    /// Request sent to know extra command supported by server undefined in RFC 959.
    ///
	class FeatRequest : public Request {

	public:

        ///
        /// \brief FeatRequest constructor
        ///
		FeatRequest();

		static constexpr const char* CommandName = "FEAT";

	};
}

#endif
