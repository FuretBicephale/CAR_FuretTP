#include <gtest/gtest.h>
#include <core/FTPServer.h>

using namespace FTP;

namespace {

class TestFTPCommands : public ::testing::Test {

public:
    TestFTPCommands() {
		_configuration = new  ServerConfiguration();
		_configuration->setBindPort(++currentPort);

		_server = new FTPServer(*_configuration);
		_thread = new Thread<FTPServer>(_server);

		_thread->run();

    }

	virtual  ~TestFTPCommands() {
		_server->close();

		delete _configuration;
		delete _server;
		delete _thread;
	}


	Thread<FTPServer>* _thread;
	FTPServer* _server;
	ServerConfiguration* _configuration;

	static unsigned int currentPort;

};

unsigned int TestFTPCommands::currentPort =  4242;

class FTPClient {

public:
	FTPClient() {

	}

	Packet initializeConnection(unsigned int port) {
		_socket.connect(IP::Address("127.0.0.1"), port);

		Packet packet;
		_socket.receive(packet);

		return packet;
	}

	Packet commandeUser(const std::string& username) {
		Packet packet_user;
		packet_user << "USER" << " " << "falezp";
		_socket.send(packet_user);

		Packet packet_answer_user;
		_socket.receive(packet_answer_user);

		return packet_answer_user;
	}

private:
	TCP::Socket _socket;
};

TEST_F(TestFTPCommands, testConnection) {

	FTPClient client;

	Packet packet = client.initializeConnection(currentPort);

	std::string packet_answer_code;
	packet >> packet_answer_code;
	ASSERT_EQ(std::to_string(AnswerSuccess::Code), packet_answer_code);

	sleep(1);
}

TEST_F(TestFTPCommands, testAUTH) {

	FTPClient client;

	client.initializeConnection(currentPort);
	Packet packet_user = client.commandeUser("falezp");


	std::string packet_answer_user_code;
	packet_user >> packet_answer_user_code;
	ASSERT_EQ(std::to_string(AnswerUsernameOK::Code), packet_answer_user_code);

	usleep(100);
}
/*
TEST_F(TestFTPCommands, testLIST) {
    client.send("LIST");
    ASSERT_EQ(client.getAnswer(), OK);
}

TEST_F(TestFTPCommands, testRETR) {
    client.send("RETR", "toto.txt");
    ASSERT_EQ(client.getAnswer(), OK);
}

TEST_F(TestFTPCommands, testSTOR) {
    client.send("STOR", "toto.txt");
    ASSERT_EQ(client.getAnswer(), OK);
}

TEST_F(TestFTPCommands, testQUIT) {
    client.send("QUIT");
    ASSERT_EQ(client.getAnswer(), OK);
}

TEST_F(TestFTPCommands, testPWD) {
    client.send("PWD");
    ASSERT_EQ(client.getAnswer(), OK);
}

TEST_F(TestFTPCommands, testCWD) {
    client.send("CWD", "toto");
    ASSERT_EQ(client.getAnswer(), OK);
}

TEST_F(TestFTPCommands, testCDUP) {
    client.send("CDUP");
    ASSERT_EQ(client.getAnswer(), OK);
}

TEST_F(TestFTPCommands, testCDUP) {
    ASSERT_TRUE(true);
}
*/
}



int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


