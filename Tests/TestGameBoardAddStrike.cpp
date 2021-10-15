//
// Created by BuelowJacob on 10/1/2021.
//

#include <cassert>

#include "../BattleBoatBoard.h"
#include "../Options.cpp"

using namespace std;

int main() {
    BattleBoatBoard *board = new BattleBoatBoard(Options::PLAYER_COUNT, Options::BOARD_SIZE_X, Options::BOARD_SIZE_Y);
    Player *player = new Player(HUMAN_A);
    int location[] = {0,0,0};
    Strike *strike = new Strike(*player, location);
    bool firstStrikeValid = board->placeStrike(*strike);

    Strike *strike2 = new Strike(*player, location);
    bool secondStrikeValid = board->placeStrike(*strike2);

    assert(firstStrikeValid);
    assert(!secondStrikeValid);

    // Clean up
    delete player;
    player = nullptr;
    delete board;
    board = nullptr;

    // Verify that the deconstructor for BattleBoatBoard has deleted all the strikes attached to it
    assert(strike->getPlayerPos() != 0);
    strike = nullptr;

    assert(strike2->getPlayerPos() == 0);
    delete strike2;
    strike2 = nullptr;

    return 0;
}