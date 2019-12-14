/**********************
 * Written by: Lance Kevin and Riley Conant
 * Time of Completion: 11:08pm 12/13/2019
 * Description: Corn header class that has the prototypes and member variables
 * defined and used by the corn object
 * ************************/
 #ifndef CORN_H
#define CORN_H
#include <cstdlib>

using namespace std;
class Corn{
public:
//Constuctor
  Corn();
//Functions
  int getAge() const;
  void update();
  Corn& operator=(const Corn);
  int getMaxAge();
  int getFertilityAge() const;

private:
//Member variables
  const int MAX_AGE = 200;
  const int FERTILITY_AGE = 60;
  int age;

};

#endif
