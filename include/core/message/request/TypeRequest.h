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
    /// Set the type of file to be transferred
    ///
	class TypeRequest : public Request {

	public:

        ///
        /// \brief File type enumeration
        ///
		enum Type {
			Ascii,
			Ebcdic,
			Image,
			Local
		};

        ///
        /// \brief TypeRequest constructor
        /// \param type File type to set
        ///
		TypeRequest(Type type);

		Type getType() const;

		static constexpr const char* CommandName = "TYPE";

	private:
        Type _type; ///< The file type to set
	};
}

#endif
