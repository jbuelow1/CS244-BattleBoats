#include "BoardPiece.h"

BoardPiece::BoardPiece(int location[3]) {
    //TODO: Implement
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
