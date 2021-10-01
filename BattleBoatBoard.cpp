#include "BattleBoatBoard.h"

BattleBoatBoard::BattleBoatBoard(int players, int sizeX, int sizeY) {

}

BattleBoatBoard::~BattleBoatBoard() {

}

bool BattleBoatBoard::placeShip(Boat &s) {
    return false;
}

bool BattleBoatBoard::placeStrike(Strike &s) {
    return false;
}

Player &BattleBoatBoard::getWinner() {
    return <#initializer#>;
}

std::ostream &operator<<(std::ostream &out, BattleBoatBoard board) {
    return <#initializer#>;
}
