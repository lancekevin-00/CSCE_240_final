#ifndef CORN_H
#define CORN_H
#include <cstdlib>

using namespace std;
class Corn{
public:
  Corn();

  int getAge() const;
  void update();
  Corn& operator=(const Corn);
  int getMaxAge();
  int getFertilityAge() const;

private:
  const int MAX_AGE = 200;
  const int FERTILITY_AGE = 60;
  int age;

};

#endif
