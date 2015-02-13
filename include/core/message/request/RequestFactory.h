#ifndef _FURETTP_REQUEST_FACTORY_H
#define _FURETTP_REQUEST_FACTORY_H

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
#include "network/Packet.h"

namespace FuretTP {

	class RequestFactory {

	public:
		/// Return an FTPMessage. Receiver is responsable of the return delete
		static Request* eval(Packet& packet);

	private:
		//Static class
		RequestFactory();
		RequestFactory(const RequestFactory& that);
		RequestFactory& operator=(const RequestFactory& that);
	};
}

#endif
