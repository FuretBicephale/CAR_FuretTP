#include <gtest/gtest.h>
#include <core/FTPServer.h>

using namespace FTP;

namespace {

	class TestException : public ::testing::Test {

	};

}

TEST_F(TestException, testPortParsing) {
	Packet packet;
	packet << "PORT 127,0,0,1,23,23";

	Request* request;
	ASSERT_NO_THROW(request = RequestFactory::eval(packet));

	ASSERT_EQ(23*256+23, static_cast<PortRequest*>(request)->getPort());

	delete request;
}


TEST_F(TestException, testPortNaN) {
	Packet packet;
	packet << "PORT a,b,c,d,e,f";

	ASSERT_THROW(RequestFactory::eval(packet), UnrecognizedMessageException);
}

TEST_F(TestException, testPortTooMuchNumber) {
	Packet packet;
	packet << "PORT 127,0,0,1,23,23,0";

	ASSERT_THROW(RequestFactory::eval(packet), UnrecognizedMessageException);
}

TEST_F(TestException, testPortNoEnoughNumber) {
	Packet packet;
	packet << "PORT 127,0,0,1,23";

	ASSERT_THROW(RequestFactory::eval(packet), UnrecognizedMessageException);
}

TEST_F(TestException, testTypeParing) {
	Packet packet;
	packet << "TYPE I";

	Request* request;
	ASSERT_NO_THROW(request = RequestFactory::eval(packet));

	ASSERT_EQ(TypeRequest::Image, static_cast<TypeRequest*>(request)->getType());
}

TEST_F(TestException, testTypeUnknwon) {
	Packet packet;
	packet << "TYPE Z";

	ASSERT_THROW(RequestFactory::eval(packet), UnrecognizedMessageException);
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
