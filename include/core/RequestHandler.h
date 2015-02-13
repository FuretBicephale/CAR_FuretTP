#ifndef _FTP_RequestHandler_H
#define _FTP_RequestHandler_H

#include "core/message/request/Request.h"
#include "core/message/answer/Answer.h"

#include "core/message/request/UserRequest.h"
#include "core/message/request/PassRequest.h"
#include "core/message/request/ListRequest.h"
#include "core/message/request/PortRequest.h"

#include "network/ip/Address.h"

namespace FuretTP {

	class Client;

    class RequestHandler {

    public:

        // Call the right command handler for the message
		static void process(Request& request, Client* client);

	private:
		// Static class
		RequestHandler();
		RequestHandler(const RequestHandler& that);
		RequestHandler& operator=(const RequestHandler& that);

        // Server command handlers
		static void processUser(UserRequest& request, Client* client);
		static void processPass(PassRequest& request, Client* client);
        static void processList(ListRequest& request, Client* client);
		static void processPort(PortRequest& request, Client* client);
	   /* static void processRetr(RertRequest &request, Client &client);
        static void processStor(StorRequest &request, Client &client);
        static void processQuit(QuitRequest &request, Client &client);
        static void processPwd(PwdRequest &request, Client &client);
        static void processCwd(CwdRequest &request, Client &client);
		static void processCdup(CdupRequest &request, Client &client);*/

    };
}

#endif
