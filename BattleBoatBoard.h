#pragma once

#include <iostream>
#include <vector>

#include "Boat.h"
#include "Strike.h"

using namespace std;

class BattleBoatBoard {
public:
	BattleBoatBoard(int players, int sizeX, int sizeY);
	~BattleBoatBoard();
	bool placeShip(Boat& s);
	bool placeStrike(Strike& s);
	Player& getWinner();
	//PlayerVisibleGameBoard getPlayerBoard(Player& player);
	friend ostream& operator << (ostream& out, BattleBoatBoard board);
private:
	Boat* ships;
	Strike* strikes;
	vector<vector<vector<vector<BoardPiece*>>>> boardGrid; //4 dimensional array of objects on the gameboard [p][x][y][i]
};
