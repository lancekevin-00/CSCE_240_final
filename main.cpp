#include <iostream>
#include "GameBoard.h"
int main (int argc, char **argv) {
	
	World *sim = new GameBoard();
	sim->PrintGrid();
	
	return 0;
}
