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
    //TODO: Implement
}

void BattleBoatGame::runTurnForPlayer(Player) {
    //TODO: Implement
}

bool BattleBoatGame::runRound() {
    //TODO: Implement
    return false;
}
