
#include "GameBoard.h"
#include "Soil.h"
#include <iostream>

GameBoard::GameBoard() : World(){
  srand (time(NULL));
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
  x = rand() % tornado_num;
  if (x == tornado_spawn_num){
    spawnTornado();
    cout << "the tornado has ended" << endl;
  }
  for(int i =0; i < 10; i++) {
		for(int j =0; j < 10;j++) {
      soilGrid[i][j]->update();
     if(soilGrid[i][j]->planted() == NULL)
         grid[i][j] = 'S';
         //Add a check for when it dies
    }
  }
  //determining if a new corn object should be spawned
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      currCorn = soilGrid[i][j]->planted();
      if(currCorn != NULL){
        if(currCorn->getAge() >= currCorn->getFertilityAge()){
          matureCorn(i,j);
        }
      }
    }
  }
}

void GameBoard::initGrid(){
  cornY = rand() % 8;
  cornX = rand() % 5;
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      //putting the corn objects in the correct configuration
      if((i >= cornX && i < cornX+5) && (j == cornY || j == cornY+1)){
        Soil *soil = new Soil();
        soil->addCorn();
        soilGrid[i][j] = soil;
        grid[i][j] = 'C';
      }
      //the regular soil
      else {
        Soil *soil = new Soil();
        soilGrid[i][j] = soil;
        grid[i][j] = 'S';
      }
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

void GameBoard::spawnTornado(){
  cout << "TORNADO SIRENS" << endl;
  //finding the crops which are going to be destroyed
  crops_destroyed = (rand() % 4) + 1;
  corn_locations = new int[crops_destroyed];
  for(int i = 0; i <= crops_destroyed; i++){
    while(true){
      x = rand() % 10;
      y = rand() % 10;
      if (soilGrid[x][y]->planted() != NULL){
        soilGrid[x][y]->destroyCorn();
        grid[x][y] = 'S';
        break;
      }
    }
  }
}

void GameBoard::matureCorn(int x, int y){
  //checking the space to the right
  if(checkBounds(x, y+1)){
    //if the space is planted
    if(soilGrid[x][y+1]->hasCorn()){
      tempCorn = soilGrid[x][y+1]->planted();
      //check the age of the adjacent corn
      if(tempCorn->getAge() >= tempCorn->getFertilityAge()){
        if(checkBounds(x, y+2) && !soilGrid[x][y+2]->hasCorn()){
          soilGrid[x][y+2]->addCorn();
          grid[x][y+2]= 'C' ;
        }
      }
    }
  }
  if(checkBounds(x, y-1)){
    //if the space is planted
    if(soilGrid[x][y-1]->hasCorn()){
      tempCorn = soilGrid[x][y-1]->planted();
      //check the age of the adjacent corn
      if(tempCorn->getAge() >= tempCorn->getFertilityAge()){
        if(checkBounds(x, y-2) && !soilGrid[x][y-2]->hasCorn()){
          soilGrid[x][y-2]->addCorn();
          grid[x][y-2]= 'C' ;
        }
      }
    }
  }
  if(checkBounds(x+1, y)){
    //if the space is planted
    if(soilGrid[x+1][y]->hasCorn()){
      tempCorn = soilGrid[x+1][y]->planted();
      //check the age of the adjacent corn
      if(tempCorn->getAge() >= tempCorn->getFertilityAge()){
        if(checkBounds(x+2, y) && !soilGrid[x+2][y]->hasCorn()){
          soilGrid[x+2][y]->addCorn();
          grid[x+2][y]= 'C' ;
        }
      }
    }
  }
  if(checkBounds(x-1, y)){
    //if the space is planted
    if(soilGrid[x-1][y]->hasCorn()){
      tempCorn = soilGrid[x-1][y]->planted();
      //check the age of the adjacent corn
      if(tempCorn->getAge() >= tempCorn->getFertilityAge()){
        if(checkBounds(x-2, y) && !soilGrid[x-2][y]->hasCorn()){
          soilGrid[x-2][y]->addCorn();
          grid[x-2][y]= 'C' ;
        }
      }
    }
  }
}
