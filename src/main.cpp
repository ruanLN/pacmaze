#include <iostream>
#include "reader/MazeReader.h"

int main() {
    std::cout << "Hello, World!" << std::endl;


    MazeReader *fileReader = new MazeReader();

    fileReader->readMaze(1);
    fileReader->printMaze();

    return 0;
}