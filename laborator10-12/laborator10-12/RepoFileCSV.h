#pragma once
#include "RepoFile.h"

template <class T>
class RepoFileCSV : public RepoFile<T> {
public:
	RepoFileCSV();
	RepoFileCSV(string fileName);
	~RepoFileCSV();

	void loadFromFile();
	void saveToFile();
};

template<class T>
inline RepoFileCSV<T>::RepoFileCSV() : RepoFile<T>() {}

template<class T>
inline RepoFileCSV<T>::RepoFileCSV(string fileName) : RepoFile<T>(fileName) {}

template<class T>
inline RepoFileCSV<T>::~RepoFileCSV() {}


template<class T>
inline void RepoFileCSV<T>::loadFromFile() {
	ifstream f(this->fileName);
	if (f.is_open()) {
		this->emptyRepo();
		string line;
		string delim = ",";
		while (getline(f, line)) {
			if (line.substr(0, 4) == "SHOW") {
				line = line.erase(0, 5);
				string name = "", date = "", place = "";
				int numberOfSeatsAvailable = 0, numberOfSeatsSold = 0;

				getElementsFromString(line, name, date, place, numberOfSeatsAvailable, numberOfSeatsSold, delim);

				Artist* artist = new Artist(name, date, place, numberOfSeatsAvailable, numberOfSeatsSold);
				this->elements.push_back(artist);
			}
			else if (line.substr(0, 5) == "MOVIE") {
				line = line.erase(0, 6);
				string name = "", date = "", place = "";
				int numberOfSeatsAvailable = 0, numberOfSeatsSold = 0;

				getElementsFromString(line, name, date, place, numberOfSeatsAvailable, numberOfSeatsSold, delim);
				line = line.erase(0, 1);
				vector<string> listOfActors;
				getElementsFromStringInVector(listOfActors, line);

				Movie* movie = new Movie(name, listOfActors, date, place, numberOfSeatsAvailable, numberOfSeatsSold);
				this->elements.push_back(movie);

			}
		}
		f.close();
	}
}

template<class T>
inline void RepoFileCSV<T>::saveToFile() {
	ofstream f(this->fileName);
	if (f.is_open()) {
		for (T* elem : this->elements)
			f << elem->toString(",") << endl;
	}
}
