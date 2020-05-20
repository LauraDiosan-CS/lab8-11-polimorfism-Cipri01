#include "Console.h"

int main() {
	cout << "CSV or TXT\n";
	cout << "Option: ";
	string option;
	cin >> option;
	RepoFile<Festival>* repo = NULL;
	if (option.compare("txt") == 0) {
		repo = new RepoFileTXT<Festival>;
		repo->setFileName("elements.txt");
	}
	else if (option.compare("csv") == 0) {
		repo = new RepoFileCSV<Festival>;
		repo->setFileName("TestElementsOut.csv");
	}

	AdminFile af("admins.txt");

	Service service;
	service.setRepo(repo);
	service.setAdmins(af);

	Console console(service);
	console.run();
	return 0;
}
