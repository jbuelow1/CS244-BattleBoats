#include "BattleBoatBoard.h"

using namespace std;

BattleBoatBoard::BattleBoatBoard(int players, int sizeX, int sizeY) {
    //TODO: Implement
}

BattleBoatBoard::~BattleBoatBoard() {
    //TODO: Implement
}

bool BattleBoatBoard::placeShip(Boat &s) {
    //TODO: Implement
    return false;
}

bool BattleBoatBoard::placeStrike(Strike &s) {
    //TODO: Implement
    return false;
}

Player &BattleBoatBoard::getWinner() {
    //TODO: Implement
    return Player(COMPUTER);
}

std::ostream &operator<<(std::ostream &out, BattleBoatBoard board) {
    //TODO: Implement
    cout << "Printing game board not yet implemented" << endl;
    return out;
}
