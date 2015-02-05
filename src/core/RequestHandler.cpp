#include "core/RequestHandler.h"

using namespace FuretTP;

RequestHandler::RequestHandler() {

}

void RequestHandler::process(Request &request, Client &client) {
    name = request.getName();
    if(name == "USER") {
        processUser(static_cast<UserRequest&> request, client);
    } else if(name == "PASS") {
        processPass(static_cast<PassRequest&> request, client);
    } else if(name == "RETR") {
        processRetr(static_cast<RetrRequest&> request, client);
    } else if(name == "STOR") {
        processStor(static_cast<StorRequest&> request, client);
    } else if(name == "LIST") {
        processList(static_cast<ListRequest&> request, client);
    } else if(name == "QUIT") {
        processQuit(static_cast<QuitRequest&> request, client);
    } else if(name == "PWD") {
        processPwd(static_cast<PwdRequest&> request, client);
    } else if(name == "CWD") {
        processCwd(static_cast<CwdRequest&> request, client);
    } else if(name == "CDUP") {
        processCdup(static_cast<CdupRequest&> request, client);
    }
}

void RequestHandler::processUser(UserRequest &request, Client &client) {
    client.username = message.username;
}

void RequestHandler::processPass(PassRequest &request, Client &client) {
    client.password = message.password;
}

void RequestHandler::processRetr(RetrRequest &request, Client &client) {
    // TODO
}

void RequestHandler::processStor(StorRequest &request, Client &client) {
    // TODO
}

void RequestHandler::processList(ListRequest &request, Client &client) {
    // TODO
}

void RequestHandler::processQuit(QuitRequest &request, Client &client) {
    // TODO
}

void RequestHandler::processPwd(PwdRequest &request, Client &client) {
    // TODO
}

void RequestHandler::processCwd(CwdRequest &request, Client &client) {
    // TODO
}

void RequestHandler::processCdup(CdupRequest &request, Client &client) {
    // TODO
}
