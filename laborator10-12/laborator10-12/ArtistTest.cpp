#include "ArtistTest.h"
#include "Artist.h"
#include <assert.h>

void ArtistTest::testAll() {
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
	this->testAssignmentOperator();
	this->testEqualityOperator();
	this->testClone();
	this->testToString();
}

void ArtistTest::testImplicitConstructor() {
	Artist artist;

	assert(artist.getName().empty());
	assert(artist.getDate().empty());
	assert(artist.getPlace().empty());
	assert(artist.getNumberOfSeatsAvailable() == 0);
	assert(artist.getNumberOfSeatsSold() == 0);
}

void ArtistTest::testConstructorWithParameters() {
	Artist artist("Sia", "20.12.2020", "BT ARENA", 1000, 1000000);

	assert(artist.getName() == "Sia");
	assert(artist.getDate() == "20.12.2020");
	assert(artist.getPlace() == "BT ARENA");
	assert(artist.getNumberOfSeatsAvailable() == 1000);
	assert(artist.getNumberOfSeatsSold() == 1000000);
}

void ArtistTest::testCopyConstructor() {
	Artist artist("Sia", "20.12.2020", "BT ARENA", 1000, 1000000);

	Artist artist02(artist);

	assert(artist02.getName() == "Sia");
	assert(artist02.getDate() == "20.12.2020");
	assert(artist02.getPlace() == "BT ARENA");
	assert(artist02.getNumberOfSeatsAvailable() == 1000);
	assert(artist02.getNumberOfSeatsSold() == 1000000);
}

void ArtistTest::testGetName() {
	Artist artist("Sia", "20.12.2020", "BT ARENA", 1000, 1000000);
	assert(artist.getName() == "Sia");
}

void ArtistTest::testSetName() {
	Artist artist("Sia", "20.12.2020", "BT ARENA", 1000, 1000000);

	artist.setName("Zendaya");

	assert(artist.getName() == "Zendaya");
}

void ArtistTest::testGetDate() {
	Artist artist("Sia", "20.12.2020", "BT ARENA", 1000, 1000000);

	assert(artist.getDate() == "20.12.2020");
}

void ArtistTest::testSetDate() {
	Artist artist("Sia", "20.12.2020", "BT ARENA", 1000, 1000000);

	artist.setDate("20.12.2021");

	assert(artist.getDate() == "20.12.2021");
}

void ArtistTest::testGetPlace() {
	Artist artist("Sia", "20.12.2020", "BT ARENA", 1000, 1000000);

	assert(artist.getPlace() == "BT ARENA");
}

void ArtistTest::testSetPlace() {
	Artist artist("Sia", "20.12.2020", "BT ARENA", 1000, 1000000);

	artist.setPlace("Stadion");

	assert(artist.getPlace() == "Stadion");
}

void ArtistTest::testGetNumberOfSeatsAvailable() {
	Artist artist("Sia", "20.12.2020", "BT ARENA", 1000, 1000000);

	assert(artist.getNumberOfSeatsAvailable() == 1000);
}

void ArtistTest::testSetNumberOfSeatsAvailable() {
	Artist artist("Sia", "20.12.2020", "BT ARENA", 1000, 1000000);

	artist.setNumberOfSeatsAvailable(500);

	assert(artist.getNumberOfSeatsAvailable() == 500);
}

void ArtistTest::testGetNumberOfSeatsSold() {
	Artist artist("Sia", "20.12.2020", "BT ARENA", 1000, 1000000);

	assert(artist.getNumberOfSeatsSold() == 1000000);
}

void ArtistTest::testSetNumberOfSeatsSold() {
	Artist artist("Sia", "20.12.2020", "BT ARENA", 1000, 1000000);

	artist.setNumberOfSeatsAvailable(500);

	assert(artist.getNumberOfSeatsAvailable() == 500);
}

void ArtistTest::testAssignmentOperator() {
	Artist artist("Sia", "20.12.2020", "BT ARENA", 1000, 1000000);
	Artist artist02;

	artist02 = artist;

	assert(artist02.getName() == "Sia");
	assert(artist02.getDate() == "20.12.2020");
	assert(artist02.getPlace() == "BT ARENA");
	assert(artist02.getNumberOfSeatsAvailable() == 1000);
	assert(artist02.getNumberOfSeatsSold() == 1000000);
}

void ArtistTest::testEqualityOperator() {
	Artist artist("Sia", "20.12.2020", "BT ARENA", 1000, 1000000);
	Artist artist02;

	artist02 = artist;

	assert(artist == artist02);
}

void ArtistTest::testClone() {
	Artist artist("Sia", "20.12.2020", "BT ARENA", 1000, 1000000);

	Artist* artistClone = (Artist*)artist.clone();
	assert(artist == *artistClone);
	assert(&artist != artistClone);
}

void ArtistTest::testToString() {
	Artist artist("Sia", "20.12.2020", "BT ARENA", 1000, 1000000);

	assert(artist.toString(" ") == "SHOW Sia* 20.12.2020 BT ARENA* 1000 1000000");
	assert(artist.toString(",") == "SHOW,Sia*,20.12.2020,BT ARENA*,1000,1000000");

	cout << "TEST for Artist class DONE!" << endl;
}
