#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include "World.h"
#include "Soil.h"
#include <cstdlib>

class GameBoard : public World {
	public:
	GameBoard();
	void PrintGrid();
	void UpdateGrid();	
	protected:
  Soil *soilGrid[10][10];
	void initGrid();
	bool checkBounds(int x, int y);
};
#endif /* GAMEBOARD_H */
