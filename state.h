#ifndef CSWEEPER_CPP_STATE_H
#define CSWEEPER_CPP_STATE_H

#include <array>
#include <vector>
#include "board.h"

class State {
private:
    char** gameState;
    char** values;

    void initState();

public:
    std::vector<std::array<int, 2>> flags;
    int x, y;

    State(Board &b);


    // Getter
    char** getGameState();

    // Setter
    void open(int posY, int posX);
};

#endif //CSWEEPER_CPP_STATE_H
