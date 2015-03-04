#ifndef _FTP_DELE_REQUEST_H
#define _FTP_DELE_REQUEST_H

#include "core/message/request/Request.h"

namespace FTP {

///
/// \class FeatRequest
/// \ingroup request
/// \brief Feat request.
///
/// Request sent to know extra command supported by server undefined in RFC 959.
///
class DeleRequest : public Request {

public:

	///
	/// \brief FeatRequest constructor
	///
	DeleRequest(const std::string& pathname);

	const std::string& getPathname() const;

	static constexpr const char* CommandName = "DELE";

private:
	std::string _pathname;

};
}

#endif
