#ifndef SOIL_H
#define SOIL_H
#include "Corn.h"
#include <cstdlib>

using namespace std;

class Soil{
public:
  Soil();
  Soil(Corn*);
  ~Soil();
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
  Corn *corn;
	int fertility;
	int harvested;
  static const int MAX_FERTILITY = 5000;
  static const int FERTILITY_DECREASE = 20;
  static const int FERTILITY_INCREASE = 20;
};

#endif
