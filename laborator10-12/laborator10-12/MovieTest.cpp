#include "MovieTest.h"
#include "Movie.h"
#include <assert.h>

void MovieTest::testAll() {
	this->testImplicitConstructor();
	this->testConstructorWithParameters();
	this->testCopyConstructor();
	this->testGetName();
	this->testSetName();
	this->testGetDate();
	this->testSetDate();
	this->testGetPlace();
	this->testSetPlace();
	this->testGetNumberOfSeatsAvailable();
	this->testSetNumberOfSeatsAvailable();
	this->testGetNumberOfSeatsSold();
	this->testSetNumberOfSeatsSold();
	this->testGetListOfActors();
	this->testSetListOfActors();
	this->testAssignmentOperator();
	this->testEqualityOperator();
	this->testClone();
	this->testToString();
	this->testVectorEqual();
	this->testVectorToString();
}

void MovieTest::testImplicitConstructor() {
	Movie movie;

	assert(movie.getName().empty());
	assert(movie.getListOfActors().size() == 0);
	assert(movie.getDate().empty());
	assert(movie.getPlace().empty());
	assert(movie.getNumberOfSeatsAvailable() == 0);
	assert(movie.getNumberOfSeatsSold() == 0);
}

void MovieTest::testConstructorWithParameters() {
	vector<string> listOfActors;
	listOfActors.push_back("Bella Thorne");
	listOfActors.push_back("Patrick Schwarzenegger");
	listOfActors.push_back("Rob Riggle");
	listOfActors.push_back("Quinn Shephard");

	Movie movie("Midnight sun", listOfActors, "20.12.2020", "BT ARENA", 1000, 1000000);

	assert(movie.getName() == "Midnight sun");
	assert(movie.vectorEqual(listOfActors, movie.getListOfActors()) == true);
	assert(movie.getDate() == "20.12.2020");
	assert(movie.getPlace() == "BT ARENA");
	assert(movie.getNumberOfSeatsAvailable() == 1000);
	assert(movie.getNumberOfSeatsSold() == 1000000);
}

void MovieTest::testCopyConstructor() {
	vector<string> listOfActors;
	listOfActors.push_back("Bella Thorne");
	listOfActors.push_back("Patrick Schwarzenegger");
	listOfActors.push_back("Rob Riggle");
	listOfActors.push_back("Quinn Shephard");

	Movie movie("Midnight sun", listOfActors, "20.12.2020", "BT ARENA", 1000, 1000000);

	Movie movie02(movie);

	assert(movie02.getName() == "Midnight sun");
	assert(movie02.vectorEqual(listOfActors, movie02.getListOfActors()) == true);
	assert(movie02.getDate() == "20.12.2020");
	assert(movie02.getPlace() == "BT ARENA");
	assert(movie02.getNumberOfSeatsAvailable() == 1000);
	assert(movie02.getNumberOfSeatsSold() == 1000000);
}

void MovieTest::testGetName() {
	vector<string> listOfActors;
	listOfActors.push_back("Bella Thorne");
	listOfActors.push_back("Patrick Schwarzenegger");
	listOfActors.push_back("Rob Riggle");
	listOfActors.push_back("Quinn Shephard");

	Movie movie("Midnight sun", listOfActors, "20.12.2020", "BT ARENA", 1000, 1000000);

	assert(movie.getName() == "Midnight sun");
}

void MovieTest::testSetName() {
	vector<string> listOfActors;
	listOfActors.push_back("Bella Thorne");
	listOfActors.push_back("Patrick Schwarzenegger");
	listOfActors.push_back("Rob Riggle");
	listOfActors.push_back("Quinn Shephard");

	Movie movie("Midnight sun", listOfActors, "20.12.2020", "BT ARENA", 1000, 1000000);

	movie.setName("Midnight moon");

	assert(movie.getName() == "Midnight moon");
}

void MovieTest::testGetDate() {
	vector<string> listOfActors;
	listOfActors.push_back("Bella Thorne");
	listOfActors.push_back("Patrick Schwarzenegger");
	listOfActors.push_back("Rob Riggle");
	listOfActors.push_back("Quinn Shephard");

	Movie movie("Midnight sun", listOfActors, "20.12.2020", "BT ARENA", 1000, 1000000);

	assert(movie.getDate() == "20.12.2020");
}

void MovieTest::testSetDate() {
	vector<string> listOfActors;
	listOfActors.push_back("Bella Thorne");
	listOfActors.push_back("Patrick Schwarzenegger");
	listOfActors.push_back("Rob Riggle");
	listOfActors.push_back("Quinn Shephard");

	Movie movie("Midnight sun", listOfActors, "20.12.2020", "BT ARENA", 1000, 1000000);

	movie.setDate("20.12.2021");

	assert(movie.getDate() == "20.12.2021");
}

void MovieTest::testGetPlace() {
	vector<string> listOfActors;
	listOfActors.push_back("Bella Thorne");
	listOfActors.push_back("Patrick Schwarzenegger");
	listOfActors.push_back("Rob Riggle");
	listOfActors.push_back("Quinn Shephard");

	Movie movie("Midnight sun", listOfActors, "20.12.2020", "BT ARENA", 1000, 1000000);

	assert(movie.getPlace() == "BT ARENA");
}

void MovieTest::testSetPlace() {
	vector<string> listOfActors;
	listOfActors.push_back("Bella Thorne");
	listOfActors.push_back("Patrick Schwarzenegger");
	listOfActors.push_back("Rob Riggle");
	listOfActors.push_back("Quinn Shephard");

	Movie movie("Midnight sun", listOfActors, "20.12.2020", "BT ARENA", 1000, 1000000);

	movie.setPlace("Stadion");

	assert(movie.getPlace() == "Stadion");
}

void MovieTest::testGetNumberOfSeatsAvailable() {
	vector<string> listOfActors;
	listOfActors.push_back("Bella Thorne");
	listOfActors.push_back("Patrick Schwarzenegger");
	listOfActors.push_back("Rob Riggle");
	listOfActors.push_back("Quinn Shephard");

	Movie movie("Midnight sun", listOfActors, "20.12.2020", "BT ARENA", 1000, 1000000);

	assert(movie.getNumberOfSeatsAvailable() == 1000);
}

void MovieTest::testSetNumberOfSeatsAvailable() {
	vector<string> listOfActors;
	listOfActors.push_back("Bella Thorne");
	listOfActors.push_back("Patrick Schwarzenegger");
	listOfActors.push_back("Rob Riggle");
	listOfActors.push_back("Quinn Shephard");

	Movie movie("Midnight sun", listOfActors, "20.12.2020", "BT ARENA", 1000, 1000000);

	movie.setNumberOfSeatsAvailable(500);

	assert(movie.getNumberOfSeatsAvailable() == 500);
}

void MovieTest::testGetNumberOfSeatsSold() {
	vector<string> listOfActors;
	listOfActors.push_back("Bella Thorne");
	listOfActors.push_back("Patrick Schwarzenegger");
	listOfActors.push_back("Rob Riggle");
	listOfActors.push_back("Quinn Shephard");

	Movie movie("Midnight sun", listOfActors, "20.12.2020", "BT ARENA", 1000, 1000000);

	assert(movie.getNumberOfSeatsSold() == 1000000);
}

void MovieTest::testSetNumberOfSeatsSold() {
	vector<string> listOfActors;
	listOfActors.push_back("Bella Thorne");
	listOfActors.push_back("Patrick Schwarzenegger");
	listOfActors.push_back("Rob Riggle");
	listOfActors.push_back("Quinn Shephard");

	Movie movie("Midnight sun", listOfActors, "20.12.2020", "BT ARENA", 1000, 1000000);

	movie.setNumberOfSeatsAvailable(500);

	assert(movie.getNumberOfSeatsAvailable() == 500);
}

void MovieTest::testGetListOfActors() {
	vector<string> listOfActors;
	listOfActors.push_back("Bella Thorne");
	listOfActors.push_back("Patrick Schwarzenegger");
	listOfActors.push_back("Rob Riggle");
	listOfActors.push_back("Quinn Shephard");

	Movie movie("Midnight sun", listOfActors, "20.12.2020", "BT ARENA", 1000, 1000000);

	assert(movie.vectorEqual(listOfActors, movie.getListOfActors()) == true);
	assert(movie.getListOfActors().size() == 4);
}

void MovieTest::testSetListOfActors() {
	vector<string> listOfActors;
	listOfActors.push_back("Bella Thorne");
	listOfActors.push_back("Patrick Schwarzenegger");
	listOfActors.push_back("Rob Riggle");
	listOfActors.push_back("Quinn Shephard");

	vector<string> newListOfActors;
	listOfActors.push_back("Bella Thorne");
	listOfActors.push_back("Patrick Schwarzenegger");
	listOfActors.push_back("Rob Riggle");
	listOfActors.push_back("Quinn Shephard");

	Movie movie("Midnight sun", listOfActors, "20.12.2020", "BT ARENA", 1000, 1000000);

	assert(movie.vectorEqual(listOfActors, movie.getListOfActors()) == true);

	movie.setListOfActors(newListOfActors);

	assert(movie.vectorEqual(newListOfActors, movie.getListOfActors()) == true);


}

void MovieTest::testAssignmentOperator() {
	vector<string> listOfActors;
	listOfActors.push_back("Bella Thorne");
	listOfActors.push_back("Patrick Schwarzenegger");
	listOfActors.push_back("Rob Riggle");
	listOfActors.push_back("Quinn Shephard");

	Movie movie("Midnight sun", listOfActors, "20.12.2020", "BT ARENA", 1000, 1000000);

	Movie movie02;

	movie02 = movie;

	assert(movie02.getName() == "Midnight sun");
	assert(movie02.vectorEqual(listOfActors, movie02.getListOfActors()) == true);
	assert(movie02.getDate() == "20.12.2020");
	assert(movie02.getPlace() == "BT ARENA");
	assert(movie02.getNumberOfSeatsAvailable() == 1000);
	assert(movie02.getNumberOfSeatsSold() == 1000000);
}

void MovieTest::testEqualityOperator() {
	vector<string> listOfActors;
	listOfActors.push_back("Bella Thorne");
	listOfActors.push_back("Patrick Schwarzenegger");
	listOfActors.push_back("Rob Riggle");
	listOfActors.push_back("Quinn Shephard");

	Movie movie("Midnight sun", listOfActors, "20.12.2020", "BT ARENA", 1000, 1000000);

	Movie movie02;

	movie02 = movie;

	assert(movie == movie02);
}

void MovieTest::testClone() {
	vector<string> listOfActors;
	listOfActors.push_back("Bella Thorne");
	listOfActors.push_back("Patrick Schwarzenegger");
	listOfActors.push_back("Rob Riggle");
	listOfActors.push_back("Quinn Shephard");

	Movie movie("Midnight sun", listOfActors, "20.12.2020", "BT ARENA", 1000, 1000000);

	Movie* movieClone = (Movie*)movie.clone();
	assert(movie == *movieClone);
	assert(&movie != movieClone);
}

void MovieTest::testToString() {
	vector<string> listOfActors;
	listOfActors.push_back("Bella Thorne");
	listOfActors.push_back("Patrick Schwarzenegger");
	listOfActors.push_back("Rob Riggle");
	listOfActors.push_back("Quinn Shephard");

	Movie movie("Midnight sun", listOfActors, "20.12.2020", "BT ARENA", 1000, 1000000);


	assert(movie.toString(" ") == "MOVIE Midnight sun* 20.12.2020 BT ARENA* 1000 1000000 [Bella Thorne;Patrick Schwarzenegger;Rob Riggle;Quinn Shephard]");
	assert(movie.toString(",") == "MOVIE,Midnight sun*,20.12.2020,BT ARENA*,1000,1000000,[Bella Thorne;Patrick Schwarzenegger;Rob Riggle;Quinn Shephard]");
}

void MovieTest::testVectorEqual() {
	vector<string> listOfActors;
	listOfActors.push_back("Bella Thorne");
	listOfActors.push_back("Patrick Schwarzenegger");
	listOfActors.push_back("Rob Riggle");
	listOfActors.push_back("Quinn Shephard");

	Movie movie("Midnight sun", listOfActors, "20.12.2020", "BT ARENA", 1000, 1000000);

	assert(movie.vectorEqual(listOfActors, movie.getListOfActors()) == true);
}

void MovieTest::testVectorToString() {
	vector<string> listOfActors;
	listOfActors.push_back("Bella Thorne");
	listOfActors.push_back("Patrick Schwarzenegger");
	listOfActors.push_back("Rob Riggle");
	listOfActors.push_back("Quinn Shephard");

	Movie movie("Midnight sun", listOfActors, "20.12.2020", "BT ARENA", 1000, 1000000);

	string result = movie.convertVectorToString(movie.getListOfActors());

	assert(result == "Bella Thorne;Patrick Schwarzenegger;Rob Riggle;Quinn Shephard");

	cout << "TEST for Movie class DONE!" << endl;
}
