/**********************
 * Written by: Lance Kevin and Riley Conant
 * Time of Completion: 11:08pm 12/13/2019
 * Description: Soil header class that has the prototypes of all the functions 
 *  and member variables that the soil object will define.
 * ************************/
#ifndef SOIL_H
#define SOIL_H
#include "Corn.h"
#include <cstdlib>

using namespace std;

class Soil{
public:
//Constructor and Desctructor
  Soil();
  ~Soil();
  //Functions
  void addCorn();
  void Harvest();
  void update();
	Soil& operator=(const Soil);
	Corn* planted() const;
	int getHarvested();
  void destroyCorn();
  bool hasCorn();
  int getFertility() const;
private:
//Member variables
  Corn *corn;
	int fertility;
	int harvested;
  static const int MAX_FERTILITY = 5000;
  static const int FERTILITY_DECREASE = 20;
  static const int FERTILITY_INCREASE = 20;
};

#endif
