#pragma once
#include "Admin.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class AdminFile {
private:
	string fileName;
	vector<Admin> listOfAdmins;
public:
	AdminFile();
	AdminFile(string fileName);
	~AdminFile();

	void addAdmin(Admin adminForAdd);
	void deleteAdmin(Admin adminForDelete);

	void saveToFile();
	void loadFromFile();

	int getSize();
	vector<Admin> getAll();

	void setFileName(string fileName);
};
