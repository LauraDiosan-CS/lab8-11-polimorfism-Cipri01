#pragma once
#include <vector>
#include <string>

using namespace std;

template <class T>
class RepoFile {
protected:
	vector<T*> elements;
	string fileName;
public:
	RepoFile();
	RepoFile(string fileName);
	~RepoFile();

	void setFileName(string fileName);

	vector<T*> getAll();
	int getSize();
	T* getElement(int pos);
	T* getElementOriginal(int pos);
	void addElement(T* element);
	void updateElement(T* oldElement, T* newElement);
	void deleteElement(T* element);

	void emptyRepo();

	virtual void loadFromFile() = 0;
	virtual void saveToFile() = 0;
};

template<class T>
inline RepoFile<T>::RepoFile() {}

template<class T>
inline RepoFile<T>::RepoFile(string fileName) {
	this->fileName = fileName;
}

template<class T>
inline RepoFile<T>::~RepoFile() {}

template<class T>
inline void RepoFile<T>::setFileName(string fileName) {
	this->fileName = fileName;
}

template<class T>
inline vector<T*> RepoFile<T>::getAll() {
	return this->elements;
}

template<class T>
inline int RepoFile<T>::getSize() {
	return this->elements.size();
}

template<class T>
inline T* RepoFile<T>::getElement(int pos) {
	if (pos >= 0 && pos < this->getSize())
		return this->elements[pos]->clone();
}

template<class T>
inline T* RepoFile<T>::getElementOriginal(int pos) {
	if (pos >= 0 && pos < this->getSize())
		return this->elements[pos];
}

template<class T>
inline void RepoFile<T>::addElement(T* element) {
	this->loadFromFile();
	this->elements.push_back(element);
	this->saveToFile();
}

template<class T>
inline void RepoFile<T>::updateElement(T* oldElement, T* newElement) {
	for (int i = 0; i < this->getSize(); i++) {
		if (*(this->getElement(i)) == *oldElement) {
			delete this->elements[i];
			this->elements[i] = newElement->clone();
			this->saveToFile();
			return;
		}
	}
}

template<class T>
inline void RepoFile<T>::deleteElement(T* element) {
	for (int i = 0; i < this->getSize(); i++) {
		if (**(this->elements.begin() + i) == *element) {
			delete this->elements[i];
			this->elements.erase(this->elements.begin() + i);
			this->saveToFile();
			return;
		}
	}
}

template<class T>
inline void RepoFile<T>::emptyRepo() {
	for (int i = 0; i < this->getSize(); i++)
		delete this->elements[i];
	this->elements.clear();
}
