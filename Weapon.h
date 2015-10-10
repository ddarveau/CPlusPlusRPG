/*
Desmond Darveau
Aug 16, 2015
Ver 1.01
Wolf.h
-Growls when you talk to it
-Drops wolf pelt when killed
*/

//Include guard.
#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"

#include <string> //C++ standard string class
#include <time.h>  //for random seed

using namespace std;

//Weapon class defenition

class Weapon : public Item{
public:
	Weapon(); //default constructor.

	//Constructor
	//X, Y, name, description, itemType, weight, value, minDammage, maxDammage
	Weapon(int, int, string, string, string, long, int, int, int);

	int getMinDammage() const;
	int getMaxDammage() const;

	void setMinDammage(int);
	void setMaxDammage(int);
	int getDammage() const;

private:
	int minDammage;
	int maxDammage;
};

#endif