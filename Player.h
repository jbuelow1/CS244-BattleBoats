#pragma once

#include "Boat.h"
#include "Strike.h"

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
private:
	Boat* boats;
	Strike* strikes;
};