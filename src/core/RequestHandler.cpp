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
	} else if(name == SystRequest::CommandName) {
		processSyst(static_cast<SystRequest&>(request), client);
	} else if(name == FeatRequest::CommandName) {
		processFeat(static_cast<FeatRequest&>(request), client);
	} else if(name == PwdRequest::CommandName) {
		processPwd(static_cast<PwdRequest&>(request), client);
	} else if(name == TypeRequest::CommandName) {
		processType(static_cast<TypeRequest&>(request), client);
	} else if(name == PasvRequest::CommandName) {
		processPasv(static_cast<PasvRequest&>(request), client);
    } else if(name == CWDRequest::CommandName) {
        processCwd(static_cast<CWDRequest&>(request), client);
    }
	/*else if(name == "STOR") {
        processStor(static_cast<StorRequest&> request, client);
    } else if(name == "QUIT") {
        processQuit(static_cast<QuitRequest&> request, client);
    } else if(name == "PWD") {
        processPwd(static_cast<PwdRequest&> request, client);
    }  else if(name == "CDUP") {
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
		if(client->getUser().getPassword() == "_") { // User without password
			AnswerLoginOk answer;
			answer.addArgument("Welcome "+client->getUser().getUsername());
			answer.generatePacket(p);
		}
		else {
			AnswerUsernameOK answer;
			answer.addArgument("Require password");
			answer.generatePacket(p);
		}
	}

	client->getSocket().send(p);
}

void RequestHandler::processPass(PassRequest& request, Client* client) {
	Packet p;

	if(client->login(request.getPassword())) {
		AnswerLoginOk answer;
		answer.addArgument("Welcome "+client->getUser().getUsername());
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

	if(client->openActiveConnection(IP::Address(request.getAddress()), request.getPort())) {
		AnswerDataConnectionOpen answer;
		answer.addArgument("Data connection open");
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
	try {
		Directory directory;

		directory.open(client->getUser().getHomeDir()+client->getCurrentDirectory());


		std::vector<Directory::Entry> entries;

		directory.list(entries);

		Packet p_data;

		for(auto it=entries.begin(); it != entries.end(); ++it) {
			if(it->name != "." && it->name  != "..")
                p_data << it->permission << " " << "1" << " " <<  "owner" << " " << "group" << " " << std::to_string(it->size) << " " << "Dec" << " " << "25" << " " << "16:23" << " " << it->name << "\n\0";
		}

		std::cout << "Send=[" << p_data << "]" << std::endl;

		client->getActiveDataSocket().send(p_data);

		//client->getDataSocket().close();
sleep(1);
		AnswerTransfertSuccess answer;
		answer.addArgument("Data sended successfully");
		answer.generatePacket(p);
	}
	catch(SystemException& e) {
		AnswerFileUnavailable answer;
		answer.addArgument("Unable to read \""+client->getCurrentDirectory()+"\"");
		answer.generatePacket(p);
	}
	client->getSocket().send(p);
}


void RequestHandler::processRetr(RetrRequest& request, Client* client) {
	Packet p;

	std::string filename = client->getCurrentDirectory()+request.getFilename();

	std::ifstream file(filename, std::ios::in);

	if(!file) {
		AnswerFileUnavailable answer;
		answer.generatePacket(p);
		client->getSocket().send(p);
	}
	else {
		file.seekg(0, file.end);
		unsigned int size = file.tellg();
		file.seekg(0, file.beg);

		char* buffer = new char[size];
		file.read(buffer, size);
		p.rawWrite(buffer, size);
		delete buffer;
		client->getActiveDataSocket().send(p);

		Packet p2;

		AnswerTransfertSuccess answer2;
		answer2.generatePacket(p2);
		client->getSocket().send(p2);
	}
}

void RequestHandler::processSyst(SystRequest& request, Client* client) {
	Packet p;
	std::string sys_name(FURETTP_SYST_NAME);
	std::transform(sys_name.begin(), sys_name.end(),sys_name.begin(), ::toupper);

	AnswerSystemName answer(sys_name);
	answer.addArgument("Type: L8");

	answer.generatePacket(p);
	client->getSocket().send(p);
}

void RequestHandler::processFeat(FeatRequest& request, Client* client) {
	Packet p;

	AnswerSystemStatus answer;

	answer.addArgument("Extensions supported:");
	answer.generatePacket(p);
	client->getSocket().send(p);
}

void RequestHandler::processPwd(PwdRequest& request, Client* client) {
	Packet p;

	AnswerPathnameCreated answer("\""+client->getCurrentDirectory()+"\"");
	answer.generatePacket(p);
	client->getSocket().send(p);
}

void RequestHandler::processType(TypeRequest& request, Client* client) {
	Packet p;

	AnswerSuccess answer;
	answer.addArgument("Type changed");
	answer.generatePacket(p);
	client->getSocket().send(p);
}

void RequestHandler::processPasv(PasvRequest& request, Client* client) {
	Packet p;

	client->switchPassiveMode();

	AnswerEnteringPassiveMode answer;
	answer.addArgument("Entering Passive Mode (127,0,0,1,"+std::to_string((client->getPassiveDataSocket().getPort() >> 8) & 0xFF)+","+std::to_string(client->getPassiveDataSocket().getPort() & 0xFF)+").");
	answer.generatePacket(p);
	client->getSocket().send(p);
}

void RequestHandler::processCwd(CWDRequest &request, Client* client) {
    Packet p;
    const std::string directory_path = request.getDirectory();

    if(directory_path.compare(0, 1, "/") == 0) {
        try {
            Directory directory;
            directory.open(client->getUser().getHomeDir()+directory_path);
            client->setCurrentDirectory(directory_path);
            AnswerSuccess answer;
            answer.generatePacket(p);
        } catch(SystemException& e) {
            AnswerFileUnavailable answer;
            answer.addArgument("Unable to access to \""+client->getCurrentDirectory()+"\"");
            answer.generatePacket(p);
        }
    } else {
        AnswerFileUnavailable answer;
        answer.addArgument("Unable to access to \""+directory_path+"\"");
        answer.generatePacket(p);
    }

    client->getSocket().send(p);
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

void RequestHandler::processCdup(CdupRequest &request, Client &client) {
    // TODO
}
*/
