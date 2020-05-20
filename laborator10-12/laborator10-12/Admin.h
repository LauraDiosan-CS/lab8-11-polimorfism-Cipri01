#pragma once
#include <iostream>
#include <string>

using namespace std;

class Admin {
private:
	string userName;
	string passWord;
public:
	Admin();
	Admin(string userName, string passWord);
	Admin(const Admin& admin);
	~Admin();

	string getUserName();
	string getPassWord();

	void setUserName(string newUserName);
	void setPassWord(string newPassWord);

	Admin& operator=(const Admin& admin);
	bool operator==(const Admin& admin);

	string toString(string delim);
};
