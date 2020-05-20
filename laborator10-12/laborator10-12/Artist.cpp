#include "Artist.h"

Artist::Artist() : Festival() {}

Artist::Artist(string name, string date, string place, int numberOfSeatsAvailable, int numberOfSeatsSold) :
	Festival(name, date, place, numberOfSeatsAvailable, numberOfSeatsSold) {}


Artist::Artist(const Artist& artist) : Festival(artist) {}

Artist::~Artist() {}

Artist& Artist::operator=(const Artist& artist) {
	Festival::operator=(artist);
	return *this;
}

bool Artist::operator==(const Artist& artist) {
	return Festival::operator==(artist);
}

Festival* Artist::clone()
{
	return new Artist(this->name, this->date, this->place,
		this->numberOfSeatsAvailable, this->numberOfSeatsSold);
}

string Artist::toString(string delim) {
	return "SHOW" + delim + this->name + "*" + delim + this->date + delim + this->place + "*" + delim +
		std::to_string(this->numberOfSeatsAvailable) + delim + std::to_string(this->numberOfSeatsSold);
}
