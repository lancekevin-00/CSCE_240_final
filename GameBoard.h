#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include "World.h"
#include <cstdlib>

class GameBoard : public World {
	public:
	GameBoard();
	void PrintGrid();
	void UpdateGrid();	
	protected:
	void initGrid();
	bool checkBounds(int x, int y);
};
#endif /* GAMEBOARD_H */
