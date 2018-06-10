//
// Created by flora on 10/06/2018.
//

#ifndef PACMAZE_MARKOVDECISIONPROCESS_H
#define PACMAZE_MARKOVDECISIONPROCESS_H

#include <string>
#include <vector>
#include <iostream>
#include "list"

//- empty
//# wall
//0 pacman
 //& enemy

class PacMazeMdp {

public:
    PacMazeMdp (std::vector<std::vector<std::string>> maze);

    std::vector<std::pair<int, int>> getStates();

    std::pair<int, int> getStartState();

    std::list<std::string> getPossibleActions(std::pair<int, int> state);

    std::list<std::pair<std::pair<int, int>, double>> getTransitionStatesAndProbs(std::pair<int, int> state, std::list<std::string> action);

    double getReward(std::pair<int, int> state, std::string action, std::pair<int, int> next_state);

    bool isTerminal(std::pair<int, int> state);

private:

    std::vector<std::vector<std::string>> maze;

    std::vector<std::pair<int, int>> states;
};

PacMazeMdp::PacMazeMdp(std::vector<std::vector<std::string>> maze) {
    this->maze = maze;
}

std::vector<std::pair<int, int>> PacMazeMdp::getStates() {
    std::vector<std::pair<int, int>> states;

    for ( std::vector<std::vector<int>>::size_type i = 0; i < this->maze.size(); i++ )
    {
        for ( std::vector<int>::size_type j = 0; j < this->maze[i].size(); j++ )
        {
            if (this->maze[i][j].compare(0, 1, '#') == 0) {
                states.push_back(std::make_pair<int, int>(i, j));
            }
        }
        std::cout << std::endl;
    }

    this->states = states;
    return states;
}

std::pair<int, int> PacMazeMdp::getStartState() {

    for ( std::vector<std::vector<int>>::size_type i = 0; i < this->maze.size(); i++ )
    {
        for ( std::vector<int>::size_type j = 0; j < this->maze[i].size(); j++ )
        {
            if (this->maze[i][j].compare(0, 1, '0') == 0) {
                return std::make_pair<int, int>(i, j);
            }
        }
        std::cout << std::endl;
    }
    return std::pair<int, int>();
}

std::list<std::string> PacMazeMdp::getPossibleActions(std::pair<int, int> state) {
    return std::list<std::string>();
}

std::list<std::pair<std::pair<int, int>, double>>
PacMazeMdp::getTransitionStatesAndProbs(std::pair<int, int> state,
                                        std::list<std::string> action) {

    return std::list<std::pair<std::pair<int, int>, double>>();
}

double PacMazeMdp::getReward(std::pair<int, int> state,
                             std::string action,
                             std::pair<int, int> next_state) {

    return 0;
}

bool PacMazeMdp::isTerminal(std::pair<int, int> state) {
    return false;
}


#endif //PACMAZE_MARKOVDECISIONPROCESS_H
