#pragma once
#include "RepoFile.h"
#include"RepoFileTXT.h"
#include "RepoFileCSV.h"
#include "Artist.h"
#include "Movie.h"
#include "AdminFile.h"
#include "ValidatorArtist.h"
#include "ValidatorMovie.h"

class Service {
private:
	RepoFile<Festival>* repo;
	AdminFile admins;
	ValidatorArtist validatorArtist;
	ValidatorMovie validatorMovie;
public:
	Service();
	Service(RepoFile<Festival>* repo);
	~Service();

	void setRepo(RepoFile<Festival>* repo);
	void setAdmins(AdminFile admins);

	void addArtist(string name, string date, string place,
		int numberOfSeatsAvailable, int numberOfSeatsSold);
	void addMovie(string name, vector<string> listOfActors,
		string date, string place, int numberOfSeatsAvailable, int numberOfSeatsSold);

	vector<Festival*> getAll();

	Festival* getElement(int pos);

	void updateArtist(string name, string newName, string newDate, string newPlace,
		int newNumberOfSeatsAvailable, int newNumberOfSeatsSold);

	void updateMovie(string name, string newName, vector<string> newListOfActors,
		string newDate, string newPlace, int newNumberOfSeatsAvailable, int newNumberOfSeatsSold);

	void deleteElement(string name);

	int getSize();

	bool login(string userName, string passWord);
	string getPassWordForAnUserName(string userName);

	vector<Festival*> getElementBySearch(string date);
	void getMovieOrShowForBuy(string name, int numberOfSeats);

	void addAdmin(string userName, string passWord);
};
