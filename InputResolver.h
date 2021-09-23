#pragma once

#include "Boat.h"

class InputResolver {
public:
	int* promptAndResolveBoardLocation();
	Orientation promptAndResolveOrientation();
	bool promptAndResolvePlayAgain();
private:
};

