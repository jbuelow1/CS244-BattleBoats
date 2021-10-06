#pragma once

#include "BoardPiece.h"
#include "Player.h"

enum Orientation {
	VERTICAL,
	HORIZONTAL
};

class Player;
class Strike;

class Boat : public BoardPiece {
public:
	Boat(Player& owner, int* location,  int size, Orientation orientation);
	~Boat();
    virtual bool validatePlacement(BattleBoatBoard *b);
	void addStrike(Strike& strike);
	bool isSunk() const;
    int getSize() const;
    int getOrientation() const;
private:
	int boatSize;
	Orientation orientation;
	Strike* strikes;
	int strikeCount;
};
