#ifndef INDEXOUTOFBOUNDSEXCEPTION_H
#define INDEXOUTOFBOUNDSEXCEPTION_H
#include <stdexcept>

using namespace std;

class IndexOutOfBoundsException :
	public runtime_error {
private:
	string message;
public:
	IndexOutOfBoundsException(string msg) :
		runtime_error(msg), message(msg) {
	}
	string what() {
		return message;
	}
};
#endif // !INDEXOUTOFBOUNDSEXCEPTION_H
