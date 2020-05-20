#pragma once
#include "RepoFile.h"
#include "Festival.h"

class RepoTest {
private:
	const string fileNameInTXT = "TestElementsIn.txt";
	const string fileNameOutTXT = "TestElementsOut.txt";
	const string fileNameInCSV = "TestElementsIn.csv";
	const string fileNameOutCSV = "TestElementsOut.csv";

	vector<Festival*> elementsIn;

	void testGetSize();
	void testGetAll();
	void testGetElement();
	void testAddElement();
	void testUpdateElement();
	void testDeleteElement();

	void testLoadFromFileTXT();
	//void testSaveToFileTXT();
	void testLoadFromFileCSV();
	//void testSaveToFileCSV();
public:
	RepoTest();
	~RepoTest();
	void testAll();
};
