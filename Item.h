/*
Desmond Darveau
Aug 16, 2015
Ver 1.01
Item.h
Abstract class.  Used for things that have:
-name
-weight
-description
-value(gold)
*/

//Include guard.
#ifndef ITEM_H
#define ITEM_H

#include <string> //C++ standard string class
using namespace std;

//Item class defenition

class Item{
public:
	Item(); //default constructor
	//xCord, yCord, name, description, itemType, weight, value
	Item(int, int, string, string, string, long, int);  //base class constructor

	void setCord(int, int);
	void setName(string);
	void setDescription(string);
	void setItemType(string);
	void setWeight(long); //weight is in pounds (roughly).  So a gold coin would be aprox 0.001 (4.5 grams).
	void setValue(int); //in gold coins

	int getXCord();
	int getYCord();
	string getName();
	string getDescription();
	string getItemType();
	long getWeight();
	int getValue();

protected:
	int xCord;
	int yCord;
	string name;
	string description;
	string itemType;
	long weight;
	int value;
};

#endif /*INCLUDE_H*/