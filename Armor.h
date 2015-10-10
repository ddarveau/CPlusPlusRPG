/*
Desmond Darveau
Aug 16, 2015
Ver 1.01
Armor.h

*/

//Include guard.
#ifndef ARMOR_H
#define ARMOR_H

#include <string> //C++ standard string class

#include "Item.h"
using namespace std;

//Armor class defenition

class Armor : public Item{
public:
	Armor(); //default constructor
	Armor(int, int, string, string, string, long, int, int, string);

	string getBody() const;
	int get_dr () const;

	void set_dr(int);  //may want to allow defence rating to be changed.

private:
	string body; //part of body on wich armor is worn
	int dr; //defense rating

	void setBody(string);  //should not need to change what body part armor is used on

};

#endif