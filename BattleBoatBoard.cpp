#include "BattleBoatBoard.h"

using namespace std;

BattleBoatBoard::BattleBoatBoard(int players, int sizeX, int sizeY) {
    for (int p = 0; p < players; p++) {
        for (int x = 0; x < sizeX; x++) {
            for (int y = 0; y < sizeY; y++) {
                for (int i = 0; i < 2; i++) {
                    boardGrid[p][x][y][i] = nullptr;
                }
            }
        }
    }

}

BattleBoatBoard::~BattleBoatBoard() {
    for (int p = 0; p < boardGrid.size(); p++) {
        for (int x = 0; x < boardGrid[0].size(); x++) {
            for (int y = 0; y < boardGrid[0][0].size(); y++) {
                for (int i = 0; i < 2; i++) {
                    delete boardGrid[p][x][y][i];
                }
            }
        }
    }
}

bool BattleBoatBoard::placeShip(Boat &s) {
    if (s.validatePlacement(this)) {
        boardGrid[s.getPlayerPos()][s.getX()][s.getY()][0] = &s;
        return true;
    } else {
        return false;
    }
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
