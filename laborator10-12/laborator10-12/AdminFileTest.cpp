#include "AdminFileTest.h"
#include <assert.h>

void AdminFileTest::testAdd() {
	AdminFile adminFile;

	Admin admin("ana", "12345");

	adminFile.addAdmin(admin);

	assert(adminFile.getSize() == 1);
	assert(adminFile.getAll()[0] == admin);
}

void AdminFileTest::testDelete() {
	AdminFile adminFile;

	Admin admin("ana", "12345");

	adminFile.addAdmin(admin);

	assert(adminFile.getSize() == 1);

	adminFile.deleteAdmin(admin);

	assert(adminFile.getSize() == 0);
}

void AdminFileTest::testGetSize() {
	AdminFile adminFile;

	Admin admin01("ana", "1235");
	Admin admin02("maria01", "mar1234");

	adminFile.addAdmin(admin01);
	adminFile.addAdmin(admin02);

	assert(adminFile.getSize() == 2);
}

void AdminFileTest::testGetAll() {
	AdminFile adminFile;

	Admin admin01("ana", "1235");
	Admin admin02("maria01", "mar1234");

	adminFile.addAdmin(admin01);
	adminFile.addAdmin(admin02);

	assert(adminFile.getSize() == 2);
	assert(adminFile.getAll()[0] == admin01);
	assert(adminFile.getAll()[1] == admin02);
}

void AdminFileTest::testLoadFromFile() {
	AdminFile adminFile(this->fileNameIn);
	adminFile.loadFromFile();

	assert(adminFile.getSize() == 3);
	assert(adminFile.getAll()[0] == this->admins[0]);
	assert(adminFile.getAll()[1] == this->admins[1]);
	assert(adminFile.getAll()[2] == this->admins[2]);
}

void AdminFileTest::testSaveToFile() {
	AdminFile adminFile(this->fileNameIn);
	adminFile.loadFromFile();
	adminFile.setFileName(this->fileNameOut);

	Admin admin("cipri01", "136257");

	adminFile.addAdmin(admin);

	adminFile.saveToFile();
	adminFile.loadFromFile();

	assert(adminFile.getSize() == 4);
	assert(adminFile.getAll()[0] == this->admins[0]);
	assert(adminFile.getAll()[1] == this->admins[1]);
	assert(adminFile.getAll()[2] == this->admins[2]);
	assert(adminFile.getAll()[3] == admin);

	adminFile.deleteAdmin(admin);

	cout << "TEST fot AdminFile class DONE!" << endl;
}


AdminFileTest::AdminFileTest() {
	Admin admin01("ana", "12345678");
	Admin admin02("maria", "98765432");
	Admin admin03("gabi", "13579246");

	this->admins.push_back(admin01);
	this->admins.push_back(admin02);
	this->admins.push_back(admin03);
}

AdminFileTest::~AdminFileTest() {}

void AdminFileTest::testAll() {
	this->testAdd();
	this->testDelete();
	this->testGetSize();
	this->testGetAll();
	this->testLoadFromFile();
	this->testSaveToFile();
}
