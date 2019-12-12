#include <iostream>
#include "GameBoard.h"
int main (int argc, char **argv) {
	int harvest=0;
  int day = 0;
  char response;
	GameBoard *sim = new GameBoard();
    while(day < 1000 && harvest < 50) {
      sim->PrintGrid();
      harvest = sim->harvested();
      cout << "This is day "<< day << "! Enter a y to continue"<< endl;
			cout << harvest << " corn has been harvested" << endl;
      cin >> response;
      if(response != 'y')
       break;
      sim->UpdateGrid();
      day++;
      
  }
  if(harvest > 50) {
    cout << "Congratulations you have harvested enough corn for the season!" << endl;
  }
  if(harvest < 50 && day == 999) {
    cout << "Uh oh the seasons over and you didn't harvest enough corn in time! Game Over." << endl;
  }
	return 0;
}
