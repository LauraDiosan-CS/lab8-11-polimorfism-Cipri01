#include "Admin.h"

Admin::Admin() {
	this->userName = "";
	this->passWord = "";
}

Admin::Admin(string userName, string passWord) {
	this->userName = userName;
	this->passWord = passWord;
}

Admin::Admin(const Admin& admin) {
	this->userName = admin.userName;
	this->passWord = admin.passWord;
}

Admin::~Admin() {}

string Admin::getUserName() {
	return this->userName;
}

string Admin::getPassWord() {
	return this->passWord;
}

void Admin::setUserName(string newUserName) {
	this->userName = newUserName;
}

void Admin::setPassWord(string newPassWord) {
	this->passWord = newPassWord;
}

Admin& Admin::operator=(const Admin& admin) {
	if (this != &admin) {
		this->userName = admin.userName;
		this->passWord = admin.passWord;
	}
	return *this;
}

bool Admin::operator==(const Admin& admin) {
	return (this->userName.compare(admin.userName) == 0
		&& this->passWord.compare(admin.passWord) == 0);
}

string Admin::toString(string delim) {
	return "ADMIN" + delim + this->userName + delim + this->passWord;
}
