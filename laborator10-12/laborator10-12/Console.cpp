#include "Console.h"
#include "EmptyVectorException.h"
#include "FullVectorException.h"

Console::Console() {}

Console::Console(Service service) {
	this->service = service;
}

Console::~Console() {}

void Console::menuLogin() {
	cout << endl;
	cout << "---------------------------------------------------" << endl;
	cout << "      | LOGIN | " << endl;
	cout << "---------------------------------------------------" << endl;
	cout << "Options: " << endl;
	cout << " 0 -> Login <-" << endl;
	cout << " 1 -> Creare account <-" << endl;
	cout << " 2 -> EXIT! <-" << endl;
}

void Console::menuApp() {
	cout << endl;
	cout << "---------------------------------------------------" << endl;
	cout << "      | MENU | " << endl;
	cout << "---------------------------------------------------" << endl;
	cout << "Options: " << endl;
	cout << " 0 -> Logout <-" << endl;
	cout << " 1 -> Search show or movie <-" << endl;
	cout << " 2 -> Buy ticket <-" << endl;
	cout << " 3 -> Other (add, delete, update, show all, test) <-" << endl;
	cout << " 4 -> EXIT! <- " << endl;
}

void Console::menuCRUD() {
	cout << endl;
	cout << "---------------------------------------------------" << endl;
	cout << "      | CRUD OPERATIONS AND TESTS | " << endl;
	cout << "---------------------------------------------------" << endl;
	cout << "Options: " << endl;
	cout << " 0 -> Add artist <-" << endl;
	cout << " 1 -> Add  movie <-" << endl;
	cout << " 2 -> Delete artist <-" << endl;
	cout << " 3 -> Delete movie <-" << endl;
	cout << " 4 -> Show all <-" << endl;
	cout << " 5 -> Test all <-" << endl;
	cout << " 6 -> EXIT! <-" << endl;
}

void Console::login(bool &ok) {
	ok = false;
	cout << "Give userName: ";
	string userName;
	cin >> userName;

	string goodPassWord = service.getPassWordForAnUserName(userName);

	if (goodPassWord == "none") {
		cout << "This userName is non-existent!" << endl;
		cout << "You need to create an account!" << endl;
	}
	else {
		cout << "Give passWord: ";
		string passWord;
		cin >> passWord;
		if (service.login(userName, passWord) == false) {
			cout << "Wrong passWord!" << endl;
		}
		else {
			ok = true;
			try {
				cout << endl << "Welcome!" << endl;;
				vector<Festival*> vect = service.getAll();
				for (int i = 0; i < service.getSize(); i++) {
					cout << vect[i]->toString(" ") << endl;
				}
			}
			catch (EmptyVectorException& exc) {
				cout << "exception: " << exc.what() << endl;
			}
		}
	}
}

void Console::createAccount() {
	cout << "Welcome!" << endl;
	cout << "Give an userName: ";
	string userName;
	cin >> userName;

	cout << "Give a passWord: ";
	string passWord;
	cin >> passWord;

	service.addAdmin(userName, passWord);

	cout << "Now you have an account!" << endl;
}

void Console::run() {
	bool shouldRun = true;
	int option;
	while (shouldRun) {
		bool ok = false;
		this->menuLogin();
		cout << "Give option: ";
		cin >> option;
		switch (option) {
			case 0: {
				this->login(ok);
				if (ok == false)
					cout << "Try again! " << endl;
				else
					this->runMENU();
				break;
			}
			case 1: {
				this->createAccount();
				break;
			}
			case 2: {
				shouldRun = false;
				break;
			}
			default: {
				cout << "Wrong option! " << endl;
				break;
			}
		}
	}
}

void Console::runMENU() {
	bool shouldRun = true;
	int option;
	while (shouldRun) {
		this->menuApp();
		cout << "Give option: ";
		cin >> option;
		switch (option) {
			case 0: {
				cout << "Logout!..." << endl;
				shouldRun = false;
				break;
			}
			case 1: {
				this->search();
				break;
			}
			case 2: {
				this->buy();
				break;
			}
			case 3: {
				this->runCRUD();
				break;
			}
			case 4: {
				shouldRun = false;
				break;
			}
			default: {
				cout << "Wrong option!" << endl;
				break;
			}
		}
	}
}

void Console::search() {
	cout << "Give the date for search: ";
	string date;
	cin >> date;
	vector<Festival*> vect = service.getElementBySearch(date);
	for (int i = 0; i < vect.size(); i++) {
		cout << vect[i]->toString(" ") << endl;
	}
}

void Console::buy() {
	cout << "Movie or Artist name: ";
	string name;
	cin >> name;

	cout << "Buyer name: ";
	string buyer;
	cin >> buyer;

	cout << "Number of seats: ";
	int numberOfSeats;
	cin >> numberOfSeats;

	service.getMovieOrShowForBuy(name, numberOfSeats);
}

void Console::runCRUD() {
	bool shouldRun = true;
	int option;
	while (shouldRun) {
		this->menuCRUD();
		cout << "Give option: ";
		cin >> option;
		switch (option) {
			case 0: {
				this->addArtist();
				break;
			}
			case 1: {
				this->addMovie();
				break;
			}
			case 2: {
				this->deleteArtist();
				break;
			}
			case 3: {
				this->deleteMovie();
				break;
			}
			case 4: {
				this->showAll();
				break;
			}
			case 5: {
				this->tests();
				break;
			}
			case 6: {
				shouldRun = false;
				break;
			}
			default: {

			}
		}
	}
}

void Console::addArtist() {
	string name, date, place;
	int numberAvailable, numberSold;

	cout << "Give artist name: ";
	cin >> name;
	cout << "Give show date: ";
	cin >> date;

	cout << "Give show place: ";
	cin >> place;

	cout << "Give number of seats available: ";
	cin >> numberAvailable;

	cout << "Give number of seats sold: ";
	cin >> numberSold;

	try {
		service.addArtist(name, date, place, numberAvailable, numberSold);
	}
	catch (ValidationException& exc) {
		cout << "exception: " << exc.what() << endl;
	}
	catch (FullVectorException & exc) {
		cout << "exception: " << exc.what() << endl;
	}
	catch (...) {
		cout << "other problem..." << endl;
	}
	
	cout << "Artist added! " << endl;
}

void Console::addMovie() {
	string name, date, place;
	int numberAvailable, numberSold;

	cout << "Give movie name: ";
	cin >> name;

	cout << "Give movie date: ";
	cin >> date;

	cout << "Give movie place: ";
	cin >> place;

	cout << "Give number of seats available: ";
	cin >> numberAvailable;

	cout << "Give number of seats sold: ";
	cin >> numberSold;

	vector<string> listOfActors;
	
	cout << "Actors number: ";
	int number;
	cin >> number;
	for (int i = 0; i < number; i++) {
		string nameAct;
		cout << "Actor name: ";
		cin >> nameAct;
		listOfActors.push_back(nameAct);
	}

	try {
		service.addMovie(name, listOfActors, date, place, numberAvailable, numberSold);
	}
	catch (ValidationException& exc) {
		cout << "exception: " << exc.what() << endl;
	}
	catch (FullVectorException& exc) {
		cout << "exception: " << exc.what() << endl;
	}
	catch (...) {
		cout << "other problem..." << endl;
	}

	cout << "Movie added! " << endl;
}

void Console::deleteArtist() {
	cout << "Give artist name for delete: ";
	string name;
	cin >> name;

	service.deleteElement(name);

	cout << "Artist deleted!" << endl;
}

void Console::deleteMovie() {
	cout << "Give movie name for delete: ";
	string name;
	cin >> name;

	service.deleteElement(name);

	cout << "Movie deleted!" << endl;
}

void Console::showAll() {
	try {
		vector<Festival*> all;
		all = service.getAll();
		for (int i = 0; i < all.size(); i++) {
			cout << all[i]->toString(" ") << endl;
		}
	}
	catch (EmptyVectorException& exc) {
		cout << "exception: " << exc.what() << endl;
	}
	catch (...) {
		cout << "other problem..." << endl;
	}
}

void Console::tests() {
	ArtistTest artist;
	MovieTest movie;
	RepoTest repo;
	ServiceTest service;
	AdminTest admin;
	AdminFileTest adminFile;

	cout << "--------------------------------------" << endl;
	cout << "    | TESTS | " << endl;
	cout << "--------------------------------------" << endl;
	cout << endl;
	artist.testAll();
	movie.testAll();
	repo.testAll();
	service.testAll();
	admin.testAll();
	adminFile.testAll();
	cout << endl;
}