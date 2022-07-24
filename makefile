all: board

board: main.cpp
	g++ -o board main.cpp board.cpp state.cpp -lncurses
