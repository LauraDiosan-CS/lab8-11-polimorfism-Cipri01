#include "ValidatorMovie.h"
#include "Movie.h"
#include "ValidationException.h"

ValidatorMovie::ValidatorMovie() {}

ValidatorMovie::~ValidatorMovie() {}

void ValidatorMovie::validate(Festival* festival) {
	ValidatorFestival::validate(festival);
	Movie* movie = (Movie*)festival;
	if (movie->getListOfActors().size() == 0)
		throw ValidationException("List of actors can't be empty");
	for (int i = 0; i < movie->getListOfActors().size(); i++) {
		if (movie->getListOfActors()[i].empty())
			throw ValidationException("Each actor must be a string!");
	}
}
