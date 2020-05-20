#include "Util.h"

void getElementsFromString(string& line, string& name, string& date, string& place, int& numberOfSeatsAvailable, int& numberOfSeatsSold, string delim) {
	int pos = line.find("*");
	name = line.substr(0, pos);
	line = line.erase(0, pos + 2);

	pos = line.find(delim);
	date = line.substr(0, pos);
	line = line.erase(0, pos + 1);

	pos = line.find("*");
	place = line.substr(0, pos);
	line = line.erase(0, pos + 2);

	pos = line.find(delim);
	numberOfSeatsAvailable = stoi(line.substr(0, pos));
	line = line.erase(0, pos + 1);

	pos = line.find(delim);
	numberOfSeatsSold = stoi(line.substr(0, pos));
	line = line.erase(0, pos);
}

void getElementsFromStringInVector(vector<string>& list, string line) {
	line = line.erase(0, 1);
	int pos = line.find(";");
	while (pos < line.size()) {
		string element = line.substr(0, pos);
		line = line.erase(0, pos + 1);
		list.push_back(element);
		pos = line.find(";");
	}
	if (line.size())
		list.push_back(line.substr(0, line.size() - 1));
}
