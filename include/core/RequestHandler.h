#ifndef _FTP_RequestHandler_H
#define _FTP_RequestHandler_H

#include "core/message/Message.h"
#include "core/Client.h"

namespace FuretTP {

    class RequestHandler {

    public:
        // Constructor
        RequestHandler();

        // Call the right command handler for the message
        static void process(Request &request, Client &client);

        // Server command handlers
        static void processUser(UserRequest &request, Client &client);
        static void processPass(PassRequest &request, Client &client);
        static void processRetr(RertRequest &request, Client &client);
        static void processStor(StorRequest &request, Client &client);
        static void processList(ListRequest &request, Client &client);
        static void processQuit(QuitRequest &request, Client &client);
        static void processPwd(PwdRequest &request, Client &client);
        static void processCwd(CwdRequest &request, Client &client);
        static void processCdup(CdupRequest &request, Client &client);

    private:

    };
}

#endif
