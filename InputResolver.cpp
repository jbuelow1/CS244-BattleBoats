#include <string>

#include "InputResolver.h"
#include "Options.cpp"

Orientation InputResolver::promptAndResolveOrientation() {
    while (true) {
        cout << "Select orientation (Horizontal or Vertical) ? ";
        string input;
        getline(cin, input);

        // Scan through the line of input recieved. Once we hit a v or an h, assume vertial or horizontal was input
        for (int i = 0; i < input.length(); i++) {
            if (input[i] >= 0x41 && input[i] <= 0x5A)  { // Between A and Z
                input[i] += 0x20; // Shift over to make it lowercase
            }

            if (input[i] == 'v') {
                //cout << "Got: VERTICAL" << endl;
                return VERTICAL;
            } else if (input[i] == 'h') {
                //cout << "Got: HORIZONTAL" << endl;
                return HORIZONTAL;
            }
        }
        cout << "Invalid Input!" << endl;
    }
}

int *InputResolver::promptAndResolveBoardLocation() {
    char letter{0x00};
    int number{-1};
    bool done{false};
    while (!done) {
        string input;
        cout << "Enter Location (Ex.'C5') ?";
        getline(cin, input);

        for (int i = 0; i < input.length(); i++) {
            if (input[i] >= 0x41 && input[i] <= 0x5A)  { // Between A and Z
                input[i] += 0x20; // Shift over to make it lowercase
            }

            if (input[i] >= 0x61 && input[i] <= 0x7A) { // Between a and z
                letter = input[i];
                break;
            }
        }

        for (int i = 0; i < input.length(); i++) { //TODO: need to make this work with at least 2 digit numbers!
            if (input[i] >= 0x30 && input[i] <= 0x39) { // Between 0 and 9
                number = input[i] - 0x30;
            }
        }

        if (letter == 0x00 || number == -1) { // Input could not be parsed
            cout << "Invalid input! Type a letter and a number!" << endl;
        } else if (letter - 0x61 > Options::BOARD_SIZE_X ||
                   number - 1 > Options::BOARD_SIZE_Y) { // Selection is too large for board size
            cout << "Invalid input! Selection too large for board size!" << endl;
        } else {
            done = true;
        }
    }

    int* out = new int[3];
    out[0] = -1; // -1 used to signify that the side of the board is not known yet / irrelevant
    out[1] = letter - 0x61; // convert a-z to 0-25
    out[2] = number - 1;

    return out;
}

bool InputResolver::promptAndResolvePlayAgain() {
    return false;
}
