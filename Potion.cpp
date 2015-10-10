/*
Desmond Darveau
Aug 24, 2015
Ver 1.01
potion.cpp

*/

#include "Potion.h" //Item class definition
//#include <iostream> //for cout and cin. for debugging.
using namespace std;

//Default constructor
Potion::Potion(){

}

//constructor
//xCord, yCord, name, description, itemType, weight, value, effect, points
Potion::Potion(int xCord, int yCord, string name, string description, 
	string itemType, long weight, int value, string effect, int points){
	setCord(xCord, yCord);
	setName(name);
	setDescription(description);
	setItemType(itemType);
	setWeight(weight);
	setValue(value);
	setEffect(effect);
	setPoints(points);
}
void Potion::setEffect(string effect){
	this->effect = effect;
}

void Potion::setPoints(int points){
	this->points = points;
}

string Potion::getEffect() const{
	return effect;
}

int Potion::getPoints() const{
	return points;
}