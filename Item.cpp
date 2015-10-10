/*
Desmond Darveau
Aug 16, 2015
Ver 1.01
Item.cpp

*/

#include "Item.h" //Item class definition
//#include <iostream> //for cout and cin. for debugging.
using namespace std;

//Default constructor
Item::Item(){
	int xCord = -1;
	int XCord = -1;
	string name = "strange item";
	string description = "A strange item of unknown use.";
	long weight = 1;
	int value = 0;
}

//constructor
Item::Item(int xCord, int yCord, string name, string description, 
	string itemType, long weight, int value){
	setCord(xCord, yCord);
	setName(name);
	setDescription(description);
	setItemType(itemType);
	setWeight(weight);
	setValue(value);
}

void Item::setCord(int xCord, int yCord){
	this->xCord = xCord;
	this->yCord = yCord;
}

void Item::setName(string name){
	this->name = name;
}

void Item::setDescription(string description){
	this->description = description;
}

void Item::setItemType(string itemType){
	this->itemType = itemType;
}

void Item::setWeight(long weight){
	this->weight = weight;
}

void Item::setValue(int value){
	this->value = value;
}

int Item::getXCord(){
	return xCord;
}

int Item::getYCord(){
	return yCord;
}

string Item::getName(){
	return name;
}

string Item::getDescription(){
	return description;
}

string Item::getItemType(){
	return itemType;
}

long Item::getWeight(){
	return weight;
}

int Item::getValue(){
	return value;
}