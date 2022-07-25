all: mine 

mine: main.cpp
	g++ -o mine main.cpp board.cpp state.cpp -lncurses
