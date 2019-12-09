#include <iostream>
#include "GameBoard.h"
int main (int argc, char **argv) {
	int harvest=0;
  int day = 0;
  char response;
	GameBoard *sim = new GameBoard();
    while(day < 1000 && harvest < 50) {
      sim->PrintGrid();
      cout << "This is day "<< day << "! Enter a y to continue"<< endl;
      cin >> response;
      if(response != 'y') 
        break;
      sim->UpdateGrid();
      day++;
      harvest = sim->harvested();
  }
	return 0;
}
