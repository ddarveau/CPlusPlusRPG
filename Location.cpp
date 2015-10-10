/*
Desmond Darveau
Jul 25, 2015
Ver 1.01
Location.cpp
Location data is stored in a text file.  This will allow for saving of game state.
Will also allow for better game data management.
*/

#include "Location.h"  //Location class definiton
using namespace std;


//Default constructor
Location::Location() {

}

//constructor
Location::Location(string name, string description, string preamble, 
				   char mapChar, bool isLocked): 
				   name(name), description(description), preamble(preamble),
				   mapChar(mapChar), isLocked(isLocked){
}

void Location::setName(string name) {
	this->name = name;
}

void Location::setDescription(string description) {
	this->description = description;
}

void Location::setPreamble(string preamble) {
	this->preamble = preamble;
}

void Location::setMapChar(char mapChar) {
	this->mapChar = mapChar;
}

void Location::setIsLocked(bool isLocked) {
	this->isLocked = isLocked;
}

string Location::getName(void) const{
	return name;
}

string Location::getDescription(void) const{
	return description;
}

string Location::getPreamble(void) const{
	return preamble;
}

char Location::getMapChar(void) const{
	return mapChar;
}

bool Location::getIsLocked(void) const{
	return isLocked;
}