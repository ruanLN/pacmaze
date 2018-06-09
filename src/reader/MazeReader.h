//
// Created by flora on 09/06/2018.
//

#ifndef PACMAZE_FILEREADER_H
#define PACMAZE_FILEREADER_H


#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>


int empty = 0; //-
int wall = 1; //#
int pacman = 2; //0
int enemy = 3; //&

class MazeReader {

public:

    std::ifstream mazeFile;
    std::vector<std::vector<std::string>> maze;

    void readMaze(int type);

    std::vector<std::vector<std::string>> getMaze(int type);

    void printMaze();

private:

};

void MazeReader::readMaze(int type) {
    std::string filePath;
    switch (type) {
        case 1 :
            filePath = "../maze/pacmaze-01-tiny.txt";
            break;
        case 2 :
            filePath = "../maze/pacmaze-02-mid-sparse.txt";
            break;
        case 3 :
            filePath = "../maze/pacmaze-03-tricky.txt";
            break;
        default:
            break;
    }

    if (filePath.empty()) {
        std::cout << "Invalid option for maze selection.";
        return;
    }

    mazeFile.open(filePath);
    if (!mazeFile.is_open()) {
        std::cout << "Error opening maze file" << std::endl;
    }



    std::string infoLine;
    getline(mazeFile, infoLine);

    int width = infoLine[0] - '0';
    int lenght = infoLine[2] - '0';

    std::vector<std::string> tempElements;
    std::string templine;

    for (int i = 0; i < width; i++) {
        getline(mazeFile, templine);
        tempElements.push_back(templine);
    }
    this->maze.push_back(tempElements);

    mazeFile.close();
}

void MazeReader::printMaze() {
    for ( std::vector<std::vector<int>>::size_type i = 0; i < this->maze.size(); i++ )
    {
        for ( std::vector<int>::size_type j = 0; j < this->maze[i].size(); j++ )
        {
            std::cout << this->maze[i][j] << ' ';
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

std::vector<std::vector<std::string>> MazeReader::getMaze(int type) {
    return maze;
}


#endif //PACMAZE_FILEREADER_H
