#pragma once

#include <iostream>
#include <vector>

#include "Boat.h"
#include "Strike.h"

using namespace std;

class Boat;
class Strike;
class Player;

class BattleBoatBoard {
public:
	BattleBoatBoard(int players, int sizeX, int sizeY);
	~BattleBoatBoard();
	bool placeBoat(Boat& b);
	bool placeStrike(Strike& s);
	Player& getWinner();
	//PlayerVisibleGameBoard getPlayerBoard(Player& player);
    vector<vector<vector<vector<BoardPiece*>>>> getGrid() const;
	friend ostream& operator << (ostream& out, BattleBoatBoard& board);

    bool hasWinner();

private:
    vector<Boat*> boats;
    vector<Strike*> strikes;
	vector<vector<vector<vector<BoardPiece*>>>> boardGrid; //4 dimensional array of objects on the gameboard [p][x][y][i]
};
