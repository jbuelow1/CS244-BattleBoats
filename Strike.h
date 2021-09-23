#pragma once

#include "BoardPiece.h"
#include "Player.h"

class Strike : public BoardPiece {
public:
	Strike(int location[], Player& owner);
	void computeHit(BattleBoatBoard board);
	bool getIsHit() const;
private:
	bool isHit;
};

