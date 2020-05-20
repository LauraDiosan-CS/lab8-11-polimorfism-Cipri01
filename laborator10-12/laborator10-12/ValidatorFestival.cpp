#include "ValidatorFestival.h"

ValidatorFestival::ValidatorFestival() {}

ValidatorFestival::~ValidatorFestival() {}

void ValidatorFestival::validate(Festival* festival) {
	if (festival->getName().empty())
		throw ValidationException("Name can't be empty!");

	if (festival->getDate().empty())
		throw ValidationException("Date can't be empty!");

	if (festival->getPlace().empty())
		throw ValidationException("Place can't be empty!");

	if (festival->getNumberOfSeatsAvailable() < 0)
		throw ValidationException("Number of seats available can't be a negative number!");

	if (festival->getNumberOfSeatsSold() < 0)
		throw ValidationException("Number of seats sold can't be a negative number!");
}
