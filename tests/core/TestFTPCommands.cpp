#include <QtTest/QtTest>

#define OK 200

class TestFTPRequest: public QObject
{
	Q_OBJECT

private slots:
	void initTestCase();
	void testAUTH();
	void testLIST();
	void testRETR();
	void testSTOR();
	void testSTOR();
	void testQUIT();
	void testPWD();
	void testCWD();
	void testCDUP();
};

void TestFTPRequest::initTestCase() {
	FTPServer serveur = new FTPServer("127.0.0.1", 2121);
	FTPClient client = new FTPClient();
}

void TestFTPRequest::testAUTH() {
	client.send("USER", "toto");
	QCOMPARE(client.getReturnCode(), OK);
	client.send("PASS", "12345");
	QCOMPARE(client.getReturnCode(), OK);
	QCOMPARE(client.getMessage(), "connected");
}

void TestFTPRequest::testLIST() {
	client.send("LIST");
	QCOMPARE(client.getAnswer(), OK);
}

void TestFTPRequest::testRETR() {
	client.send("RETR", "toto.txt");
	QCOMPARE(client.getAnswer(), OK);
}

void TestFTPRequest::testSTOR() {
	client.send("STOR", "toto.txt");
	QCOMPARE(client.getAnswer(), OK);
}

void TestFTPRequest::testQUIT() {
	client.send("QUIT");
	QCOMPARE(client.getAnswer(), OK);
}

void TestFTPRequest::testPWD() {
	client.send("PWD");
	QCOMPARE(client.getAnswer(), OK);
	
}

void TestFTPRequest::testCWD() {
	client.send("CWD", "toto");
	QCOMPARE(client.getAnswer(), OK);
}

void TestFTPRequest::testCDUP() {
	client.send("CDUP");
	QCOMPARE(client.getAnswer(), OK);
}

QTEST_MAIN(TestFTPRequest)
#include "testftprequest.moc"