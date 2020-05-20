#include "Movie.h"

Movie::Movie() : Festival() {
	this->listOfActors.empty();
}

Movie::Movie(string name, vector<string> listOfActors, string date, string place, int numberOfSeatsAvailable, int numberOfSeatsSold) :
	Festival(name, date, place, numberOfSeatsAvailable, numberOfSeatsSold) {
	this->listOfActors = listOfActors;
}

Movie::Movie(const Movie& movie) : Festival(movie) {
	this->listOfActors = movie.listOfActors;
}

Movie::~Movie() {}

vector<string> Movie::getListOfActors() {
	return this->listOfActors;
}

void Movie::setListOfActors(vector<string> newListOfActors) {
	this->listOfActors = newListOfActors;
}

Movie& Movie::operator=(const Movie& movie) {
	Festival::operator=(movie);
	this->listOfActors = movie.listOfActors;
	return *this;
}

bool Movie::vectorEqual(vector<string> vector01, vector<string> vector02) {
	if (vector01.size() != vector02.size())
		return false;
	for (int i = 0; i < vector01.size(); i++) {
		if (vector01[i].compare(vector02[i]) == true)
			return false;
	}
	return true;
}

bool Movie::operator==(const Movie& movie) {
	return Festival::operator==(movie) &&
		this->vectorEqual(this->listOfActors,
			movie.listOfActors);
}

Festival* Movie::clone() {
	return new Movie(this->name, this->listOfActors,
		this->date, this->place, this->numberOfSeatsAvailable,
		this->numberOfSeatsSold);
}

string Movie::convertVectorToString(vector<string> vector) {
	string vectorString = "";
	for (int i = 0; i < vector.size() - 1; i++) {
		vectorString = vectorString + vector[i] + ";";
	}
	vectorString = vectorString + vector[vector.size() - 1];
	return vectorString;
}

string Movie::toString(string delim) {
	return "MOVIE" + delim + this->name + "*" + delim + this->date + delim + this->place + "*" + delim +
		std::to_string(this->numberOfSeatsAvailable) + delim + std::to_string(this->numberOfSeatsSold) + delim + "[" + this->convertVectorToString(this->listOfActors) + "]";
}
