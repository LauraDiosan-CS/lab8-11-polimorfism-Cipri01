#include "AdminFile.h"
#include <fstream>

AdminFile::AdminFile() {
	this->fileName = "";
}

AdminFile::AdminFile(string fileName) {
	this->fileName = fileName;
}

AdminFile::~AdminFile() {}

void AdminFile::addAdmin(Admin adminForAdd) {
	this->loadFromFile();
	this->listOfAdmins.push_back(adminForAdd);
	this->saveToFile();
}

void AdminFile::deleteAdmin(Admin adminForDelete) {
	vector<Admin>::iterator it;
	it = find(this->listOfAdmins.begin(), this->listOfAdmins.end(), adminForDelete);
	if (!(it == this->listOfAdmins.end())) {
		this->listOfAdmins.erase(it);
	}
	this->saveToFile();
}

void AdminFile::saveToFile() {
	ofstream f(this->fileName);
	if (f.is_open()) {
		for (Admin elem : this->listOfAdmins)
			f << elem.toString(" ") << endl;
	}
}

void AdminFile::loadFromFile() {
	ifstream f(this->fileName);
	if (f.is_open()) {
		this->listOfAdmins.clear();
		string line;
		string delim = " ";
		while (getline(f, line)) {
			if (line.substr(0, 5) == "ADMIN") {
				line = line.erase(0, 6);

				int pos = line.find(" ");
				string userName = line.substr(0, pos);
				line = line.erase(0, pos + 1);

				string passWord = line;

				Admin admin(userName, passWord);
				this->listOfAdmins.push_back(admin);
			}
		}
		f.close();
	}
}

int AdminFile::getSize() {
	return this->listOfAdmins.size();
}

vector<Admin> AdminFile::getAll() {
	return this->listOfAdmins;
}

void AdminFile::setFileName(string fileName) {
	this->fileName = fileName;
}
