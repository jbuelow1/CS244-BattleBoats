#include "Boat.h"

Boat::Boat(Player &owner, int location[3], int size, Orientation orientation) : BoardPiece(location) {
    this->boatSize = size;
    this->orientation = orientation;
}

Boat::~Boat() {
    //TODO: Implement
}

void Boat::addStrike(Strike &strike) {
    //TODO: Implement
}

bool Boat::isSunk() const {
    //TODO: Implement
    return false;
}

bool Boat::validatePlacement(BattleBoatBoard *b) {
    for (int i = 0; i < boatSize; i++) {
        int x,y;
        if (orientation == VERTICAL) {
            x = getX();
            y = getY() + i;
        } else {
            x = getX() + i;
            y = getY();
        }

        if (!(b->getGrid()[getPlayerPos()][x][y][0] == nullptr)) {
            return false;
        }
    }
    return true;
}

int Boat::getSize() const {
    return boatSize;
}

int Boat::getOrientation() const {
    return orientation;
}
