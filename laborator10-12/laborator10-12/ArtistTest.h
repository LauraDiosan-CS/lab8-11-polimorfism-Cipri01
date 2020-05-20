#pragma once

class ArtistTest {
private:
	void testImplicitConstructor();
	void testConstructorWithParameters();
	void testCopyConstructor();
	void testGetName();
	void testSetName();
	void testGetDate();
	void testSetDate();
	void testGetPlace();
	void testSetPlace();
	void testGetNumberOfSeatsAvailable();
	void testSetNumberOfSeatsAvailable();
	void testGetNumberOfSeatsSold();
	void testSetNumberOfSeatsSold();
	void testAssignmentOperator();
	void testEqualityOperator();
	void testClone();
	void testToString();
public:
	void testAll();
};
