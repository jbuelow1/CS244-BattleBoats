#include <iomanip>

#include "BattleBoatBoard.h"
#include "Options.cpp"

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
        for (int i = 0; i < s.getSize(); i++) {
            int x,y;
            if (s.getOrientation() == VERTICAL) {
                x = s.getX();
                y = s.getY() + i;
            } else {
                x = s.getX() + i;
                y = s.getY();
            }

            boardGrid[s.getPlayerPos()][x][y][0] = &s;
        }
        boats.push_back(&s);
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

// TODO: Document this abomination
// TODO: These box drawing chars dont work on windows. find an alternative!
// TODO: Fix bug where anything in column J doesnt display
// TODO: Fix bug where placing a strike in column J crashes
// TODO: Fix bug where anything in row 10 doesnt display
std::ostream& operator<<(std::ostream &out, BattleBoatBoard board) {
    for (int by = 0; by < ((Options::BOARD_SIZE_Y + 1) * 4) + 1; by++) {
        for (int p = 0; p < Options::PLAYER_COUNT; p++) {
            if (by == 0) {
                cout << "╔";
            } else if (by >= ((Options::BOARD_SIZE_Y + 1) * 4)) {
                cout << "╚";
            } else if (by % 4 == 0) {
                cout << "╠";
            } else {
                cout << "║";
            }

            for (int bx = 0; bx < ((Options::BOARD_SIZE_X + 1) * 4) - 1; bx++) {
                if (by % 4 == 0) {
                    if ((bx + 1) % 4 == 0) {
                        if (by == 0) {
                            cout << "╦";
                        } else if (by >= (Options::BOARD_SIZE_Y + 1) * 4) {
                            cout << "╩";
                        } else {
                            cout << "╬";
                        }
                    } else {
                        cout << "═";
                    }
                } else {
                    if ((bx + 1) % 4 == 0) {
                        cout << "║";
                    } else if ((bx + 3) % 4 == 0) {
                        // vertical/center data in each cell
                        if (by == 2) {
                            // Top cell
                            char letterLabel = ((bx + 1) / 4) + 0x40;
                            cout << letterLabel;
                        } else if (bx < 5 && (by + 2) % 4 == 0) {
                            // Left cell
                            cout << ((by + 1) / 4);
                        } else {
                            if ((by + 2) % 4 == 0 && ((bx + 1) / 4) > 0 && ((by + 1) / 4) > 0 &&
                            ((bx + 1) / 4) < Options::BOARD_SIZE_X && ((by + 1) / 4) < Options::BOARD_SIZE_Y) {
                                if (board.getGrid()[p][((bx + 1) / 4) - 1][((by + 1) / 4) - 1][0] && board.getGrid()[p][((bx + 1) / 4) - 1][((by + 1) / 4) - 1][1]) {
                                    cout << "¤"; // A hit
                                } else if (board.getGrid()[p][((bx + 1) / 4) - 1][((by + 1) / 4) - 1][0]) {
                                    cout << "█"; // A boat
                                } else if (board.getGrid()[p][((bx + 1) / 4) - 1][((by + 1) / 4) - 1][1]) {
                                    cout << "Ø"; // A miss
                                } else {
                                    cout << " ";
                                }
                            } else {
                                cout << " "; // Vertical and center data in each cell
                            }
                        }
                    } else if ((by + 2) % 4 == 0) {
                        if ((by + 1) / 4 == 10 && bx == 2) { // Prevents printing a space on the right of "10" on the label col
                        } else {
                            cout << " "; // horizontal data in each cell
                        }
                    } else {
                        cout << " "; // Corner of each cell
                    }
                }
            }

            if (by == 0) {
                cout << "╗";
            } else if (by >= (Options::BOARD_SIZE_Y + 1) * 4) {
                cout << "╝";
            } else if (by % 4 == 0) {
                cout << "╣";
            } else {
                cout << "║";
            }
            cout << "        ";
        }
        cout << endl;
    }
    return out;
}

vector<vector<vector<vector<BoardPiece *>>>> BattleBoatBoard::getGrid() const {
    return boardGrid;
}

bool BattleBoatBoard::hasWinner() {
    return false; //TODO
}
