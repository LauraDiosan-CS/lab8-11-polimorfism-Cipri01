#pragma once
#include "Admin.h"

class AdminTest {
private:
	void testImplicitConstructor();
	void testConstructorWithParameters();
	void testCopyConstructor();
	void testGetUserName();
	void testSetUserName();
	void testGetPassWord();
	void testSetPassWord();
	void testAssignmentOperator();
	void testEqualityOperator();
	void testToString();
public:
	void testAll();
};
