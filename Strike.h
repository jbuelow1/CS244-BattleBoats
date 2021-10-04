#pragma once

#include "BoardPiece.h"
#include "Player.h"
#include "BattleBoatBoard.h"
#include "Boat.h"

class Player;

class BattleBoatBoard;

class Boat;

class Strike : public BoardPiece {
public:
	Strike(Player &owner, int location[3]);
	bool computeHit(BattleBoatBoard& board);
	bool getIsHit() const;
    bool wouldHit(Boat& b);
private:
	bool isHit;
};

