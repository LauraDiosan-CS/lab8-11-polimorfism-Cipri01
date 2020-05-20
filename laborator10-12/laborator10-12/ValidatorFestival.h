#pragma once
#include <string>
#include "Festival.h"
#include "ValidationException.h"

class ValidatorFestival {
public:
	ValidatorFestival();
	~ValidatorFestival();
	virtual void validate(Festival* festival);
};