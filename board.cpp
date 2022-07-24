#include <iostream>
#include <stdlib.h>
#include <time.h> // For random number generation<^

// Board coordinates are in x, y, where x is left to right, and y is top to bottom

class Board {
private:
	int** bombs;
	char** values;

	// bombLocations() sets int** bombs to a binary matrix with size x, y
	void bombLocations(int threshold = 9) {
		// Establish random seed
		srand(time(NULL));
		
		bombs = (int**)malloc(sizeof(int*) * x * y);

		for(int row = 0; row < y; row++){
			bombs[row] = (int*)malloc(sizeof(int) * x);
			for(int elem = 0; elem < x; elem++) {
				int num = rand() % 10 + 1;
				bombs[row][elem] = (num > threshold);
			}
		}
	}

public:
	int x, y;

	Board(int x, int y) {
		Board* e = this;
		e->x = x;
		e->y = y;

		bombLocations();
	}

	int** getBombBoard() {
		return bombs;
	}

};

int main() {
	int x, y;
	x = 10; y = 10;

	Board game = Board(x, y);
	int** bomb_board = game.getBombBoard();

	for(int i = 0; i < y; i++) {
		for(int j = 0; j < x; j++) {
			std::cout << bomb_board[i][j];
		}
		std::cout << "\n";
	}

	free(bomb_board);
}
