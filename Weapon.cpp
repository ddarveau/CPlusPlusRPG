/*
Desmond Darveau
Aug 16, 2015
Ver 1.01
Weapon.cpp
*/


#include "Item.h"
#include "Weapon.h" //Weapon class definition
//#include <iostream> //for cout and cin. for debugging.
using namespace std;

//Default constructor
Weapon::Weapon(){
	int xCord = 0;
	int yCord = 0;
	string name = "strange weapon";
	string description = "";
	long weight = 1;
	int value = 0;
	int minDammage = 0;
	int maxDammage = 1;

	setCord(xCord, yCord);
	setName(name);
	setDescription(description);
	setItemType(itemType);
	setWeight(weight);
	setValue(value);
	setMinDammage(minDammage);
	setMaxDammage(maxDammage);
}

//Constructor
//name, description, itemType, weight, value, minDammage, maxDammage
Weapon::Weapon(int xCord, int yCord, string name, string description, string itemType, long weight, int value, int minDammage, int maxDammage){
	setCord(xCord, yCord);
	setName(name);
	setDescription(description);
	setItemType(itemType);
	setWeight(weight);
	setValue(value);
	setMinDammage(minDammage);
	setMaxDammage(maxDammage);
}

void Weapon::setMinDammage(int minDammage){
	this->minDammage = minDammage;
}

void Weapon::setMaxDammage(int maxDammage){
	this->maxDammage = maxDammage;
}

int Weapon::getMinDammage() const{
	return minDammage;
}

int Weapon::getMaxDammage() const{
	return maxDammage;
}

//Must go one above max dammage.
int Weapon::getDammage()  const{
	int	dammage = rand() % 1 + this->getMaxDammage() + this->getMinDammage();
	return dammage;
}