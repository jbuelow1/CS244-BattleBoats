#pragma once

#include "BoardPiece.h"

enum Orientation {
	VERTICAL,
	HORIZONTAL
};

class Boat : public BoardPiece {
public:
private:
	int boatSize;
	Orientation orientation;
	Strike* strikes;
	int strikeCount;
	bool isSunken;
};
