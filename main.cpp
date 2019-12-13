#include <iostream>
#include "GameBoard.h"
int main (int argc, char **argv) {
	int won = 0;
	int lost = 0;
for (int i = 0; i < 1000; i++){
	int harvest = 0;
	int remainingCorn = 0;
  int day = 0;
  char response;
	GameBoard *sim = new GameBoard();
    while(day < 1000 && harvest < 50) {
			cout << "~~~~~~~~~~~~~~~~~~~~" << endl;
      sim->PrintGrid();
      harvest = sim->harvested();
      cout << "This is day "<< day << "! Enter a y to continue"<< endl;
			cout << harvest << " corn has been harvested" << endl;
      //cin >> response;
      //if(response != 'y')
       //break;
      sim->UpdateGrid();
			remainingCorn = sim->getCornNum();
			if(remainingCorn == 0){
				day = 1000;
			}
			day++;
  }
  if(harvest > 50) {
    cout << "Congratulations you have harvested enough corn for the season!" << endl;
		won++;
  }
  else{
    cout << "Uh oh the seasons over and you didn't harvest enough corn in time! Game Over." << endl;
		lost++;
  }
}
cout << "won: " << won << endl;
cout << "lost: " << lost << endl;
	return 0;
}
