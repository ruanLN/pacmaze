#include <iostream>
#include "reader/MazeReader.h"
#include "mdp/PacMazeMdp.h"

int main() {
    std::cout << "Hello, World!" << std::endl;


    MazeReader *fileReader = new MazeReader();

    fileReader->readMaze(1);
    fileReader->printMaze();

    PacMazeMdp *mdp = new PacMazeMdp(fileReader->maze);

    std::vector<std::pair<int, int>> states = mdp->getStates();

    return 0;
}