/**********************
 * Written by: Lance Kevin and Riley Conant
 * Time of Completion: 11:08pm 12/13/2019
 * Description: Soil object class that can have a corn object within it that will decrease its fertility
 * and cause the soil to kill of the corn if it gets low enough. Also holds the harvested amount for the 
 *  plot of soil.
 * 
 * ************************/
#include "Soil.h"
#include "Corn.h"
#include <iostream>
//Basic contructor for the soil object
Soil::Soil() {
	fertility = MAX_FERTILITY;
	corn = NULL;
	harvested = 0;
}
//Adds a corn object to the soil object
void Soil::addCorn(){
	
	corn = new Corn();
	
}
//Harvests the corn object and increases the harvest amount
void Soil::Harvest() {
	harvested = harvested + 1;
	destroyCorn();
}
//Update method for Soil
void Soil::update() {
	//Checks to see if there is corn object
	if(corn == NULL) {
		//If the soil is less than max fertility it will increase the fertility until MAX_FERTILTITY day by day
		if(fertility < MAX_FERTILITY) {
				fertility = fertility + FERTILITY_INCREASE;
		}
		return;
	}
	if(fertility <= 0){
		//if the fertility is gone destroy the corn
		destroyCorn();
		fertility = fertility + FERTILITY_INCREASE;
	}
	else {
		//Check if corn is below harvest age
		if(corn->getAge() < corn->getMaxAge()) {
			//Check if corn is below child corn age
			if(corn->getAge() < corn->getFertilityAge()){
				fertility = fertility + rand() % (int)(FERTILITY_DECREASE/4)+1; //this is the FERTILITY_DECREASE offset of young plants
			}
			//Lower fertility of soil and update corns age
			fertility = fertility - FERTILITY_DECREASE;
			corn->update();
			}
		else {
			//Harvest corn object
			Harvest();
		}
	}
}
//Returns the fertility of the soil
int Soil::getFertility() const {
	return fertility;
}
//Returns the corn object
Corn* Soil::planted() const {
	return corn;
}
//Returns the amount of harvested corn
int Soil::getHarvested() {
	return harvested;
}
//Overloading of equals operator for Soil
Soil& Soil::operator=(const Soil rhs) {
	//Sets  this soil's fetility to the passed in soil's fertility and sets the corn object to the passed in soil's corn object
	fertility = rhs.getFertility();
	corn = rhs.planted();
	return *this;
}
//Removes the corn from the soil object
void Soil::destroyCorn(){
	delete corn;
	corn = NULL;
	
}
//Checks to see if the soil has a corn planted in it
bool Soil::hasCorn(){
	if(corn == NULL){
		return false;
	}
	return true;
}
//Deconstructor for Soil, Deletes the corn object
Soil::~Soil(){
	delete corn;
}
