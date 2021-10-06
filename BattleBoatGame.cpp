#include "BattleBoatGame.h"
#include "Options.cpp"
#include "Player.h"

BattleBoatGame::BattleBoatGame() {
    board = new BattleBoatBoard(Options::PLAYER_COUNT, Options::BOARD_SIZE_X, Options::BOARD_SIZE_Y);
    turnOrder[0] = new Player(HUMAN_A);
    turnOrder[1] = new Player(HUMAN_B);
}

BattleBoatGame::~BattleBoatGame() {
    delete board;
    delete turnOrder[0];
    delete turnOrder[1];

}

void BattleBoatGame::playGame() {
    setupGame();

    bool gameRunning{true};
    int turn{0};
    while (gameRunning) {

        runRound();

        // Exit conditions: a player has won
        if (board->hasWinner()) {
            gameRunning = false;
        }
    }
}

/**
 * Setup helper function; prompts and places all boats for a given player
 * @param p player to place boats for
 */
void BattleBoatGame::placeBoats(Player& p) {
    for (int size : Options::BOAT_SIZES) { // For each of the boat sized defined in Options.cpp
        bool placing{true};
        while (placing) { // Loop until boat placed successfully
            cout << p << ": Placing " << size << " unit boat. ";

            int* boatLocation = ir.promptAndResolveBoardLocation(); // prompts for a location to be entered
            boatLocation[0] = turnIndex; // move the board index to the current player's index (above function doesnt know this and will always output -1)
            Orientation boatOrientation = ir.promptAndResolveOrientation(); // prompts for the orientation of the boat
            Boat* b = new Boat(p, boatLocation, size, boatOrientation); // creat the boat object

            delete boatLocation; // Boat will copy location data, clean up in this scope
            boatLocation = nullptr;

            if (board->placeBoat(*b)) { placing = false; } // break loop if boat was placed
            else { cout << "Location Invalid!" << endl; } // otherwise, scream at the user and loop again
        }
    }
}

void BattleBoatGame::setupGame() {
    cout << "Welcome to BattleBoats!" << endl;
    for (turnIndex = 0; turnIndex < 2; turnIndex++) { // For each player
        placeBoats(*turnOrder[turnIndex]);
    }
    turnIndex = 0;
}

void BattleBoatGame::runTurnForPlayer(Player p) {
    //TODO: Implement
}

bool BattleBoatGame::runRound() {
    for (turnIndex = 0; turnIndex < 2; turnIndex++) { // For each player

    }
    turnIndex = 0;
    return false;
}
