#include <iostream>
#include <stdlib.h>
#include <time.h> // For random number generation<^
#include <vector>
#include <array>

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

				// Binary expression: 1 = bomb
				bombs[row][elem] = (num > threshold);
			}
		}
	}

	void valueBoard() {
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


public:
	int x, y;

	Board(int x, int y) {
		Board* e = this;
		e->x = x;
		e->y = y;

		// Initialize private class attributes
		bombLocations();
		valueBoard();
	}

	char** getValues() {
		return values;
	}
};


class State {
private:
	char** state;

public:
	std::vector<std::array<int, 2>> flags;
	int x, y;
	char** values;
	char** gameState;
	
	State(Board &b) {
		int x = b.x;
		int y = b.y;
		values = b.getValues();
		gameState = initState();
	}

	char** initState() {
		gameState = (char**)malloc(sizeof(char*) * x * y);
		for(int row = 0; row < y; row++) {
			gameState[row] = (char*)malloc(sizeof(char) * x);
			for(int elem = 0; elem < x; elem++) {
				gameState[row][elem] = '~';
			}
		}	

	}

	
};



int main() {
	int x, y;
	x = 10; y = 10;

	Board game = Board(x, y);
	State display = State(game);
	auto state = display.gameState;

	for(int i = 0; i < y; i++) {
		for(int j = 0; j < x; j++) {
			std::cout << state[i][j];
		}
		std::cout << "\n";
	}
	return 0;
}
