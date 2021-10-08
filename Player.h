#pragma once

#include <iostream>
#include <vector>

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
    void addBoat(Boat& b);
	void playTurn();
    PlayerType getType() const;
    friend ostream& operator << (ostream& out, Player& p);
    bool hasLost() const;
private:
    PlayerType type;
	vector<Boat *> boats;
	vector<Strike *> strikes;
};