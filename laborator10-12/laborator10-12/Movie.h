#pragma once
#include "Festival.h"
#include <vector>

class Movie : public Festival {
private:
	vector<string> listOfActors;
public:
	Movie();
	Movie(string name, vector<string> listOfActors, string date, string place,
		int numberOfSeatsAvailable, int numberOfSeatsSold);
	Movie(const Movie& movie);
	~Movie();

	vector<string> getListOfActors();
	void setListOfActors(vector<string> newListOfActors);

	Movie& operator=(const Movie& movie);
	bool operator==(const Movie& movie);

	Festival* clone();
	string toString(string delim);

	bool vectorEqual(vector<string> vector01,
		vector<string> vector02);
	string convertVectorToString(vector<string> vector);
};
