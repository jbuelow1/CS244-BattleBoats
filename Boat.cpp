#include "Boat.h"

Boat::Boat(Player &owner, int location[3], int size, Orientation orientation) : BoardPiece(location) {
    //TODO: Implement
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
    return false;
}
