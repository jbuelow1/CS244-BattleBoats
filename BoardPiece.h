#pragma once



class BattleBoatBoard;

class BoardPiece {
public:
    BoardPiece(int location[3]);
    int getPlayerPos() const;
    int getX() const;
    int getY() const;
private:
	//Player& owner; // was causing too many problems with cyclic includes, so was disabled pretty early on
	int location[3];
};

