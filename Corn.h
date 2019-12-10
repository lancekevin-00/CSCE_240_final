#ifndef CORN_H
#define CORN_H
#include <cstdlib>

using namespace std;
class Corn{
public:
  Corn();

  int getAge() const;
  void update();
  //void move(); //maybe goes here, just a placeholder for now till i figure it out 
  Corn& operator=(const Corn);
  int getMaxAge();
  int getFertilityAge();

private:
  const int MAX_AGE = 200;
  const int FERTILITY_AGE = 60;
  int age;

};

#endif
