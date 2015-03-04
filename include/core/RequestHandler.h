#ifndef _FTP_RequestHandler_H
#define _FTP_RequestHandler_H

#include <algorithm>
#include <fstream>

#include "core/message/answer/AnswerInitialize.h"
#include "core/message/answer/AnswerSuccess.h"
#include "core/message/answer/AnswerWaiting.h"
#include "core/message/answer/AnswerUserError.h"
#include "core/message/answer/AnswerCommandError.h"

#include "core/message/request/UserRequest.h"
#include "core/message/request/PassRequest.h"
#include "core/message/request/ListRequest.h"
#include "core/message/request/PortRequest.h"
#include "core/message/request/StorRequest.h"
#include "core/message/request/RetrRequest.h"
#include "core/message/request/SystRequest.h"
#include "core/message/request/FeatRequest.h"
#include "core/message/request/PwdRequest.h"
#include "core/message/request/TypeRequest.h"
#include "core/message/request/PasvRequest.h"
#include "core/message/request/CWDRequest.h"
#include "core/message/request/CDUPRequest.h"
#include "core/message/request/MkdRequest.h"
#include "core/message/request/RmdRequest.h"
#include "core/message/request/QuitRequest.h"
#include "core/message/request/DeleRequest.h"
#include "system/Directory.h"

#include "network/ip/Address.h"

namespace FTP {

class Client;

///
/// \class RequestHandler
/// \ingroup core
/// \brief Interpret and execute a known request.
///
/// RequestHandler is a static Class.
/// It receives a request on its process method and then call the right method to execute it.
///
class RequestHandler {

public:

    ///
    /// \brief Call the right request handler for the request
    /// \param request Request to interpret and execute
    /// \param client the user who sends the request
    ///
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
    static void processStor(StorRequest& request, Client* client);
    static void processSyst(SystRequest& request, Client* client);
    static void processFeat(FeatRequest& request, Client* client);
    static void processPwd(PwdRequest& request, Client* client);
    static void processType(TypeRequest& request, Client* client);
    static void processPasv(PasvRequest& request, Client* client);
    static void processCwd(CWDRequest& request, Client* client);
    static void processCdup(CDUPRequest& request, Client* client);
    static void processMkd(MkdRequest& request, Client* client);
    static void processRmd(RmdRequest& request, Client* client);
    static void processQuit(QuitRequest& request, Client* client);
	static void processDele(DeleRequest& request, Client* client);
};
}

#endif
