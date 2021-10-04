#include "Strike.h"

Strike::Strike(Player &owner, int location[3]) : BoardPiece(location) {

}

bool Strike::computeHit(BattleBoatBoard& board) {
    // Verify that a strike is not already at this location
    if (board.getGrid()[getPlayerPos()][getX()][getY()][1] != nullptr) {
        return false;
    }


    // Grab a pointer for the boat at the strike location
    BoardPiece* boatPiecePtr = board.getGrid()[getPlayerPos()][getX()][getY()][0];

    // Determine if shot is a hit or miss by checking the BoardPiece pointer in the boat index
    if (boatPiecePtr == nullptr) { // If no boat at strike location
        // Shot is a miss
        isHit = false;
    } else {
        // Shot is a hit
        isHit = true;

        // Because this is a hit, attach strike to hit boat
        Boat* boatPtr = static_cast<Boat*>(boatPiecePtr);
        boatPtr->addStrike(*this);
    }

    return true;
}

bool Strike::getIsHit() const {
    //TODO: Implement
    return false;
}
