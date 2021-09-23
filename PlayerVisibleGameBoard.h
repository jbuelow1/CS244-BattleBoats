#pragma once

#include <iostream>

#include "BattleBoatBoard.h"

class PlayerVisibleGameBoard : public BattleBoatBoard {
public:
	friend ostream& operator << (ostream& out, PlayerVisibleGameBoard board);
	void setOwner(Player& owner);
private:
	Player& owner;
};
