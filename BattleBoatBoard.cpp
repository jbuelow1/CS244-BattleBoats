#include "BattleBoatBoard.h"

using namespace std;

BattleBoatBoard::BattleBoatBoard(int players, int sizeX, int sizeY) {

    // Initialize the game board with nullptr at all positions
    for (int p = 0; p < players; p++) {
        vector<vector<vector<BoardPiece*>>> indexX{};
        for (int x = 0; x < sizeX; x++) {
            vector<vector<BoardPiece*>> indexY{};
            for (int y = 0; y < sizeY; y++) {
                vector<BoardPiece*> indexI{};
                for (int i = 0; i < 2; i++) {
                    indexI.push_back(nullptr);
                }
                indexY.push_back(indexI);
            }
            indexX.push_back(indexY);
        }
        boardGrid.push_back(indexX);
    }

}

BattleBoatBoard::~BattleBoatBoard() {
    // Delete boat and strike arrays
    for (int i = 0; i < boats.size(); i++) {
        delete boats[i];
    }

    for (int i = 0; i < strikes.size(); i++) {
        delete strikes[i];
    }
}

bool BattleBoatBoard::placeBoat(Boat &s) {
    if (s.validatePlacement(this)) {
        boardGrid[s.getPlayerPos()][s.getX()][s.getY()][0] = &s;
        return true;
    } else {
        return false;
    }
}

bool BattleBoatBoard::placeStrike(Strike &s) {
    // Check that the strike is valid using its computeHit function
    // Retuning true does not mean a hit, but the strike was valid8
    if (s.computeHit(*this)) {
        // Add the strike to the game board and strike list
        boardGrid[s.getPlayerPos()][s.getX()][s.getY()][1] = &s;
        strikes.push_back(&s);
        return true;
    } else {
        return false;
    }
}

Player& BattleBoatBoard::getWinner() {
    //TODO: Implement
    Player p = Player(COMPUTER);
    return p;
}

std::ostream& operator<<(std::ostream &out, BattleBoatBoard board) {
    //TODO: Implement
    cout << "Printing game board not yet implemented" << endl;
    return out;
}

vector<vector<vector<vector<BoardPiece *>>>> BattleBoatBoard::getGrid() const {
    return boardGrid;
}
