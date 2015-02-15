#ifndef _FTP_TYPE_REQUEST_H
#define _FTP_TYPE_REQUEST_H

#include "core/message/request/Request.h"
#include "network/ip/Address.h"

namespace FTP {

    ///
    /// \class ftp::TypeRequest
    /// \ingroup request
    /// \brief Type request.
    ///
    ///
    ///
	class TypeRequest : public Request {

	public:

        ///
        /// \brief The Type enum
        ///
		enum Type {
			Ascii,
			Ebcdic,
			Image,
			Local
		};

        ///
        /// \brief TypeRequest constructor
        /// \param type
        ///
		TypeRequest(Type type);

		Type getType() const;

		static constexpr const char* CommandName = "TYPE";

	private:
        Type _type; ///<
	};
}

#endif
