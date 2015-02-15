#ifndef _FTP_TYPE_REQUEST_H
#define _FTP_TYPE_REQUEST_H

#include "core/message/request/Request.h"
#include "network/ip/Address.h"

namespace FTP {

	/// Command send by the client for known server system
	class TypeRequest : public Request {

	public:
		enum Type {
			Ascii,
			Ebcdic,
			Image,
			Local
		};

		TypeRequest(Type type);

		Type getType() const;

		static constexpr const char* CommandName = "TYPE";

	private:
		Type _type;
	};
}

#endif
