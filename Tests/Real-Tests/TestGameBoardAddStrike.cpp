//
// Created by BuelowJacob on 10/1/2021.
//

#include "../../BattleBoatBoard.h"
#include "../../Options.cpp"

using namespace std;

class TestGameBoardAddStrike {
public:
    static bool testStrikeOverlapValidation() {
        BattleBoatBoard *board = new BattleBoatBoard(Options::PLAYER_COUNT, Options::BOARD_SIZE_X, Options::BOARD_SIZE_Y);
        Player *player = new Player(HUMAN_A);
        int location[] = {0,0,0};
        Strike *strike = new Strike(*player, location);
        bool firstStrikeValid = board->placeStrike(*strike);

        Strike *strike2 = new Strike(*player, location);
        bool secondStrikeValid = board->placeStrike(*strike2);

        if (!firstStrikeValid) cerr << "TEST FAILURE: Placing a strike that was supposed to succeed has failed!" << endl;
        if (secondStrikeValid) cerr << "TEST FAILURE: Placing a strike that was supposed to fail has succeeded!" << endl;

        // Clean up
        delete strike2;
        strike2 = nullptr;
        delete strike;
        strike = nullptr;
        delete player;
        player = nullptr;
        delete board;
        board = nullptr;

        return firstStrikeValid && !secondStrikeValid;
    }

    static bool testAll() {
        bool allPass = true;
        if (!testStrikeOverlapValidation()) allPass = false;
        return allPass;
    }
};
