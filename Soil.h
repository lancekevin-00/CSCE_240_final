#ifndef SOIL_H
#define SOIL_H
#include <cstdlib>

using namespace std;

class Soil{
public:
  Soil();

private:
  Corn corn;

  int getFertility();

  const int MAX_FERTILITY = 100;
  const int FERTILITY_DECREASE = 1;
  const int FERTILITY_INCREASE = 1;
};

#endif
