#pragma once

#include <iostream>

#include "Ship.h"
#include "Strike.h"
#include "PlayerVisibleGameBoard.h"

class GameBoard {
public:
	bool placeShip(Ship& s);
	bool placeStrike(Strike& s);
	Player& getWinner();
	PlayerVisibleGameBoard getPlayerBoard(Player& player);
	friend ostream& operator << (ostream& out, GameBoard board);
private:
	Ship* ships;
	Strike* strikes;
	BoardPiece* boardGrid; //3 dimensional array of objects on the gameboard [x][y][i]
};
