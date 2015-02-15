#ifndef _FTP_REQUEST_FACTORY_H
#define _FTP_REQUEST_FACTORY_H

#include <memory>
#include <sstream>

#include "core/message/request/Request.h"
#include "core/message/answer/Answer.h"
#include "exception/UnrecognizedMessageException.h"
#include "network/ip/Address.h"

#include "core/message/request/UserRequest.h"
#include "core/message/request/PassRequest.h"
#include "core/message/request/ListRequest.h"
#include "core/message/request/PortRequest.h"
#include "core/message/request/RetrRequest.h"
#include "core/message/request/StorRequest.h"
#include "core/message/request/SystRequest.h"
#include "core/message/request/FeatRequest.h"
#include "core/message/request/PwdRequest.h"
#include "core/message/request/TypeRequest.h"
#include "core/message/request/PasvRequest.h"
#include "core/message/request/CWDRequest.h"
#include "core/message/request/CDUPRequest.h"
#include "network/Packet.h"

namespace FTP {

    ///
    /// \class ftp::RequestFactory
    /// \ingroup request
    /// \brief Determine the class of request packet
    ///
    /// RequestFactory is a static class.
    /// It evaluate a packet in order to create a request from it.
    ///
	class RequestFactory {

	public:

        ///
        /// \brief Create a request from the packet
        /// \param packet The packet to evaluate
        /// \return FTPMessage
        ///
        /// The receiver is responsible of the returned object deletion
        ///
        static Request* eval(Packet& packet);

	private:
		//Static class
		RequestFactory();
		RequestFactory(const RequestFactory& that);
		RequestFactory& operator=(const RequestFactory& that);
	};
}

#endif
