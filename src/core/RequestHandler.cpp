#include "core/RequestHandler.h"
#include "core/Client.h"
#include <dirent.h>

using namespace FuretTP;


void RequestHandler::process(Request& request, Client* client) {
	const std::string& name = request.getCommandName();
	if(name == UserRequest::CommandName) {
		processUser(static_cast<UserRequest&>(request), client);
	} else if(name == PassRequest::CommandName) {
		processPass(static_cast<PassRequest&>(request), client);
	} else if(name == PortRequest::CommandName) {
		processPort(static_cast<PortRequest&>(request), client);
	} else if(name == ListRequest::CommandName) {
        processList(static_cast<ListRequest&>(request), client);
	} else if(name == RetrRequest::CommandName) {
		processRetr(static_cast<RetrRequest&>(request), client);
	} /*else if(name == "STOR") {
        processStor(static_cast<StorRequest&> request, client);
    } else if(name == "QUIT") {
        processQuit(static_cast<QuitRequest&> request, client);
    } else if(name == "PWD") {
        processPwd(static_cast<PwdRequest&> request, client);
    } else if(name == "CWD") {
        processCwd(static_cast<CwdRequest&> request, client);
    } else if(name == "CDUP") {
        processCdup(static_cast<CdupRequest&> request, client);
	}*/
}

void RequestHandler::processUser(UserRequest& request, Client* client) {
	Packet p;

	if(!client->setUsername(request.getUsername())) {
		AnswerLoginFail answer;
		answer.generatePacket(p);
	}
	else {
		AnswerUsernameOK answer;
		answer.generatePacket(p);
	}

	client->getSocket().send(p);
}

void RequestHandler::processPass(PassRequest& request, Client* client) {
	Packet p;

	if(client->login(request.getPassword())) {
		AnswerLoginOk answer("Welcome "+client->getUser().getUsername());
		answer.generatePacket(p);

	} else {
		AnswerLoginFail answer;
		answer.generatePacket(p);
		client->resetLogin();
	}

	client->getSocket().send(p);
}

void RequestHandler::processPort(PortRequest& request, Client* client) {
	Packet p;

	if(client->openConnection(IP::Address(request.getAddress()), request.getPort())) {
		AnswerSuccess answer;
		answer.generatePacket(p);

	} else {
		AnswerOpenConnectionFailed answer;
		answer.generatePacket(p);
		client->resetLogin();
	}

	client->getSocket().send(p);
}

void RequestHandler::processList(ListRequest& request, Client* client) {
    Packet p;

    const std::string currDir = client->getCurrentDir();
    const std::string listDir = "";

    DIR* dir = opendir(currDir.c_str());
    struct dirent* ent;
    if(dir != NULL) {
        while((ent = readdir(dir)) != NULL) {
            std::cout << ent->d_name << std::endl;
        }
        closedir(dir);
    } else {
        //Fail
    }

}


void RequestHandler::processRetr(RetrRequest& request, Client* client) {
    // TODO
}
/*
void RequestHandler::processStor(StorRequest &request, Client &client) {
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
*/
