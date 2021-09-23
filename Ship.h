#pragma once

#include "BoardPiece.h"

enum Orientation {
	VERTICAL,
	HORIZONTAL
};

class Ship : public BoardPiece {
public:
private:
	Orientation orientation;
	bool isSunken;
};
