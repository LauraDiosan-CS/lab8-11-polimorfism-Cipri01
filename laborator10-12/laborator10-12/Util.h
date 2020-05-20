#pragma once

#include <string>
#include <vector>

using namespace std;

void getElementsFromString(string& line, string& name, string& date, string& place, int& numberOfSeatsAvailable, int& numberOfSeatsSold, string delim);
void getElementsFromStringInVector(vector<string>& list, string line);
