#include "BoardPiece.h"

BoardPiece::BoardPiece(int location[3]) {
    this->location[0] = location[0];
    this->location[1] = location[1];
    this->location[2] = location[2];
}

int BoardPiece::getPlayerPos() const {
    return location[0];
}

int BoardPiece::getX() const {
    return location[1];
}

int BoardPiece::getY() const {
    return location[2];
}
