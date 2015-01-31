#include "core/FTPServer.h"

using namespace FuretTP;

FTPServer::FTPServer(const FTPServerConfiguration& configuration) :  _configuration(configuration) {

}

void FTPServer::run() {

	TCP::Listener listener;

	listener.listen(_configuration.getBindPort());

	std::cout << "Listen connection on port " << _configuration.getBindPort() << std::endl;

	while(true) {
		TCP::Socket client;
		listener.accept(client);

		Thread<Client> thread(new Client(this, client));
		thread.run();


	}

}
