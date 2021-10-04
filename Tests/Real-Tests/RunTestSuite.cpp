//
// Created by BuelowJacob on 10/2/2021.
//

#include "TestGameBoardAddStrike.cpp"

int main() {
    unsigned int failures{0};
    failures += TestGameBoardAddStrike::testAll();

    if (failures == 0) {
        cout << endl << "ALL TESTS PASSED!" << endl;
    } else {
        cerr << endl << "THERE ARE TEST FAILURES!" << endl << " > " << failures << " TESTS FAILED" << endl;
    }

    return failures;
}