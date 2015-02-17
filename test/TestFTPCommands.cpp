#include <gtest/gtest.h>
#include <core/FTPServer.h>
#include <core/UserConfigurationReader.h>

using namespace FTP;

namespace {

class TestFTPCommands : public ::testing::Test {

public:
    TestFTPCommands() {
        _configuration = new  ServerConfiguration();
        _configuration->setBindPort(++currentPort);

        UserConfigurationReader::process(_configuration->getUserConfigurationPathname(), *_configuration);

        std::cout << "Start server on port " << currentPort << std::endl;

        _server = new FTPServer(*_configuration);
        _thread = new Thread<FTPServer>(_server);

        _thread->run();

        usleep(1e5);

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

    /*
     *	Commande
     */

    Packet initializeConnection(unsigned int port) {
        _socket.connect(IP::Address("127.0.0.1"), port);

        Packet packet;
        _socket.receive(packet);

        return packet;
    }

    Packet commandeUser(const std::string& username) {

        Packet packet;
        packet << "USER" << " " << username;
        _socket.send(packet);

        Packet packet_answer;
        _socket.receive(packet_answer);

        return packet_answer;
    }

    Packet commandePass(const std::string& password) {

        Packet packet;
        packet << "PASS" << " " << password;
        _socket.send(packet);

        Packet packet_answer;
        _socket.receive(packet_answer);

        return packet_answer;
    }

    Packet commandePasv() {

        Packet packet;
        packet << "PASV";
        _socket.send(packet);

        Packet packet_answer;
        _socket.receive(packet_answer);

        return packet_answer;
    }

    /*
     *	Parse Packet
     */

    void parsePasvInfo(std::string str) {
        unsigned int start_index = str.find_first_of("(");
        unsigned int end_index = str.find_last_of(")");

        std::string raw_address = str.substr(start_index, end_index-start_index);

        char* c_raw_addr = new char[raw_address.size()+1];

        strcpy(c_raw_addr, raw_address.c_str());

        char* token = strtok(c_raw_addr, ",");
        unsigned int i;

        std::string address;
        unsigned int port = 0;
        for(i=0; token != nullptr; i++) {

            int factor = 1;
            char* end_nb;

            switch(i) {
            case 0:
                address = token;
                break;
            case 1:
            case 2:
            case 3:
                address += "."+std::string(token);
                break;
            case 4:
                factor = 256;
            case 5:
            {
                int nb = strtol(token, &end_nb, 10);

                if(token == end_nb) {
                    delete c_raw_addr;
                    //THROW(UnrecognizedMessageException, "PASV "+raw_address, std::string(token)+" is an incorrecte number");
                }
                port += factor*nb;
            }
                break;
            default:
                delete c_raw_addr;
                //THROW(UnrecognizedMessageException, "PASV "+raw_address, "too many arguments");
            }

            token = strtok(NULL, ",");
        }
        delete c_raw_addr;
        /*if(i != 6)
            THROW(UnrecognizedMessageException, "PORT "+raw_address, "no enough argument");*/

        std::cout << "Address=" << address << ", port=" << port << std::endl;
        _dataAddress = IP::Address(address);
        _dataPort = port;
    }

    Packet commande(const std::string& commandName, const std::vector<std::string>& parameters = std::vector<std::string>()) {

        Packet packet;
        packet << commandName;

        for(auto parameter: parameters) {
            packet << " " << parameter;
        }

        _socket.send(packet);

        Packet packet_answer;
        _socket.receive(packet_answer);

        return packet_answer;

    }

private:
    TCP::Socket _socket;

    IP::Address _dataAddress;
    unsigned int _dataPort;
};

TEST_F(TestFTPCommands, testConnection) {
    FTPClient client;

    Packet packet = client.initializeConnection(currentPort);

    std::string packet_answer_code;
    packet >> packet_answer_code;
    ASSERT_EQ(std::to_string(AnswerSuccess::Code), packet_answer_code);
}

TEST_F(TestFTPCommands, testUser) {
    FTPClient client;

    client.initializeConnection(currentPort);
    Packet packet_user = client.commandeUser("falezp");

    std::string packet_answer_user_code;
    packet_user >> packet_answer_user_code;
    ASSERT_EQ(std::to_string(AnswerUsernameOK::Code), packet_answer_user_code);
}

TEST_F(TestFTPCommands, testPass) {
    FTPClient client;

    client.initializeConnection(currentPort);
    client.commandeUser("falezp");
    Packet packet_pass = client.commandePass("mdp1");

    std::string packet_answer_pass_code;
    packet_pass >> packet_answer_pass_code;
    ASSERT_EQ(std::to_string(AnswerLoginOk::Code), packet_answer_pass_code);
}

TEST_F(TestFTPCommands, testPasv) {
    FTPClient client;

    client.initializeConnection(currentPort);
    client.commandeUser("falezp");
    client.commandePass("mdp1");
    Packet packet_pasv = client.commandePasv();

    std::string packet_answer_pasv_code;
    packet_pasv >> packet_answer_pasv_code;
    ASSERT_EQ(std::to_string(AnswerEnteringPassiveMode::Code), packet_answer_pasv_code);

    client.parsePasvInfo(std::string(packet_pasv.getBuffer(), packet_pasv.getSize()));
}


TEST_F(TestFTPCommands, testPWD) {
    FTPClient client;

    client.initializeConnection(currentPort);
    Packet packet_answer = client.commande("PWD");

    std::string packet_answer_code;
    packet_answer >> packet_answer_code;
    ASSERT_EQ(std::to_string(AnswerPathnameCreated::Code), packet_answer_code);

}

TEST_F(TestFTPCommands, testCWD) {
    FTPClient client;
    const std::vector<std::string> directoryRelative(1, "home");

    client.initializeConnection(currentPort);
    Packet packet_answer_relative = client.commande("CWD", directoryRelative);

    std::string packet_answer_code;
    packet_answer_relative >> packet_answer_code;
    ASSERT_EQ(std::to_string(AnswerSuccess::Code), packet_answer_code);

    const std::vector<std::string> directoryAbsolute(1, "/home");

    client.initializeConnection(currentPort);
    Packet packet_answer_absolute = client.commande("CWD", directoryAbsolute);

    packet_answer_absolute >> packet_answer_code;
    ASSERT_EQ(std::to_string(AnswerSuccess::Code), packet_answer_code);

    const std::vector<std::string> directoryRelative2(1, ".");

    client.initializeConnection(currentPort);
    Packet packet_answer_relative2 = client.commande("CWD", directoryRelative2);

    packet_answer_relative2 >> packet_answer_code;
    ASSERT_EQ(std::to_string(AnswerSuccess::Code), packet_answer_code);

    const std::vector<std::string> directoryRelative3(1, "..");

    client.initializeConnection(currentPort);
    Packet packet_answer_relative3 = client.commande("CWD", directoryRelative3);

    packet_answer_relative3 >> packet_answer_code;
    ASSERT_EQ(std::to_string(AnswerSuccess::Code), packet_answer_code);

}

TEST_F(TestFTPCommands, testCWDFailure) {
    FTPClient client;
    const std::vector<std::string> directoryUnknown(1, "unknown");

    client.initializeConnection(currentPort);
    Packet packet_answer_uknown = client.commande("CWD", directoryUnknown);

    std::string packet_answer_code;
    packet_answer_uknown >> packet_answer_code;
    ASSERT_EQ(std::to_string(AnswerFileUnavailable::Code), packet_answer_code);

    const std::vector<std::string> directoryForbidden(1, "root");

    client.initializeConnection(currentPort);
    Packet packet_answer_forbidden = client.commande("CWD", directoryForbidden);

    packet_answer_forbidden >> packet_answer_code;
    ASSERT_EQ(std::to_string(AnswerFileUnavailable::Code), packet_answer_code);

}

TEST_F(TestFTPCommands, testCDUP) {
    FTPClient client;
    const std::vector<std::string> directory(1, "/home");

    client.initializeConnection(currentPort);
    client.commande("CWD", directory);
    Packet packet_answer = client.commande("CDUP");

    std::string packet_answer_code;
    packet_answer >> packet_answer_code;
    ASSERT_EQ(std::to_string(AnswerSuccess::Code), packet_answer_code);

}

TEST_F(TestFTPCommands, testQUIT) {
    FTPClient client;

    client.initializeConnection(currentPort);
    Packet packet_answer = client.commande("QUIT");

    std::string packet_answer_code;
    packet_answer >> packet_answer_code;
    ASSERT_EQ(std::to_string(AnswerServerCloseConnection::Code), packet_answer_code);
}

TEST_F(TestFTPCommands, testMkd) {
    FTPClient client;
    const std::vector<std::string> directory(1, "test");

    client.initializeConnection(currentPort);
    client.commandeUser("cacheran");
    client.commandePass("mdp2");
    Packet packet_answer = client.commande("MKD", directory);

    std::string packet_answer_code;
    packet_answer >> packet_answer_code;
    ASSERT_EQ(std::to_string(AnswerPathnameCreated::Code), packet_answer_code);
}

TEST_F(TestFTPCommands, testMkdFailure) {
    FTPClient client;
    const std::vector<std::string> directoryForbidden(1, "test");

    client.initializeConnection(currentPort);
    Packet packet_answer_forbidden = client.commande("MKD", directoryForbidden);

    std::string packet_answer_code;
    packet_answer_forbidden >> packet_answer_code;
    ASSERT_EQ(std::to_string(AnswerAuthRequired::Code), packet_answer_code);

    const std::vector<std::string> directoryUnknown(1, "unknown/test");

    client.initializeConnection(currentPort);
    client.commandeUser("cacheran");
    client.commandePass("mdp2");
    Packet packet_answer_unknown = client.commande("MKD", directoryUnknown);

    packet_answer_unknown >> packet_answer_code;
    ASSERT_EQ(std::to_string(AnswerFileUnavailable::Code), packet_answer_code);
}

TEST_F(TestFTPCommands, testRmd) {
    FTPClient client;
    const std::vector<std::string> directory(1, "test");

    client.initializeConnection(currentPort);
    client.commandeUser("cacheran");
    client.commandePass("mdp2");
    Packet packet_answer = client.commande("RMD", directory);

    std::string packet_answer_code;
    packet_answer >> packet_answer_code;
    ASSERT_EQ(std::to_string(AnswerPathnameCreated::Code), packet_answer_code);
}


TEST_F(TestFTPCommands, testRmdFailure) {
    FTPClient client;
    const std::vector<std::string> directoryUnknown(1, "unknown");

    client.initializeConnection(currentPort);
    client.commandeUser("cacheran");
    client.commandePass("mdp2");
    Packet packet_answer_unknown = client.commande("RMD", directoryUnknown);

    std::string packet_answer_code;
    packet_answer_unknown >> packet_answer_code;
    ASSERT_EQ(std::to_string(AnswerFileUnavailable::Code), packet_answer_code);

    const std::vector<std::string> directoryForbidden(1, "test");

    client.initializeConnection(currentPort);
    Packet packet_answer_forbidden = client.commande("RMD", directoryForbidden);

    packet_answer_forbidden >> packet_answer_code;
    ASSERT_EQ(std::to_string(AnswerAuthRequired::Code), packet_answer_code);
}

/* TEST_F(TestFTPCommands, testList) {
    FTPClient client;

    client.initializeConnection(currentPort);
    Packet packet_answer = client.commande("LIST");

    std::string packet_answer_code;
    packet_answer >> packet_answer_code;
    ASSERT_EQ(std::to_string(AnswerFileStatusOK::Code), packet_answer_code);

}*/

/*
TEST_F(TestFTPCommands, testRETR) {
    client.send("RETR", "toto.txt");
    ASSERT_EQ(client.getAnswer(), OK);
}

TEST_F(TestFTPCommands, testSTOR) {
    client.send("STOR", "toto.txt");
    ASSERT_EQ(client.getAnswer(), OK);
}
*/
}



int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


