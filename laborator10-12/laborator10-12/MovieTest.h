#pragma once

class MovieTest {
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
	void testGetListOfActors();
	void testSetListOfActors();
	void testAssignmentOperator();
	void testEqualityOperator();
	void testClone();
	void testToString();
	void testVectorEqual();
	void testVectorToString();
public:
	void testAll();
};
