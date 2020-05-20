#pragma once
#include "Service.h"
#include "ArtistTest.h"
#include "MovieTest.h"
#include "RepoTest.h"
#include "ServiceTest.h"
#include "AdminTest.h"
#include "AdminFileTest.h"

class Console {
private:
	Service service;

	void menuLogin();
	void menuApp();
	void menuCRUD();

	void login(bool &ok);
	void createAccount();

	void addArtist();
	void addMovie();

	void deleteArtist();
	void deleteMovie();

	//void updateArtist();
	//void updateMovie();

	void showAll();

	void search();
	void buy();

	//void tests();
	void runMENU();
	void runCRUD();

public:
	Console();
	Console(Service service);
	~Console();

	void run();
	void tests();
};
