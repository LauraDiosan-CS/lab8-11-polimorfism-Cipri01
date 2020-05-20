#ifndef EMPTYVECTOREXCEPTION_H
#define EMPTYVECTOREXCEPTION_H
#include <stdexcept>
#include <string>

using namespace std;

class EmptyVectorException : public runtime_error {
private:
	string message;
public:
	EmptyVectorException(string msg) :
		runtime_error(msg), message(msg) {
	}
	string what() {
		return message;
	}
};
#endif // !EMPTYVECTOREXCEPTION_H
