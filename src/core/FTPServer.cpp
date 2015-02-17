#include "core/FTPServer.h"

using namespace FTP;

FTPServer::FTPServer(const ServerConfiguration& configuration) :  _configuration(configuration), _listener() {

}

void FTPServer::run() {

    _listener.listen(_configuration.getBindPort());

    std::cout << "Listen connection on port " << _configuration.getBindPort() << std::endl;

    while(_listener.isOpen()) {
        TCP::Socket client;
		_listener.accept(client); // accept next client

		Thread<Client> thread(new Client(this, client)); // open a new thread for handle the client connection
		thread.run(); // run client thread
    }

}

void FTPServer::close() {
    _listener.close();
}

const ServerConfiguration& FTPServer::getConfiguration() const {
    return _configuration;
}
