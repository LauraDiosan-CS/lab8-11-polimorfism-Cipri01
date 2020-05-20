#include "Festival.h"

Festival::Festival() {
	this->name = "";
	this->date = "";
	this->place = "";
	this->numberOfSeatsAvailable = 0;
	this->numberOfSeatsSold = 0;
}

Festival::Festival(string name, string date, string place, int numberOfSeatsAvailable, int numberOfSeatsSold) {
	this->name = name;
	this->date = date;
	this->place = place;
	this->numberOfSeatsAvailable = numberOfSeatsAvailable;
	this->numberOfSeatsSold = numberOfSeatsSold;
}

Festival::Festival(const Festival& festival) {
	this->name = festival.name;
	this->date = festival.date;
	this->place = festival.place;
	this->numberOfSeatsAvailable = festival.numberOfSeatsAvailable;
	this->numberOfSeatsSold = festival.numberOfSeatsSold;
}

Festival::~Festival() {}

string Festival::getName() {
	return this->name;
}

string Festival::getDate() {
	return this->date;
}

string Festival::getPlace() {
	return this->place;
}

int Festival::getNumberOfSeatsAvailable() {
	return this->numberOfSeatsAvailable;
}

int Festival::getNumberOfSeatsSold() {
	return this->numberOfSeatsSold;
}

void Festival::setName(string newName) {
	this->name = newName;
}

void Festival::setDate(string newDate) {
	this->date = newDate;
}

void Festival::setPlace(string newPlace) {
	this->place = newPlace;
}

void Festival::setNumberOfSeatsAvailable(int newNumberOfSeatsAvailable) {
	this->numberOfSeatsAvailable = newNumberOfSeatsAvailable;
}

void Festival::setNumberOfSeatsSold(int newNumberOfSeatsSold) {
	this->numberOfSeatsSold = newNumberOfSeatsSold;
}

Festival& Festival::operator=(const Festival& festival) {
	if (this != &festival) {
		this->name = festival.name;
		this->date = festival.date;
		this->place = festival.place;
		this->numberOfSeatsAvailable = festival.numberOfSeatsAvailable;
		this->numberOfSeatsSold = festival.numberOfSeatsSold;
	}
	return *this;
}

bool Festival::operator==(const Festival& festival) {
	return (this->name.compare(festival.name) == 0 &&
		this->date.compare(festival.date) == 0 &&
		this->place.compare(festival.place) == 0 &&
		this->numberOfSeatsAvailable == festival.numberOfSeatsAvailable &&
		this->numberOfSeatsSold == festival.numberOfSeatsSold
		);
}
