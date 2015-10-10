/*
Desmond Darveau
Sep 13, 2015
Ver 1.02
Inventory.h
Contains arrays for:
-weapons, armor and potions
*/

//Include guard.
#ifndef INVENTORY_H
#define INVENTORY_H

#include <string> //C++ standard string class
#include <vector> //for vectors

#include "Weapon.h"
#include "Armor.h"
#include "Potion.h"

using namespace std;

//Inventory class defenition

class Inventory{
public:
	Inventory();  //default constructor
	
	//Load each item in the corresponding vector.
	Inventory(string); //Takes the name of playerInventory text file.

	void addItem(Weapon);
	void removeItem(Weapon);
	void addItem(Armor);
	void removeItem(Armor);
	void addItem(Potion);
	void removeItem(Potion);

	//remove and return a Weapon object from map inventory and add it to player inventory.
	//Set item location to player current position
	//playerInventory.addItem(mapInventory.removeWeapon(chosenItemName));
	Weapon removeWeapon(string, int, int);
	Armor removeArmor(string, int, int);
	Potion removePotion(string, int, int);

	//index all items at a specific location and add the one at a particular location.
	void addItem(int, int, int); //x, y, arrayPosition 

	//index all items at a specific location and remove the one at a particular location. 
	void removeItem(int, int, int); //x, y, arrayPosition

	//return number of items of each type.
	//item types are counted seperately in print function.  Only need item counts
	//for UI, so this should be okay.
	int getItemCount();
	int getItemCount(int, int);
		//get number of items at a specific location
	/*
	Weapon getWeapon(int, int, int); //return an inventory item based on location menu numbers.
	Armor getArmor(int, int, int); //return an inventory item based on location menu numbers.
	Potion getPotion(int, int, int); //return an inventory item based on location menu numbers.
	*/

	Weapon getItemByName(string); //return an item based on its name.


	//check X & Y coordinates in invenory.  If there is a match, return true.
	bool checkLocations(const int &, const int &); //no need to copy or change values
	
	string getItemsAt(int, int); //Concatenate and return all items with specific X and Y Coordinates.
	void listItemsAt(int, int); //Show all items with specific X and Y Coordinates.

	//index all items and return Item Type at a specified array position 
	string getItemType(int);
	string getItemName(int);

	//index all items at a specifix location and return the name of one item based on sequence
	string getItemTypeAt(int, int, int);
	string getItemNameAt(int, int, int);
	
	void printInventory(); //Displays an ordered list of all inventory items. 



private:
	/*We do not have access to derived class member functions if 
	we store pointers to these objects in a base-class vector.
	So a vector of class Item will not allow us to print all 
	item specs.*/
	vector<Weapon> weapons;
	vector<Armor> armorSets;
	vector<Potion> potions;

	int weaponCount;
	int armorCount;
	int potionCount;
	int itemCount;

	void setInventory(string);  //read text file and place weapon in corresponding vector.  
	vector<Weapon> getWepons(); //should not need access to entire arrays.
	vector<Armor> getArmor();
	vector<Potion> getPotions();

};

#endif