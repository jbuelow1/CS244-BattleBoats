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

void BattleBoatGame::setupGame() {
    cout << "Welcome to BattleBoats!" << endl;
    for (turnIndex = 0; turnIndex < 2; turnIndex++) { // For each player

    }
    turnIndex = 0;
}

void BattleBoatGame::runTurnForPlayer(Player p) {
    //TODO: Implement
}

bool BattleBoatGame::runRound() {
    //TODO: Implement
    return false;
}
