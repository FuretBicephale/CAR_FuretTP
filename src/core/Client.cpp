#include "core/Client.h"
#include "core/FTPServer.h"

using namespace FTP;

unsigned int Client::_uidCounter(0);

Client::Client(FTPServer* server, TCP::Socket& socket) : _uid(_uidCounter++), _socket(std::move(socket)), _server(server), _user(), _currrentDirectory("/"),
    _inPassiveMode(false), _activeDataSocket(), _passiveDataSocket(), _isOpen(true) {

}

void Client::run() {
    std::cout << "New client connected width id=" << _uid << " [" << _socket.getAddress() << "]" << std::endl;

    Packet packet;

    AnswerSuccess answer;
    answer.addArgument(_server->getConfiguration().getMOTD());
    answer.generatePacket(packet);

    std::cout << packet << std::endl;

    _socket.send(packet);


	while(_socket.isOpen() && _isOpen) { // While the socket is open and the client is running
        Packet packet;

		_socket.receive(packet); // receive next packet

        std::cout << "Received buffer (" << packet.getSize() << ")" << std::endl;
        std::cout <<  packet << std::endl;

		Request* message = RequestFactory::eval(packet); //Send apcket to factory for create a structured message

		if(message != nullptr) {
			RequestHandler::process(*message, this); //process message
			delete message;
        }
		else { //if message is unrecognized, then send Answer to client with unimplemented command content
            Packet answer_packet;

            AnswerUnimplemented answer;
            answer.addArgument("Uninplemented command");
            answer.generatePacket(answer_packet);

            _socket.send(answer_packet);
        }
    }

    _socket.close();
    _activeDataSocket.close();
    _passiveDataListener.close();
    _passiveDataSocket.close();

    std::cout << "[Client " << _uid << "] Disconnected " << std::endl;
}
bool Client::setUsername(const std::string& username) {
    if(_server->getConfiguration().getUserList().hasUser(username)) {
        _user = User(_server->getConfiguration().getUserList().findUser(username));
        return true;
    }

    return false;
}

bool Client::login(const std::string& password) {
    if(password == _user.getPassword()) {
        return true;
    }
    return false;
}

void Client::resetLogin() {
    _user = User();
}

void Client::openDataConnection() {
	if(_inPassiveMode) { // if client is currently in passive mode
        _passiveDataSocket.close();
		_passiveDataListener.accept(_passiveDataSocket); // then wait client connection
        std::cout << "[Client " << _uid << "] Accept new passive data connection" << std::endl;
    }
    else {
		if(_nextActivePort == 0) // if client don't specified data socket address with a PORT command
            THROW(NoActiveConnectionException, "");
        _activeDataSocket.close();
		_activeDataSocket.connect(_nextActiveAddress, _nextActivePort); // then connect to the address:port specified in last command PORT
        std::cout << "[Client " << _uid << "] Open new active data connection (" << _nextActiveAddress << ":" << _nextActivePort << ") " << std::endl;
    }
}

void Client::sendToDataConnection(const Packet& packet) {
    if(_inPassiveMode) {
        _passiveDataSocket.send(packet);
    } else {
        _activeDataSocket.send(packet);
    }
}

void Client::receiveFromDataConnection(Packet& packet) {
    if(_inPassiveMode) {
        _passiveDataSocket.receive(packet);
    } else {
        _activeDataSocket.receive(packet);
    }
}

void Client::closeDataConnection() {
    if(_inPassiveMode) {
        _passiveDataSocket.close();
    } else {
        _activeDataSocket.close();
    }
}

void Client::setNextActiveConnection(const IP::Address& address, unsigned int port) {
    _nextActiveAddress = address;
    _nextActivePort = port;
}

void Client::setCurrentDirectory(const std::string& pathname) {
    _currrentDirectory = pathname;
}


void Client::switchPassiveMode() {
    _inPassiveMode = true;

    _passiveDataListener.close();
    _passiveDataListener.listen();
}

void Client::close() {
    _isOpen = false;
}

const User& Client::getUser() const {
    return _user;
}

const std::string& Client::getCurrentDirectory() const {
    return _currrentDirectory;
}

TCP::Socket& Client::getSocket() {
    return _socket;
}

TCP::Listener& Client::getPassiveDataListener() {
    return _passiveDataListener;
}
