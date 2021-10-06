#pragma once

#include <iostream>

#include "Boat.h"
#include "Strike.h"

using namespace std;

enum PlayerType {
	HUMAN_A = 0,
	HUMAN_B = 1,
	COMPUTER = -1
};

class Boat;

class Player {
public:
	Player(PlayerType type);
	~Player();
	void playTurn();
    PlayerType getType() const;
    friend ostream& operator << (ostream& out, Player& p);
private:
    PlayerType type;
	Boat* boats;
	Strike* strikes;
};