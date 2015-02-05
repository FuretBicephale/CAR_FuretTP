#include <gtest/gtest.h>

#define OK 200

namespace {

    class TestFTPCommands : public ::testing::Test {
    private:

        TestFTPCommands() {
            FTPServer server = new FTPServer("127.0.0.1", 2121);
            FTPClient client = new FTPClient();
        }

        virtual ~TestFTPCommands() {
            delete server;
            delete client;
        }

    };

    TEST_F(TestFTPCommands, testAUTH) {
        client.send("USER", "toto");
        ASSERT_EQ(client.getReturnCode(), OK);
        client.send("PASS", "12345");
        ASSERT_EQ(client.getReturnCode(), OK);
        ASSERT_EQ(client.getMessage(), "connected");
    }

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

}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
