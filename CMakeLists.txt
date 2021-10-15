cmake_minimum_required(VERSION 3.13)
project(BattleBoats)

enable_testing()

set(CMAKE_CXX_STANDARD 14)

#[[ All Source files that arent an entry point or test go here ]]
file(GLOB BattleBoatSrc
        "BattleBoatGame.cpp"
        "BattleBoatBoard.cpp"
        "Player.cpp"
        "BoardPiece.cpp"
        "Strike.cpp"
        "Boat.cpp"
        "InputResolver.cpp"
        "Options.cpp"
)

#[[ Build main game executable ]]
add_executable(BattleBoats EntryPoint.cpp ${BattleBoatSrc})

#[[ Build test executables ]]
add_executable(BattleBoatsTest_TestGameBoardAddStrike Tests/TestGameBoardAddStrike.cpp ${BattleBoatSrc})
add_test(NAME TestGameBoardAddStrike COMMAND BattleBoatsTest_TestGameBoardAddStrike)
