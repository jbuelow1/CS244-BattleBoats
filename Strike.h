#pragma once

#include "BoardPiece.h"
#include "Player.h"
#include "BattleBoatBoard.h"

class Player;

class BattleBoatBoard;

class Strike : public BoardPiece {
public:
	Strike(Player& owner, int location[2][10][10]);
	void computeHit(BattleBoatBoard board);
	bool getIsHit() const;
private:
	bool isHit;
};

