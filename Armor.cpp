/*
Desmond Darveau
Aug 26, 2015
Ver 1.01
Armor.cpp

*/

#include "Armor.h" //Item class definition
//#include <iostream> //for cout and cin. for debugging.
using namespace std;
//Default constructor
Armor::Armor(){

}

//constructor
//xCord, yCord, name, description, itemType, weight, value, effect, points
Armor::Armor(int xCord, int yCord, string name, string description,
	string itemType, long weight, int value, int dr, string body)
{
	setCord(xCord, yCord);
	setName(name);
	setDescription(description);
	setItemType(itemType);
	setWeight(weight);
	setValue(value);
	set_dr(dr);
	setBody(body);
}

void Armor::set_dr(int dr){
	this->dr = dr;
}

void Armor::setBody(string body){
	this->body = body;
}

int Armor::get_dr() const{
	return dr;
}

string Armor::getBody() const{
	return body;
}