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
		return;
	}
	if(fertility == 0){
		//if the fertility is gone destroy the corn
		corn = NULL;
		fertility = fertility + FERTILITY_INCREASE;
	}
	else {
		if(corn->getAge() < corn->getMaxAge()) {
			if(corn->getAge() > corn->getFertilityAge()){
				fertility = fertility + 1; //this is the FERTILITY_DECREASE offset of young plants
			}
			fertility = fertility - FERTILITY_DECREASE;
			corn->update();
			}
			else {
					this->Harvest();
			}
		}
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

void Soil::destroyCorn(){
	corn = NULL;
}

bool Soil::hasCorn(){
	if(corn == NULL){
		return false;
	}
	return true;
}
