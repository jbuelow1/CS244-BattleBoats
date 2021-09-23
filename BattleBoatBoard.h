#pragma once

#include <iostream>

#include "Boat.h"
#include "Strike.h"
#include "PlayerVisibleGameBoard.h"

class BattleBoatBoard {
public:
	bool placeShip(Boat& s);
	bool placeStrike(Strike& s);
	Player& getWinner();
	PlayerVisibleGameBoard getPlayerBoard(Player& player);
	friend ostream& operator << (ostream& out, BattleBoatBoard board);
private:
	Boat* ships;
	Strike* strikes;
	BoardPiece* boardGrid; //3 dimensional array of objects on the gameboard [x][y][i]
};
