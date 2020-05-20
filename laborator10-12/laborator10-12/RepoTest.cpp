#include "RepoTest.h"
#include "RepoFileTXT.h"
#include "RepoFileCSV.h"
#include "Artist.h"
#include "Movie.h"
#include <assert.h>

void RepoTest::testGetSize() {
	RepoFile<Festival>* repoFile = new RepoFileTXT<Festival>();

	assert(repoFile->getSize() == 0);
	repoFile->addElement(new Artist());
	assert(repoFile->getSize() == 1);
}

void RepoTest::testGetAll() {
	RepoFile<Festival>* repoFile = new RepoFileTXT<Festival>();

	Artist* artist = new Artist("Sia", "20.05.2020", "BT ARENA", 10000, 20000);

	vector<string> listOfActors;
	listOfActors.push_back("Bella Thorne");
	listOfActors.push_back("Patrick Schwarzenegger");
	listOfActors.push_back("Rob Riggle");
	listOfActors.push_back("Quinn Shephard");

	Movie* movie = new Movie("Midnight sun", listOfActors, "20.12.2020", "BT ARENA", 1000, 1000000);

	repoFile->addElement(artist);
	repoFile->addElement(movie);

	vector<Festival*> elements = repoFile->getAll();
	assert(*elements[0] == *artist->clone());
	assert(*elements[1] == *movie->clone());
}

void RepoTest::testGetElement() {
	RepoFile<Festival>* repoFile = new RepoFileTXT<Festival>();

	Artist* artist = new Artist("Sia", "20.05.2020", "BT ARENA", 10000, 20000);

	repoFile->addElement(artist);

	assert(*repoFile->getElement(0) == *artist->clone());
}

void RepoTest::testAddElement() {
	RepoFile<Festival>* repoFile = new RepoFileTXT<Festival>();

	Artist* artist = new Artist("Sia", "20.05.2020", "BT ARENA", 10000, 20000);

	repoFile->addElement(artist);

	assert(*repoFile->getElement(0) == *artist->clone());
}

void RepoTest::testUpdateElement() {
	RepoFile<Festival>* repoFile = new RepoFileTXT<Festival>();

	Artist* artist = new Artist("Sia", "20.05.2020", "BT ARENA", 10000, 20000);

	repoFile->addElement(artist);

	Artist* artist02 = new Artist("Ariana Grande", "20.05.2020", "BT ARENA", 10000, 20000);

	repoFile->updateElement(artist, artist02);

	assert(*repoFile->getElement(0) == *artist02->clone());
}

void RepoTest::testDeleteElement() {
	RepoFile<Festival>* repoFile = new RepoFileTXT<Festival>();

	Artist* artist = new Artist("Sia", "20.05.2020", "BT ARENA", 10000, 20000);

	repoFile->addElement(artist);

	Artist* artist02 = new Artist("Ariana Grande", "20.05.2020", "BT ARENA", 10000, 20000);

	repoFile->deleteElement(artist);

	assert(repoFile->getSize() == 0);
}

void RepoTest::testLoadFromFileTXT() {
	RepoFile<Festival>* repoFile = new RepoFileTXT<Festival>(this->fileNameInTXT);
	repoFile->loadFromFile();

	assert(repoFile->getSize() == this->elementsIn.size());
	assert(*repoFile->getElement(0) == *this->elementsIn[0]);
	assert(*repoFile->getElement(1) == *this->elementsIn[1]);
}

//void RepoTest::testSaveToFileTXT() {
//	RepoFile<Festival>* repoFile = new RepoFileTXT<Festival>(this->fileNameInTXT);
//	repoFile->loadFromFile();
//	repoFile->setFileName(this->fileNameOutTXT);
//
//	Festival* artist = new Artist("Sia", "20.06.2020", "BT ARENA", 10000, 20000);
//
//	repoFile->addElement(artist);
//	//repoFile->saveToFile();
//	repoFile->loadFromFile();
//
//	assert(repoFile->getSize() == this->elementsIn.size() + 1);
//	vector<Festival*> elem = repoFile->getAll();
//	for (int i = 0; i < repoFile->getSize() - 1; i++)
//		assert(*elem[i] == *this->elementsIn[i]);
//
//	repoFile->deleteElement(artist);
//}

void RepoTest::testLoadFromFileCSV() {
	RepoFile<Festival>* repoFile = new RepoFileCSV<Festival>(this->fileNameInCSV);
	repoFile->loadFromFile();

	assert(repoFile->getSize() == this->elementsIn.size());
	assert(*repoFile->getElement(0) == *this->elementsIn[0]);
	assert(*repoFile->getElement(1) == *this->elementsIn[1]);

	cout << "TEST for Repo class DONE!" << endl;
}

//void RepoTest::testSaveToFileCSV() {
//	RepoFile<Festival>* repoFile = new RepoFileCSV<Festival>(this->fileNameInCSV);
//	repoFile->loadFromFile();
//	repoFile->setFileName(this->fileNameOutCSV);
//
//	Festival* artist = new Artist("Sia", "20.05.2020", "BT ARENA", 10000, 20000);
//
//	repoFile->addElement(artist);
//	repoFile->saveToFile();
//	repoFile->loadFromFile();
//
//	assert(repoFile->getSize() == this->elementsIn.size() + 1);
//
//	vector<Festival*> elem = repoFile->getAll();
//	for (int i = 0; i < repoFile->getSize() - 1; i++)
//		assert(*elem[i] == *this->elementsIn[i]);
//
//	cout << "TEST for Repo class DONE!" << endl;
//}

RepoTest::RepoTest() {
	Artist* artist = new Artist("Sia", "20.05.2020", "BT ARENA", 10000, 20000);

	vector<string> listOfActors;
	listOfActors.push_back("Bella Thorne");
	listOfActors.push_back("Patrick Schwarzenegger");
	listOfActors.push_back("Rob Riggle");
	listOfActors.push_back("Quinn Shephard");

	Movie* movie = new Movie("Midnight sun", listOfActors, "20.12.2020", "BT ARENA", 1000, 1000000);

	this->elementsIn.push_back(artist);
	this->elementsIn.push_back(movie);

}

RepoTest::~RepoTest() {}

void RepoTest::testAll() {
	this->testGetSize();
	this->testGetAll();
	this->testGetElement();
	this->testAddElement();
	this->testUpdateElement();
	this->testDeleteElement();
	this->testLoadFromFileTXT();
	//this->testSaveToFileTXT();
	this->testLoadFromFileCSV();
	//this->testSaveToFileCSV();
}
