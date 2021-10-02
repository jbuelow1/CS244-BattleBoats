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
	Boat(Player& owner, int location[3],  int size, Orientation orientation);
	~Boat();
    virtual bool validatePlacement(BattleBoatBoard *b);
	void addStrike(Strike& strike);
	bool isSunk() const;
private:
	int boatSize;
	Orientation orientation;
	Strike* strikes;
	int strikeCount;
};
