#include "Corn.h"
#include <iostream>

Corn::Corn() {
	age = 0;
}

int Corn::getAge() const {
	return age;
}

Corn& Corn::operator=(const Corn rhs) {
	age = rhs.getAge();
	return *this;
}

void Corn::update() {
	age++;
}

int Corn::getMaxAge(){
	return MAX_AGE;
}

int Corn::getFertilityAge() const{
	return FERTILITY_AGE;
}
