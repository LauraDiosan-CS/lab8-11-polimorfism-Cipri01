#pragma once
#include "ValidatorFestival.h"

class ValidatorMovie : public ValidatorFestival {
public:
	ValidatorMovie();
	~ValidatorMovie();
	void validate(Festival* festival);
};