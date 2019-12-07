#include "Soil.h"
#include <iostream>

Soil::Soil() {
	fertility = MAX_FERTILITY;
	corn = NULL;
}
Soil::Soil(Corn c) {
	corn = c;
	fertility = MAX_FERTILITY;
}
void Soil::Harvest() {
	//calls to a method somewhere that updates harvested amount, probably in gameboard or something
	corn = NULL;
}
void Soil::update() {
	if(corn.getAge <= 60 ) {
	
	}
	else if(corn.getAge > 60 && corn != NULL;{
		fertility = fertility - FERTILITY_DECREASE;
	}
	else if(corn == NULL) {
		if(fertitilty <100) {
			fertility = fertility + FERTILITY_INCREASE;
		}
	}
}
int Soil::getFertility() {
	return fertility;
}
