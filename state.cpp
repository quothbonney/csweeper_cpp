#include "state.h"

void State::initState() {
    gameState = (char **) malloc(sizeof(char *) * x * y);
    for (int row = 0; row < y; row++) {
        gameState[row] = (char *) malloc(sizeof(char) * x);
        for (int elem = 0; elem < x; elem++) {
            gameState[row][elem] = '~';
        }
    }
}

State::State(Board &b) {
x = b.x;
y = b.y;
values = b.getValues();
initState();
}


// Getter
char** State::getGameState() {
    return gameState;
}

// Setter
void State::open(int posY, int posX) {
    gameState[posY][posX] = values[posY][posX];
}


