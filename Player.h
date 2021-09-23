#pragma once

#include "Boat.h"
#include "Strike.h"

enum PlayerType {
	HUMAN_A,
	HUMAN_B,
	COMPUTER
};

class Player {
public:
	Player(PlayerType type);
	~Player();
	void playTurn();
private:
	Boat* boats;
	Strike* strikes;
};