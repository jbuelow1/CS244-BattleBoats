#include "Boat.h"
#include "Options.cpp"

Boat::Boat(Player &owner, int location[3], int size, Orientation orientation) : BoardPiece(location) {
    this->boatSize = size;
    this->orientation = orientation;
}

Boat::~Boat() {
    // While this class maintains a list of pointers to strikes, the BattleBoatBoard class also maintains a list, and is
    //  deemed responsible for deleting these when that destructor is called
}

void Boat::addStrike(Strike &strike) {
    strikes.push_back(&strike);
}

bool Boat::isSunk() {
    return strikes.size() >= boatSize;
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

        // Verify that the boat has valid position
        if (x < 0 || y < 0) {
            return false;
        }

        // Verify that the boat does not "hang off" the game board
        if (x >= Options::BOARD_SIZE_X ||
            y >= Options::BOARD_SIZE_Y) {
            return false;
        }

        if (b->getGrid()[getPlayerPos()][x][y][0] != nullptr) {
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
