#pragma once

#include <iostream>

#include "Boat.h"
#include "Strike.h"
#include "PlayerVisibleGameBoard.h"

class BattleBoatBoard {
public:
	BattleBoatBoard(int players, int sizeX, int sizeY);
	~BattleBoatBoard();
	bool placeShip(Boat& s);
	bool placeStrike(Strike& s);
	Player& getWinner();
	PlayerVisibleGameBoard getPlayerBoard(Player& player);
	friend ostream& operator << (ostream& out, BattleBoatBoard board);
private:
	Boat* ships;
	Strike* strikes;
	BoardPiece* boardGrid[2][10][10][2]; //4 dimensional array of objects on the gameboard [x][y][i]
};
