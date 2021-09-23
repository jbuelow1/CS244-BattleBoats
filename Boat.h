#pragma once

#include "BoardPiece.h"

enum Orientation {
	VERTICAL,
	HORIZONTAL
};

class Boat : public BoardPiece {
public:
private:
	Orientation orientation;
	bool isSunken;
};
