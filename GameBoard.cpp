
#include "GameBoard.h" 
#include <iostream>

GameBoard::GameBoard() : World(){
	this->initGrid();
	day =0;
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
				grid[i][j] = '*';
			}
		}
	}

	bool GameBoard::checkBounds(int x, int y){ 
		return false;
	}

