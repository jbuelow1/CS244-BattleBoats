#pragma once

//TODO: this is commented out to prevent an error with BoardPiece, Strike and Boat that I do not want to deal with right now
//#include "Player.h"

class BattleBoatBoard;

class BoardPiece {
public:
    BoardPiece(int location[3]);
    int getPlayerPos() const;
    int getX() const;
    int getY() const;
private:
	//Player& owner;
	int location[3];
};

