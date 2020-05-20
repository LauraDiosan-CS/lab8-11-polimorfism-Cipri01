#pragma once
#include "RepoFile.h"
#include "Artist.h"
#include "Movie.h"
#include "Util.h"
#include "Admin.h"
#include <fstream>

template <class T>
class RepoFileTXT : public RepoFile<T> {
public:
	RepoFileTXT();
	RepoFileTXT(string fileName);
	~RepoFileTXT();

	void loadFromFile();
	void saveToFile();
};

template<class T>
inline RepoFileTXT<T>::RepoFileTXT() : RepoFile<T>() {}

template<class T>
inline RepoFileTXT<T>::RepoFileTXT(string fileName) : RepoFile<T>(fileName) {}

template<class T>
inline RepoFileTXT<T>::~RepoFileTXT() {}

template<class T>
inline void RepoFileTXT<T>::loadFromFile() {
	ifstream f(this->fileName);
	if (f.is_open()) {
		this->emptyRepo();
		string line;
		string delim = " ";
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
				//cout << endl << line << endl;
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
inline void RepoFileTXT<T>::saveToFile() {
	ofstream f(this->fileName);
	if (f.is_open()) {
		for (T* elem : this->elements)
			f << elem->toString(" ") << endl;
	}
}
