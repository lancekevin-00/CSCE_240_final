
#include "GameBoard.h" 
#include "Soil.h"
#include <iostream>

GameBoard::GameBoard() : World(){
	this->initGrid();
	day =0;
  numHarvested = 0;
}

	void GameBoard::PrintGrid()  {
		for(int i =0; i < 10; i++) {
			cout << "| ";
			for(int j =0; j < 10;j++) {
				cout << grid[i][j] << " | ";
			}
			cout << endl;
		}
	}
	 void GameBoard::UpdateGrid(){
		 //Will call the values for the corn and soil
     
	}
	 void GameBoard::initGrid(){
		for(int i =0; i < 10; i++) {
			for(int j =0; j < 10;j++) {
        Soil *soil = new Soil();
        soilGrid[i][j] = soil;
				grid[i][j] = 'S';
			}
		}
	}
	bool GameBoard::checkBounds(int x, int y){ 
		//Checks to see if passed in values are within bounds assuming that is what the funciton takes in
    if(x < 0 || x > 10 || y < 0 || y >10) {
      return false;
    }
    return true;
	}
  int GameBoard::harvested() {
    for(int i =0; i < 10; i++) {
			for(int j =0; j < 10;j++) {
        numHarvested =+ soilGrid[i][j]->getHarvested();
      }
    }
    return numHarvested;
  }

