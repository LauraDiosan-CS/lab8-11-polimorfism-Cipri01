#include "ServiceTest.h"
#include <assert.h>
#include "IndexOutOfBoundsException.h"
#include "FullVectorException.h"

void ServiceTest::testAddArtist() {
	try {
		Service service;
		RepoFile<Festival>* repo;
		repo = new RepoFileTXT<Festival>;

		service.setRepo(repo);
		service.addArtist("Sia", "12.02.2002", "Arena", 100, 200);

		assert(service.getSize() == 1);
		assert(service.getElement(0)->getName().compare("Sia") == 0);
		assert(service.getElement(0)->getDate().compare("12.02.2002") == 0);
		assert(service.getElement(0)->getPlace().compare("Arena") == 0);
		assert(service.getElement(0)->getNumberOfSeatsAvailable() == 100);
		assert(service.getElement(0)->getNumberOfSeatsSold() == 200);
	}
	catch (ValidationException& exc) {
		cout << exc.what() << endl;
	}
	catch (FullVectorException& exc) {
		cout << exc.what() << endl;
	}
}

void ServiceTest::testAddMovie() {
	Service service;
	RepoFile<Festival>* repo;
	repo = new RepoFileTXT<Festival>;

	service.setRepo(repo);

	vector<string> listOfActors;
	listOfActors.push_back("Actor 01");
	listOfActors.push_back("Actor 02");
	service.addMovie("Titanic", listOfActors, "12.02.2002", "Arena", 100, 200);

	assert(service.getSize() == 1);
	assert(service.getElement(0)->getName().compare("Titanic") == 0);
	//assert((Movie*)service.getElement(0)->getListOfActors() == listOfActors);
	assert(service.getElement(0)->getDate().compare("12.02.2002") == 0);
	assert(service.getElement(0)->getPlace().compare("Arena") == 0);
	assert(service.getElement(0)->getNumberOfSeatsAvailable() == 100);
	assert(service.getElement(0)->getNumberOfSeatsSold() == 200);
}

void ServiceTest::testGetAll() {
	Service service;
	RepoFile<Festival>* repo;
	repo = new RepoFileTXT<Festival>;

	service.setRepo(repo);

	vector<string> listOfActors;
	listOfActors.push_back("Actor 01");
	listOfActors.push_back("Actor 02");
	service.addMovie("Titanic", listOfActors, "12.02.2003", "Arena", 100, 200);
	service.addArtist("Sia", "12.02.2003", "Arena", 100, 200);

	assert(service.getAll()[0]->getName() == "Titanic");
	assert(service.getAll()[1]->getName() == "Sia");
	assert(service.getSize() == 2);
}

void ServiceTest::testGetElement() {
	Service service;
	RepoFile<Festival>* repo;
	repo = new RepoFileTXT<Festival>;

	service.setRepo(repo);

	vector<string> listOfActors;
	listOfActors.push_back("Actor 01");
	listOfActors.push_back("Actor 02");
	service.addMovie("Titanic", listOfActors, "12.02.2002", "Arena", 100, 200);
	service.addArtist("Sia", "12.02.2002", "Arena", 100, 200);

	assert(service.getElement(0)->getName() == "Titanic");
	assert(service.getElement(1)->getName() == "Sia");
	assert(service.getSize() == 2);
	/*try {
		cout<<service.getElement(2)->getName();
	}
	catch (IndexOutOfBoundsException & exc) {
		cout << endl;
		cout << "exception: " << exc.what() << endl;
		cout << endl;
	}*/
}

void ServiceTest::testUpdateArtist() {
	Service service;
	RepoFile<Festival>* repo;
	repo = new RepoFileTXT<Festival>;

	service.setRepo(repo);

	service.addArtist("Sia", "12.02.2002", "Arena", 100, 200);
	service.updateArtist("Sia", "Ariana Grande", "12.02.2002", "Arena", 100, 200);

	assert(service.getElement(0)->getName().compare("Ariana Grande") == 0);
}

void ServiceTest::testUpdateMovie() {
	Service service;
	RepoFile<Festival>* repo;
	repo = new RepoFileTXT<Festival>;

	service.setRepo(repo);

	vector<string> listOfActors;
	listOfActors.push_back("Actor 01");
	listOfActors.push_back("Actor 02");
	service.addMovie("Titanic", listOfActors, "12.02.2002", "Arena", 100, 200);
	service.updateMovie("Titanic", "Midnight sun", listOfActors, "12.02.2002", "Arena", 100, 200);

	assert(service.getElement(0)->getName().compare("Midnight sun") == 0);
}

void ServiceTest::testDelete() {
	Service service;
	RepoFile<Festival>* repo;
	repo = new RepoFileTXT<Festival>;

	service.setRepo(repo);

	vector<string> listOfActors;
	listOfActors.push_back("Actor 01");
	listOfActors.push_back("Actor 02");
	service.addMovie("Titanic", listOfActors, "12.02.2002", "Arena", 100, 200);
	service.addArtist("Sia", "12.02.2002", "Arena", 100, 200);
	service.deleteElement("Titanic");

	assert(service.getSize() == 1);
	assert(service.getElement(0)->getName().compare("Sia") == 0);
}

void ServiceTest::testGetSize() {
	Service service;
	RepoFile<Festival>* repo;
	repo = new RepoFileTXT<Festival>;

	service.setRepo(repo);

	vector<string> listOfActors;
	listOfActors.push_back("Actor 01");
	listOfActors.push_back("Actor 02");
	service.addMovie("Titanic", listOfActors, "12.02.2002", "Arena", 100, 200);
	service.addArtist("Sia", "12.02.2002", "Arena", 100, 200);

	assert(service.getSize() == 2);
}

void ServiceTest::testLogin() {
	Admin admin01("ana", "1234");
	Admin admin02("maria", "5678");

	Service service;
	AdminFile adminFile("srv.txt");
	service.setAdmins(adminFile);

	adminFile.addAdmin(admin01);
	adminFile.addAdmin(admin02);
	adminFile.saveToFile();
	bool first = service.login("ana", "1234");
	bool second = service.login("ana", "0123");
	assert(first == true);
	assert(second == false);
}

void ServiceTest::testGetPassWordForAnUserName() {
	Admin admin01("ana", "1234");
	Admin admin02("maria", "5678");

	string userName01 = "ana";
	string userName02 = "ana01";

	string passWord01 = "1234";

	Service service;
	AdminFile adminFile("srv.txt");
	service.setAdmins(adminFile);

	adminFile.addAdmin(admin01);
	adminFile.addAdmin(admin02);
	adminFile.saveToFile();

	string first = service.getPassWordForAnUserName(userName01);
	string second = service.getPassWordForAnUserName(userName02);

	assert(first.compare(passWord01) == 0);
	assert(second.compare("none") == 0);
}

void ServiceTest::testGetElementBySearch() {
	Service service;
	RepoFile<Festival>* repo;
	repo = new RepoFileTXT<Festival>;

	service.setRepo(repo);

	vector<string> listOfActors;
	listOfActors.push_back("Actor 01");
	listOfActors.push_back("Actor 02");
	service.addMovie("Titanic", listOfActors, "12.02.2002", "Arena", 100, 200);
	service.addArtist("Sia", "12.02.2003", "Arena", 100, 200);

	vector<Festival*> vector = service.getElementBySearch("12.02.2003");

	assert(vector.size() == 1);
	assert(vector[0]->getName().compare("Sia") == 0);
}

//void ServiceTest::testGetMovieOrShowForBuy() {
//	Service service;
//	RepoFile<Festival>* repo;
//	repo = new RepoFileTXT<Festival>;
//
//	service.setRepo(repo);
//
//	vector<string> listOfActors;
//	listOfActors.push_back("Actor 01");
//	listOfActors.push_back("Actor 02");
//	service.addMovie("Titanic", listOfActors, "12.02.2002", "Arena", 100, 200);
//	service.addArtist("Sia", "12.02.2003", "Arena", 100, 200);
//	
//	service.getMovieOrShowForBuy("Sia", 50);
//	assert(service.getElement(1)->getNumberOfSeatsAvailable() == 50);
//	assert(service.getElement(1)->getNumberOfSeatsSold() == 250);
//
//	cout << "TEST for Service class DONE!" << endl;
//}

void ServiceTest::testGetMovieOrShowForBuy() {
	Service service;
	RepoFile<Festival>* repo;
	repo = new RepoFileCSV<Festival>;

	service.setRepo(repo);

	vector<string> listOfActors;
	listOfActors.push_back("Actor 01");
	listOfActors.push_back("Actor 02");
	service.addMovie("Titanic", listOfActors, "12.02.2002", "Arena", 100, 200);
	service.addArtist("Sia", "12.02.2003", "Arena", 100, 200);

	service.getMovieOrShowForBuy("Sia", 50);
	assert(service.getElement(1)->getNumberOfSeatsAvailable() == 50);
	assert(service.getElement(1)->getNumberOfSeatsSold() == 250);

	cout << "TEST for Service class DONE!" << endl;
}

ServiceTest::ServiceTest() {}

ServiceTest::~ServiceTest() {}

void ServiceTest::testAll() {
	//this->testAddArtist();
	//this->testAddMovie();
	//this->testGetAll();
	//this->testGetElement();
	//this->testUpdateArtist();
	//this->testUpdateMovie();
	//this->testDelete();
	//this->testGetSize();
	//this->testLogin();
	//this->testGetPassWordForAnUserName();
	//this->testGetElementBySearch();
	this->testGetMovieOrShowForBuy();
}
