#include "board.h"
#include <stdlib.h>
#include <time.h> // For random number generation<^

// Board coordinates are in x, y, where x is left to right, and y is top to bottom

// bombLocations() sets int** bombs to a binary matrix with size x, y
void Board::bombLocations(int threshold) {
    // Establish random seed
    srand(time(NULL));

    bombs = (int**)malloc(sizeof(int*) * x * y);

    for(int row = 0; row < y; row++){
        bombs[row] = (int*)malloc(sizeof(int) * x);
        for(int elem = 0; elem < x; elem++) {
            int num = rand() % 10 + 1;

            // Binary expression: 1 = bomb
            bombs[row][elem] = (num > threshold);
        }
    }
}

void Board::valueBoard() {
    values = (char**)malloc(sizeof(char*) * x * y);

    for(int row = 0; row < y; row++) {
        values[row] = (char*)malloc(sizeof(char) * x);
        for(int elem = 0; elem < x; elem++) {
            if(bombs[row][elem]) {
                values[row][elem] = 'b';
            } else {
                char working = '0';
                int range[] = {-1, 0, 1};
                for(const auto i : range) {
                    for(const auto j : range) {
                        // if inside board, incrememnt char working
                        if(
                                (elem + i) > -1 &&
                                (elem + i) < x &&
                                (row + j) > -1 &&
                                (row + j) < y
                                ) { working += bombs[row + j][elem + i]; }
                    }
                }
                values[row][elem] = working;
            }
        }
    }
}

Board::Board(int x, int y) {
    Board* e = this;
    e->x = x;
    e->y = y;

    // Initialize private class attributes
    bombLocations();
    valueBoard();
}

char** Board::getValues() {
    return values;
}
