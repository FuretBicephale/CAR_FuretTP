#ifndef _FTP_RequestHandler_H
#define _FTP_RequestHandler_H

#include <algorithm>
#include <fstream>

#include "core/message/answer/AnswerSuccess.h"
#include "core/message/answer/AnswerWaiting.h"
#include "core/message/answer/AnswerUserError.h"
#include "core/message/answer/AnswerCommandError.h"

#include "core/message/request/UserRequest.h"
#include "core/message/request/PassRequest.h"
#include "core/message/request/ListRequest.h"
#include "core/message/request/PortRequest.h"
#include "core/message/request/RetrRequest.h"
#include "core/message/request/SystRequest.h"
#include "core/message/request/FeatRequest.h"
#include "core/message/request/PwdRequest.h"
#include "core/message/request/TypeRequest.h"
#include "core/message/request/PasvRequest.h"
#include "system/Directory.h"

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
		static void processRetr(RetrRequest& request, Client* client);
		static void processSyst(SystRequest& request, Client* client);
		static void processFeat(FeatRequest& request, Client* client);
		static void processPwd(PwdRequest& request, Client* client);
		static void processType(TypeRequest& request, Client* client);
		static void processPasv(PasvRequest& request, Client* client);
		/*static void processStor(StorRequest &request, Client &client);
        static void processQuit(QuitRequest &request, Client &client);
        static void processPwd(PwdRequest &request, Client &client);
        static void processCwd(CwdRequest &request, Client &client);
		static void processCdup(CdupRequest &request, Client &client);*/

    };
}

#endif
