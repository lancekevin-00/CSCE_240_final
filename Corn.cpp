#include "Corn.h"
#include <iostream>

Corn::Corn() {
	age = 0;
}
int Corn::getAge() {
	return age;	
}
void Corn::update() {
	age++;	
}
