#include <iostream>
#include <stdlib.h>
#include <time.h> // For random number generation<^

#include "board.h"
#include "state.h"

int main() {
	int x, y;
	x = 10; y = 10;

	Board game = Board(x, y);
	State board = State(game);

    board.open(2, 2);
    board.open(5, 2);

	for(int i = 0; i < y; i++) {
		for(int j = 0; j < x; j++) {
			std::cout << board.getGameState()[i][j];
		}
		std::cout << "\n";
	}
	return 0;
}
