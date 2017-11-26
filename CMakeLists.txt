cmake_minimum_required(VERSION 3.8)
project(untitled)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Game.cpp Game.h ConsolePlayer.cpp Point.cpp Point.h GameLogic1.cpp GameLogic1.h Board.cpp Board.h ConsolePlayer.h Player.h Player.cpp GameLogic.cpp GameLogic.h AIPlayer.cpp AIPlayer.h)
add_executable(untitled ${SOURCE_FILES})