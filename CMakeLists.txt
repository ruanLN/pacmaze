cmake_minimum_required(VERSION 3.10)
project(pacmaze)

set(CMAKE_CXX_STANDARD 11)

add_executable(pacmaze src/main.cpp src/reader/MazeReader.h src/mdp/PacMazeMdp.h)