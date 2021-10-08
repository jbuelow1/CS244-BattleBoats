#pragma once

#include "Boat.h"

enum TurnAction {
    SKIP = 0,
    STRIKE = 1,
    SPECIAL = 2
};

class InputResolver {
public:
	int* promptAndResolveBoardLocation();
	Orientation promptAndResolveOrientation();
	bool promptAndResolvePlayAgain();
    TurnAction promptAndResolveTurnAction();
private:
};

