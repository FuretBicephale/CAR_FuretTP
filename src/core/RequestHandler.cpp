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
	}
	/*else if(name == "STOR") {
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

	client->setNextActiveConnection(request.getAddress(), request.getPort());

	AnswerSuccess answer;
	answer.addArgument("Data connection register");
	answer.generatePacket(p);

	client->getSocket().send(p);
}

void RequestHandler::processList(ListRequest& request, Client* client) {
	Packet p, p2;
	try {

		AnswerFileStatusOK answer;
		answer.addArgument("Opening ASCII mode data connection");
		answer.generatePacket(p2);
		client->getSocket().send(p2);

		Directory directory;

		directory.open(client->getUser().getHomeDir()+client->getCurrentDirectory());


		std::vector<Directory::Entry> entries;

		directory.list(entries);

		Packet p_data;

		for(auto it=entries.begin(); it != entries.end(); ++it) {
			if(it->name != "." && it->name  != "..")
				p_data << it->permission << " " << "1" << " " <<  client->getUser().getUsername() << " " << std::to_string(it->size) << " " << it->lastModification << " " << it->name << "\r\n";
		}

		client->openActiveConnection();
		client->getActiveDataSocket().send(p_data);
		client->closeActiveConnection();

		AnswerTransfertSuccess answer2;
		answer2.addArgument("Data sended successfully");
		answer2.generatePacket(p);
	}
	catch(SystemException& e) {
		AnswerFileUnavailable answer;
		answer.addArgument("Unable to read \""+client->getCurrentDirectory()+"\"");
		answer.generatePacket(p);
	}
	client->getSocket().send(p);
}


void RequestHandler::processRetr(RetrRequest& request, Client* client) {
	Packet p, p2;

	std::string filename = client->getUser().getHomeDir()+request.getFilename();

	std::ifstream file(filename, std::ios::in);

	if(!file) {
		AnswerFileUnavailable answer;
		answer.addArgument("File not found \""+request.getFilename()+"\"");
		answer.generatePacket(p);
		client->getSocket().send(p);
	}
	else {
		AnswerFileStatusOK answer;
		answer.addArgument("Opening ASCII mode data connection");
		answer.generatePacket(p);
		client->getSocket().send(p);

		file.seekg(0, file.end);
		unsigned int size = file.tellg();
		file.seekg(0, file.beg);

		Packet p_data;

		char* buffer = new char[size];
		file.read(buffer, size);
		p_data.rawWrite(buffer, size);
		delete buffer;

		client->openActiveConnection();
		client->getActiveDataSocket().send(p_data);
		client->closeActiveConnection();

		AnswerTransfertSuccess answer2;
		answer2.addArgument("Data sended successfully");
		answer2.generatePacket(p2);
		client->getSocket().send(p2);
	}
}

void RequestHandler::processStor(StorRequest& request, Client* client) {
	Packet p, p2;

	std::string filename = client->getUser().getHomeDir()+request.getFilename();

	std::ofstream file(filename, std::ios::out | std::ios::trunc);

	if(!file) {
		AnswerFileUnavailable answer;
		answer.addArgument("Unable to open \""+request.getFilename()+"\"");
		answer.generatePacket(p);
		client->getSocket().send(p);
	}
	else {
		AnswerFileStatusOK answer;
		answer.addArgument("Opening ASCII mode data connection");
		answer.generatePacket(p);
		client->getSocket().send(p);

		client->openActiveConnection();

		Packet packet_data;
		client->getActiveDataSocket().receive(packet_data);
		file.write(packet_data.getBuffer(), packet_data.getSize());
		client->closeActiveConnection();

		AnswerTransfertSuccess answer2;
		answer2.addArgument("Data sended successfully");
		answer2.generatePacket(p2);
		client->getSocket().send(p2);
	}
}

void RequestHandler::processSyst(SystRequest& request, Client* client) {
	Packet p;
	std::string sys_name("UNIX"/*FURETTP_SYST_NAME*/);
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
