//
// Created by BuelowJacob on 10/1/2021.
//

#include "../BattleBoatBoard.h"
#include "../Options.cpp"

using namespace std;

int main() {
    bool failures{false};

    BattleBoatBoard *board = new BattleBoatBoard(Options::PLAYER_COUNT, Options::BOARD_SIZE_X, Options::BOARD_SIZE_Y);
    Player *player = new Player(HUMAN_A);
    int location[] = {0,0,0};
    Strike *strike = new Strike(*player, location);
    bool firstStrikeValid = board->placeStrike(*strike);

    Strike *strike2 = new Strike(*player, location);
    bool secondStrikeValid = board->placeStrike(*strike2);

    if (!firstStrikeValid) {
        cerr << "TEST FAILURE: Placing a strike that was supposed to succeed has failed!" << endl;
        failures = true;
    }
    if (secondStrikeValid) {
        cerr << "TEST FAILURE: Placing a strike that was supposed to fail has succeeded!" << endl;
        failures = true;
    }

    // Clean up
    delete player;
    player = nullptr;
    delete board;
    board = nullptr;

    // Verify that the deconstructor for BattleBoatBoard has deleted all the strikes attached to it
    if (strike->getPlayerPos() == 0) {
        cerr << "TEST FAILURE: BattleBoatBoard failed to deconstruct an attached strike object!" << endl;
        failures = true;
    }
    strike = nullptr;

    if (strike2->getPlayerPos() != 0) {
        cerr << "TEST FAILURE: BattleBoatBoard deconstructor destroyed a strike object that should not have been attached!" << endl;
        failures = true;
    } else {
        delete strike2;
    }
    strike2 = nullptr;

    if (!failures) cout << "TEST PASS: testStrikeOverlapValidation()" << endl;
    return failures;
}