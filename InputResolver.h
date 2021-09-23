#pragma once

#include "Ship.h"

class InputResolver {
public:
	int* promptAndResolveBoardLocation();
	Orientation promptAndResolveOrientation();
	bool promptAndResolvePlayAgain();
private:
};

