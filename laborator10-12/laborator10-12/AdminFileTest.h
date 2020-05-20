#pragma once
#include "Admin.h"
#include "AdminFile.h"

class AdminFileTest {
private:
	string fileNameIn = "TestAdminsIn.txt";
	string fileNameOut = "TestAdminsOut.txt";

	vector<Admin> admins;

	void testAdd();
	void testDelete();
	void testGetSize();
	void testGetAll();

	void testLoadFromFile();
	void testSaveToFile();
public:
	AdminFileTest();
	~AdminFileTest();

	void testAll();
};
