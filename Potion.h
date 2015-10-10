/*
Desmond Darveau
Aug 16, 2015
Ver 1.01
Potion.h
Can:
Heal HP
(Increase DR)
(Increase dammage)
Note: Player will drink potion.  Player class changes its own stats.
*/

//Include guard.
#ifndef POTION_H
#define POTION_H

#include <string> //C++ standard string class

#include "Item.h"
using namespace std;

//Potion class defenition
//xCord, yCord, name, description, itemType, weight, value, effect, points
class Potion : public Item{
public:
	Potion(); //default constructor
	Potion(int, int, string, string, string, long, int, string, int);

	string getEffect() const;
	int getPoints() const;

private:
	string effect; //effect that the potion has
	int points; //severity of effect

	void setEffect(string);  //this shoud not change with a potion
	void setPoints(int);	//this shoud not change with a potion
};

#endif