#ifndef CSWEEPER_CPP_BOARD_H
#define CSWEEPER_CPP_BOARD_H

#include <stdlib.h>
#include <time.h> // For random number generation<^
#include <vector>
#include <array>

class Board {
private:
    int** bombs;
    char** values;

    // bombLocations() sets int** bombs to a binary matrix with size x, y
    void bombLocations(int threshold = 9);

    void valueBoard();


public:
    int x, y;

    Board(int x, int y);

    char** getValues();
};





#endif //CSWEEPER_CPP_BOARD_H
