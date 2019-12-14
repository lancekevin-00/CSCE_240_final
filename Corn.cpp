/**********************
 * Written by: Lance Kevin and Riley Conant
 * Time of Completion: 11:08pm 12/13/2019
 * Description: Corn object class that defines the functions 
 * from the corn header class
 * ************************/
#include "Corn.h"
#include <iostream>
//Default Constructor
Corn::Corn() {
	age = 0;
}
//Returns the age of the corn object
int Corn::getAge() const {
	return age;
}
//Overloaded equals operator for corn object
Corn& Corn::operator=(const Corn rhs) {
	age = rhs.getAge();
	return *this;
}
//Increases the age of the corn 
void Corn::update() {
	age++;
}
//returns the max age of the corn
int Corn::getMaxAge(){
	return MAX_AGE;
}
//returns the fertility age of the corn
int Corn::getFertilityAge() const{
	return FERTILITY_AGE;
}
