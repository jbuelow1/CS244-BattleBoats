//#include <string>

//using namespace std;

struct Options {
    static const int PLAYER_COUNT = 2;
    static const int BOARD_SIZE_X = 10;
    static const int BOARD_SIZE_Y = 10;
    static const int BOAT_COUNT = 5;
    //constexpr static const int BOAT_SIZES[] = {2, 3, 3, 4, 5}; // This didnt work used #define below

    // Box drawing chars
    //static const string BOXDRAW_VERTICAL = "║"; // This also didnt work. #defines are below
};

#define OPTION_DEF_BOAT_SIZES {2, 3, 3, 4, 5}

#ifdef __linux
// Fancy unicode box drawing characters don't work on Windows,
// or rather at least not in the default command prompt.
// maybe in the new Windows terminal app?
#define BATTLEBOATS_USE_FANCY_CHARS
#endif

// Box drawing chars
#ifdef BATTLEBOATS_USE_FANCY_CHARS

#define BOXDRAW_VERTICAL "║"
#define BOXDRAW_HORIZONTAL "═"
#define BOXDRAW_CORNER_UPLEFT "╔"
#define BOXDRAW_CORNER_LOWLEFT "╚"
#define BOXDRAW_CORNER_UPRIGHT "╗"
#define BOXDRAW_CORNER_LOWRIGHT "╝"
#define BOXDRAW_VERTICAL_T_RIGHT "╠"
#define BOXDRAW_VERTICAL_T_LEFT "╣"
#define BOXDRAW_HORIZONTAL_T_UP "╩"
#define BOXDRAW_HORIZONTAL_T_DOWN "╦"
#define BOXDRAW_CROSS "╬"

#define BOXDRAW_BOAT "█"
#define BOXDRAW_HIT "¤"
#define BOXDRAW_MISS "Ø"

#else /* BATTLEBOATS_USE_FANCY_CHARS */

#define BOXDRAW_VERTICAL "|"
#define BOXDRAW_HORIZONTAL "-"
#define BOXDRAW_CORNER_UPLEFT "+"
#define BOXDRAW_CORNER_LOWLEFT "+"
#define BOXDRAW_CORNER_UPRIGHT "+"
#define BOXDRAW_CORNER_LOWRIGHT "+"
#define BOXDRAW_VERTICAL_T_RIGHT "+"
#define BOXDRAW_VERTICAL_T_LEFT "+"
#define BOXDRAW_HORIZONTAL_T_UP "+"
#define BOXDRAW_HORIZONTAL_T_DOWN "+"
#define BOXDRAW_CROSS "+"

#define BOXDRAW_BOAT "#"
#define BOXDRAW_HIT "*"
#define BOXDRAW_MISS "o"

#endif /* BATTLEBOATS_USE_FANCY_CHARS */
