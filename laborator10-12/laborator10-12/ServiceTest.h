#pragma once

#include "Service.h"

class ServiceTest {
private:
	void testAddArtist();
	void testAddMovie();
	void testGetAll();
	void testGetElement();
	void testUpdateArtist();
	void testUpdateMovie();
	void testDelete();
	void testGetSize();
	void testLogin();
	void testGetPassWordForAnUserName();
	void testGetElementBySearch();
	void testGetMovieOrShowForBuy();
public:
	ServiceTest();
	~ServiceTest();
	void testAll();

};
