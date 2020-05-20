#ifndef FULLVECTOREXCEPTION_H
#define FULLVECTOREXCEPTION_H
#include <stdexcept>
#include <string>

using namespace std;

class FullVectorException :public runtime_error {
private:
	string message;
public:
	FullVectorException(string msg) :
		runtime_error(msg), message(msg) {
	}
	string what() {
		return message;
	}
};
#endif // !FULLVECTOREXCEPTION_H
