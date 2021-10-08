#include "Boat.h"

Boat::Boat(Player &owner, int location[3], int size, Orientation orientation) : BoardPiece(location) {
    this->boatSize = size;
    this->orientation = orientation;
}

Boat::~Boat() {
    //TODO: Implement
}

void Boat::addStrike(Strike &strike) {
    strikes.push_back(&strike);
}

bool Boat::isSunk() const {
    return strikes.size() >= boatSize;
    // TODO: Now would be a good time to verify that all the attached strikes would actually hit this boat
    //  This should already be guarded against in other functions tho
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
