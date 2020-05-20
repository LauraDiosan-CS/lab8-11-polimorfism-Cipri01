#pragma once
#include <string>
#include <iostream>

using namespace std;

class Festival {
protected:
	string name;
	string date;
	string place;
	int numberOfSeatsAvailable;
	int numberOfSeatsSold;
public:
	Festival();
	Festival(string name, string date, string place,
		int numberOfSeatsAvailable, int numberOfSeatsSold);
	Festival(const Festival& festival);
	~Festival();

	string getName();
	string getDate();
	string getPlace();
	int getNumberOfSeatsAvailable();
	int getNumberOfSeatsSold();

	void setName(string newName);
	void setDate(string newDate);
	void setPlace(string newPlace);
	void setNumberOfSeatsAvailable(int newNumberOfSeatsAvailable);
	void setNumberOfSeatsSold(int newNumberOfSeatsSold);

	Festival& operator=(const Festival& festival);
	bool operator==(const Festival& festival);

	virtual Festival* clone() = 0;
	virtual string toString(string delim) = 0;
};
