#pragma once

#include "BoardPiece.h"

enum Orientation {
	VERTICAL,
	HORIZONTAL
};

class Boat : public BoardPiece {
public:
	Boat(int size, Orientation orientation);
	~Boat();
	void addStrike(Strike& strike);
	bool isSunk() const;
private:
	int boatSize;
	Orientation orientation;
	Strike* strikes;
	int strikeCount;
};
