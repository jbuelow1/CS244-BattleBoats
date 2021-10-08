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

Player* BattleBoatBoard::getWinner(Player* players[]) {
    for (int p = 0; p < Options::PLAYER_COUNT; p++) {
        if (players[p]->hasLost()) {
            return players[!p];
        }
    }
    return nullptr;
}
/**
 * Prints a table representation of the current gameboard.
 * Will use BOXDRAW_... preprocessor directives defined in Options.cpp
 * @param out output stream in
 * @param board reference to the game board
 * @return output stream out
 */
std::ostream& operator<<(std::ostream &out, BattleBoatBoard& board) {
    for (int by = 0; by < ((Options::BOARD_SIZE_Y + 1) * 4) + 1; by++) { // Print line-by-line
        for (int p = 0; p < Options::PLAYER_COUNT; p++) { // Print the board for each character side-by-side
            // This if statement draws characters on the far left of the table
            // These will never be data, only ever the top left corner, bottom left corner,
            // a vertical t, or just a vertical line
            if (by == 0) {
                cout << BOXDRAW_CORNER_UPLEFT;
            } else if (by >= ((Options::BOARD_SIZE_Y + 1) * 4)) {
                cout << BOXDRAW_CORNER_LOWLEFT;
            } else if (by % 4 == 0) {
                cout << BOXDRAW_VERTICAL_T_RIGHT;
            } else {
                cout << BOXDRAW_VERTICAL;
            }

            // This loop draws everything between the far left and far right
            for (int bx = 0; bx < ((Options::BOARD_SIZE_X + 1) * 4) - 1; bx++) {
                if (by % 4 == 0) {
                    // This column is the horizontal border between 2 cells
                    if ((bx + 1) % 4 == 0) {
                        // This is *also* the vertical border between 2 or 4 cells
                        if (by == 0) {
                            // At the top of the table
                            cout << BOXDRAW_HORIZONTAL_T_DOWN;
                        } else if (by >= (Options::BOARD_SIZE_Y + 1) * 4) {
                            // At the bottom of the table
                            cout << BOXDRAW_HORIZONTAL_T_UP;
                        } else {
                            // Four way intersection between 4 cells
                            cout << BOXDRAW_CROSS;
                        }
                    } else {
                        // Just a horizontal border
                        cout << BOXDRAW_HORIZONTAL;
                    }
                } else {
                    if ((bx + 1) % 4 == 0) {
                        // This column is a vertical border, but isnt also a horizontal border. that was caught above
                        cout << BOXDRAW_VERTICAL;
                    } else if ((bx + 3) % 4 == 0) {
                        // spaces horizontally centered in the cell (middle characters)
                        if (by == 2) {
                            // Label cells
                            // Top cell (Letter labels A-J)
                            char letterLabel = ((bx + 1) / 4) + 0x40;
                            cout << letterLabel;
                        } else if (bx < 5 && (by + 2) % 4 == 0) {
                            // Label cells
                            // Left cells (Number labels 1 - 10)
                            cout << ((by + 1) / 4);
                        } else {
                            if ((by + 2) % 4 == 0 && ((bx + 1) / 4) > 0 && ((by + 1) / 4) > 0 &&
                            ((bx + 1) / 4) < Options::BOARD_SIZE_X + 1 && ((by + 1) / 4) < Options::BOARD_SIZE_Y + 1) {
                                // Center of each cell that could potentially contain data
                                if (board.getGrid()[p][((bx + 1) / 4) - 1][((by + 1) / 4) - 1][0] && board.getGrid()[p][((bx + 1) / 4) - 1][((by + 1) / 4) - 1][1]) {
                                    cout << "¤"; // A hit (boat and strike both present)
                                } else if (board.getGrid()[p][((bx + 1) / 4) - 1][((by + 1) / 4) - 1][0]) {
                                    cout << "█"; // A boat
                                } else if (board.getGrid()[p][((bx + 1) / 4) - 1][((by + 1) / 4) - 1][1]) {
                                    cout << "Ø"; // A miss
                                } else {
                                    cout << " "; // Nothing
                                }
                            } else {
                                cout << " "; // Vertical spaces on top of, and on the bottom of the center of each cell
                            }
                        }
                    } else if ((by + 2) % 4 == 0) {
                        // Spaces vertically centered in cell
                        if ((by + 1) / 4 == 10 && bx == 2) { // Prevents printing a space on the right of "10" on the label col
                        } else {
                            cout << " "; // horizontal spaces in each cell
                        }
                    } else {
                        cout << " "; // Corner of each cell
                    }
                }
            }

            // This if statement draws characters on the far right side of the table
            // These will never be data, only ever the top right corner, bottom right corner,
            // a vertical t, or just a vertical line
            if (by == 0) {
                cout << BOXDRAW_CORNER_UPRIGHT;
            } else if (by >= (Options::BOARD_SIZE_Y + 1) * 4) {
                cout << BOXDRAW_CORNER_LOWRIGHT;
            } else if (by % 4 == 0) {
                cout << BOXDRAW_VERTICAL_T_LEFT;
            } else {
                cout << BOXDRAW_VERTICAL;
            }

            // Print the gap between the two tables
            cout << "        ";
        }
        cout << endl;
    }
    return out;
}

vector<vector<vector<vector<BoardPiece *>>>> BattleBoatBoard::getGrid() const {
    return boardGrid;
}
