#pragma once
#include "Festival.h"

class Artist : public Festival {
public:
	Artist();
	Artist(string name, string date, string place,
		int numberOfSeatsAvailable, int numberOfSeatsSold);
	Artist(const Artist& artist);
	~Artist();

	Artist& operator=(const Artist& artist);
	bool operator==(const Artist& artist);

	Festival* clone();
	string toString(string delim);
};
