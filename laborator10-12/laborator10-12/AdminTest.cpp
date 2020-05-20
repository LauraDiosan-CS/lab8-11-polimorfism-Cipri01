#include "AdminTest.h"
#include <assert.h>

void AdminTest::testAll() {
	this->testImplicitConstructor();
	this->testConstructorWithParameters();
	this->testCopyConstructor();
	this->testGetUserName();
	this->testSetUserName();
	this->testGetPassWord();
	this->testSetPassWord();
	this->testAssignmentOperator();
	this->testEqualityOperator();
	this->testToString();
}

void AdminTest::testImplicitConstructor() {
	Admin admin;

	assert(admin.getUserName().compare("") == 0);
	assert(admin.getPassWord().compare("") == 0);
}

void AdminTest::testConstructorWithParameters() {
	Admin admin("ana123", "12345");

	assert(admin.getUserName().compare("ana123") == 0);
	assert(admin.getPassWord().compare("12345") == 0);
}

void AdminTest::testCopyConstructor() {
	Admin admin("ana123", "12345");
	Admin admin02(admin);

	assert(admin02.getUserName().compare(admin.getUserName()) == 0);
	assert(admin02.getPassWord().compare(admin.getPassWord()) == 0);
}

void AdminTest::testGetUserName() {
	Admin admin("cipri18", "19345");

	assert(admin.getUserName().compare("cipri18") == 0);
}

void AdminTest::testSetUserName() {
	Admin admin("cipri18", "19345");

	admin.setUserName("calin18");

	assert(admin.getUserName().compare("calin18") == 0);
}

void AdminTest::testGetPassWord() {
	Admin admin("cipri18", "19345");

	assert(admin.getPassWord().compare("19345") == 0);
}

void AdminTest::testSetPassWord() {
	Admin admin("cipri18", "19345");

	admin.setPassWord("12345");

	assert(admin.getPassWord().compare("12345") == 0);
}

void AdminTest::testAssignmentOperator() {
	Admin admin("ana123", "12345");
	Admin admin02 = admin;

	assert(admin02.getUserName().compare(admin.getUserName()) == 0);
	assert(admin02.getPassWord().compare(admin.getPassWord()) == 0);
}

void AdminTest::testEqualityOperator() {
	Admin admin("ana123", "12345");
	Admin admin02 = admin;

	assert(admin == admin02);
}

void AdminTest::testToString() {
	Admin admin("cipri123", "123456");
	string toString = admin.toString(" ");

	assert(toString == "ADMIN cipri123 123456");

	cout << "TEST for Admin class DONE!" << endl;
}
