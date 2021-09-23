#pragma once

#include "BattleBoatBoard.h"
#include "Player.h"

class BattleBoatGame {
public:
	void playGame();
private:
	BattleBoatBoard board;
	Player turnOrder[2];
	int turnIndex;
	void runTurnForPlayer(Player);
	bool runRound();
};
