#pragma once

#include "GameBoard.h"
#include "Player.h"

class Game {
public:
	void start();
private:
	GameBoard board;
	Player turnOrder[2];
	int turnIndex;
	void runTurnForPlayer(Player);
	bool runRound();
};
