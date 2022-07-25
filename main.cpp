#include <iostream>
#include <ncurses.h>
#include <stdlib.h>

#include "board.h"
#include "state.h"


int cursorX = 0;
int cursorY = 0;


void printout(State &b) {
	char** boardState = b.getGameState();
	for(int row = 0; row < b.y; row++) {
		for(int elem = 0; elem < b.x; elem++) {
			mvprintw(row, elem*2, &boardState[row][elem]);
		}
	}	
} 


int main(int argc, char** argv) {
	// Check correct args
	if(argv[1] == nullptr || argv[2] == nullptr) {
		std::cout << "Usage: ./mine <X> <Y>";
		exit(1);
	}
		


	// Init screen
	initscr();
	cbreak();

	int gameX = atoi(argv[1]); // Convert char* to int
	int gameY = atoi(argv[2]);

	Board game = Board(gameX, gameY);
	State state = State(game);

	printout(state);
	char input;

	while(input != 'q') {
		noecho();
		move(cursorY, cursorX);

		input = getch();
		printout(state);

		switch(input) {
			case 's': cursorY = ((cursorY + 1) % gameY); break;
			case 'w': cursorY = ((cursorY - 1) % gameY); break;
			case 'd': cursorX = ((cursorX + 2) % (gameX * 2)); break;
			case 'a': cursorX = ((cursorX - 2) % (gameX * 2)); break;
		};
		refresh();
	}
	endwin();
}
