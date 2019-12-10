#include "Soil.h"
#include "Corn.h"
#include <iostream>

Soil::Soil() {
	fertility = MAX_FERTILITY;
	corn = NULL;
}
Soil::Soil(Corn *c) {
	corn = c; //Probably need to switch to a copy constructor or something, my brain is shot rn tbh so i dont feel like doing it rn
	fertility = MAX_FERTILITY;
}

void Soil::addCorn(){
	corn = new Corn();
}

void Soil::Harvest() {
	harvested++;
	corn = NULL;
}
void Soil::update() {
	if(corn == NULL) {
		if(fertility < MAX_FERTILITY) {
				fertility = fertility + FERTILITY_INCREASE;
		}
	}
	else {
		if(fertility > 0) {
			if(corn->getAge() < corn->getMaxAge()) {
				if(corn->getAge() > corn->getFertilityAge() && corn != NULL){
					cout << 4 << endl;
					fertility = fertility - FERTILITY_DECREASE;
					corn->update();
					cout << 5 << endl;
				}
			}
			else {
				//If it still alive harvest
				if(fertility > 0) {
					this->Harvest();
				}
			}
		}
		else {
			//Plant is dead/feritilty equals zero so increasing the fertility allows it to run through the other loop
			corn = NULL;
			fertility = fertility + FERTILITY_INCREASE;
		}
	}
	cout << 0 << endl;
}
int Soil::getFertility() const {
	return fertility;
}
Corn* Soil::planted() const {
	return corn;
}
int Soil::getHarvested() {
	return harvested;
}
Soil& Soil::operator=(const Soil rhs) {
	fertility = rhs.getFertility();
	corn = rhs.planted();
	return *this;
}


/*	else if(corn == NULL) {
				if(fertility <100) {
					fertility = fertility + FERTILITY_INCREASE;
				}
			} */
