#include "ValidatorArtist.h"
#include "Artist.h"
#include "ValidationException.h"

ValidatorArtist::ValidatorArtist() {}

ValidatorArtist::~ValidatorArtist() {}

void ValidatorArtist::validate(Festival* festival) {
	ValidatorFestival::validate(festival);
	//Artist* artist = (Artist*)festival;
}
