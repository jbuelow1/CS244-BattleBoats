#pragma once

#include <iostream>

#include "GameBoard.h"

class PlayerVisibleGameBoard : public GameBoard {
public:
	friend ostream& operator << (ostream& out, PlayerVisibleGameBoard board);
	void setOwner(Player& owner);
private:
	Player& owner;
};
