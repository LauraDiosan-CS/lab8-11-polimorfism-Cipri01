#include "Service.h"
#include "FullVectorException.h"
#include "EmptyVectorException.h"
#include "IndexOutOfBoundsException.h"

Service::Service() {
	this->repo = new RepoFileTXT<Festival>();
}

Service::Service(RepoFile<Festival>* repo) {
	this->repo = repo;
}

Service::~Service() {}

void Service::setRepo(RepoFile<Festival>* repo) {
	this->repo = repo;
}

void Service::setAdmins(AdminFile admins) {
	this->admins = admins;
}

void Service::addArtist(string name, string date, string place,
	int numberOfSeatsAvailable, int numberOfSeatsSold) throw(ValidationException, FullVectorException) {
	Festival* artist = new Artist(name, date, place, numberOfSeatsAvailable, numberOfSeatsSold);
	this->validatorArtist.validate(artist);
	if (this->repo->getSize() > 100) {
		FullVectorException exc("the vector is full; it must be re-sized...");
		throw exc;
	}
	this->repo->addElement(new Artist(name, date, place,
		numberOfSeatsAvailable, numberOfSeatsSold));
}

void Service::addMovie(string name, vector<string> listOfActors,
	string date, string place, int numberOfSeatsAvailable, int numberOfSeatsSold)
	throw(ValidationException, FullVectorException) {
	Festival* movie = new Movie(name, listOfActors, date, place, numberOfSeatsAvailable, numberOfSeatsSold);
	this->validatorMovie.validate(movie);
	if (this->repo->getSize() > 100) {
		FullVectorException exc("the vector is full; it must be re-sized...");
		throw exc;
	}

	this->repo->addElement(new Movie(name, listOfActors, date,
		place, numberOfSeatsAvailable, numberOfSeatsSold));
}

vector<Festival*> Service::getAll() throw(EmptyVectorException) {
	this->repo->loadFromFile();

	if (this->repo->getSize() == 0) {
		EmptyVectorException exc("the vector is empty...");
		throw exc;
	}
	return this->repo->getAll();
}

Festival* Service::getElement(int pos) throw(IndexOutOfBoundsException) {
	if (pos < 0 || pos >= this->repo->getSize()) {
		IndexOutOfBoundsException exc("that position don't exist...");
		throw exc;
	}
	return this->repo->getElement(pos);
}

void Service::updateArtist(string name, string newName, string newDate,
	string newPlace, int newNumberOfSeatsAvailable, int newNumberOfSeatsSold)
	throw(ValidationException) {

	vector<Festival*> artists = this->repo->getAll();
	Festival* newArtist;
	newArtist = new Artist(newName, newDate, newPlace, newNumberOfSeatsAvailable,
		newNumberOfSeatsSold);
	this->validatorArtist.validate(newArtist);
	for (int i = 0; i < this->repo->getSize(); i++) {
		if (artists[i]->getName().compare(name) == 0) {
			this->repo->updateElement(artists[i], newArtist);
		}
	}
}

void Service::updateMovie(string name, string newName, vector<string> newListOfActors,
	string newDate, string newPlace, int newNumberOfSeatsAvailable, int newNumberOfSeatsSold)
	throw(ValidationException) {

	vector<Festival*> movies = this->repo->getAll();
	Festival* newMovie;
	newMovie = new Movie(newName, newListOfActors, newDate, newPlace, newNumberOfSeatsAvailable,
		newNumberOfSeatsSold);
	this->validatorMovie.validate(newMovie);
	for (int i = 0; i < this->repo->getSize(); i++) {
		if (movies[i]->getName().compare(name) == 0) {
			this->repo->updateElement(movies[i], newMovie);
		}
	}
}

void Service::deleteElement(string name) {
	vector<Festival*> elements = this->repo->getAll();
	for (int i = 0; i < this->repo->getSize(); i++) {
		if (elements[i]->getName().compare(name) == 0) {
			this->repo->deleteElement(elements[i]);
		}
	}
}

int Service::getSize() {
	return this->repo->getSize();
}

bool Service::login(string userName, string passWord) {
	if (passWord.compare(this->getPassWordForAnUserName(userName)) == 0)
		return true;
	return false;
}

string Service::getPassWordForAnUserName(string userName) {
	this->admins.loadFromFile();
	//cout << admins.getSize() << endl;
	vector<Admin> listOfAdmins = this->admins.getAll();
	for (int i = 0; i < admins.getSize(); i++) {
		//cout << listOfAdmins[i].getUserName() << endl;
		if (listOfAdmins[i].getUserName() == userName) {
			return listOfAdmins[i].getPassWord();
		}
	}
	return "none";
}

vector<Festival*> Service::getElementBySearch(string date) {
	vector<Festival*> vectorOfElements;
	for (int i = 0; i < this->repo->getSize(); i++) {
		if (this->repo->getElement(i)->getDate().compare(date) == 0) {
			vectorOfElements.push_back(this->repo->getElement(i));
		}
	}
	return vectorOfElements;
}

void Service::getMovieOrShowForBuy(string name, int numberOfSeats) {
	this->repo->loadFromFile();
	for (int i = 0; i < this->repo->getSize(); i++) {
		if (this->repo->getElement(i)->getName().compare(name) == 0) {
			if (this->repo->getElement(i)->getNumberOfSeatsAvailable() - numberOfSeats >= 0) {
				Festival* obj = this->repo->getElement(i);
				Festival* oldObj = obj->clone();

				obj->setNumberOfSeatsAvailable(obj->getNumberOfSeatsAvailable() - numberOfSeats);
				obj->setNumberOfSeatsSold(obj->getNumberOfSeatsSold() + numberOfSeats);
				Festival* newObj = obj;

				this->repo->updateElement(oldObj, newObj);
			}
		}
	}
	this->repo->saveToFile();
}

void Service::addAdmin(string userName, string passWord) {
	this->admins.addAdmin(Admin(userName, passWord));
}
