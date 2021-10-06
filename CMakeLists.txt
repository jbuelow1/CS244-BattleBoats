cmake_minimum_required(VERSION 3.13)
project(BattleBoats)

set(CMAKE_CXX_STANDARD 14)

add_executable(BattleBoats EntryPoint.cpp Player.cpp BattleBoatBoard.cpp BattleBoatGame.cpp Options.cpp BoardPiece.cpp Strike.cpp Boat.cpp InputResolver.cpp)
add_executable(BattleBoatTestRun Tests/Debugging-Tests/TestRun.cpp Player.cpp BattleBoatBoard.cpp BattleBoatGame.cpp Options.cpp BoardPiece.cpp Strike.cpp Boat.cpp Tests/Real-Tests/TestGameBoardAddStrike.cpp InputResolver.cpp)
add_executable(BattleBoatTestSuite Tests/Real-Tests/RunTestSuite.cpp Player.cpp BattleBoatBoard.cpp BattleBoatGame.cpp Options.cpp BoardPiece.cpp Strike.cpp Boat.cpp InputResolver.cpp)
