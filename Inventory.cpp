/*
Desmond Darveau
Sep 13, 2015
Ver 1.02
Inventory.cpp

*/

#include "Inventory.h" //Item class definition

//#include <iostream> //for cout and cin. for debugging.
#include <fstream> //for file I/O
#include <iostream> //for cout and cin
#include <iomanip> //for setw(n)
#include <vector>  //for collections of different items
#include <string> //for getline

#include "Weapon.h"

using namespace std; 
//vector<Armor> armorSets;
//vector<Potion> potions;
//vector<Weapon> weapons;



//Default constructor
Inventory::Inventory(){

}

//constructor
Inventory::Inventory(string file){
	//Load weapons text file
	ifstream inventoryFile(file, ios::in);  //"ios::in" opens the file for reading only
	if (!inventoryFile) { //file could not be opened
		cerr << "Player Inventory file could not be opened." << endl;
		exit(EXIT_FAILURE);
	}

	string line;
	while (getline(inventoryFile, line)) {
		//Item Type is 5th string in text file.  All items have these attributes.
		char *tokenPtr = strtok(&line[0], ";");
		int xCord = stoi(tokenPtr);	//convert string to int
		int yCord = stoi(strtok(NULL, ";"));
		string name = strtok(NULL, ";");
		string description = strtok(NULL, ";");
		string itemType = strtok(NULL, ";");
		long weight = stol(strtok(NULL, ";"));
		int value = stoi(strtok(NULL, ";"));

		if (itemType == "armor"){
			int dr = stoi(strtok(NULL, ";"));//get remaining attributes
			string body = strtok(NULL, ";");
			Armor thisArmor (xCord, yCord, name, description, itemType, weight, value, dr, body);//invoke object
			armorSets.push_back(thisArmor);//allocate to inventory
		
		}else if(itemType == "potion") {
			string effect = strtok(NULL, ";");
			int points = stoi(strtok(NULL, ";"));
			Potion thisPotion(xCord, yCord, name, description, itemType, weight, value, effect, points);
			potions.push_back(thisPotion);
		
		}else if(itemType == "weapon"){
			int minDammage = stoi(strtok(NULL, ";"));
			int maxDammage = stoi(strtok(NULL, ";"));
			Weapon thisWeapon(xCord, yCord, name, description, itemType, weight, value, minDammage, maxDammage);
			//cout << "Weapon created. Value: " << thisWeapon.getValue() << endl;
			weapons.push_back(thisWeapon);
		}
	}//end while
	inventoryFile.close();
	
	//initialize counter variables
	//weaponCount = 0;
	//armorCount = 0;
	//potionCount = 0;
	//itemCount = 0;

}//end constructor

void Inventory::addItem(Weapon thisWeapon){
	weapons.push_back(thisWeapon);
}

void Inventory::addItem(Armor thisArmor){
	armorSets.push_back(thisArmor);
}

void Inventory::addItem(Potion thisPotion){
	potions.push_back(thisPotion);
}

//index all items at a specific location and add the one at a particular location.
void Inventory::addItem(int xCord, int yCord, int arrayPosition){
	
}

/*
void Inventory::removeItem(Weapon thisWeapon){
	for (int i = 0; i < weapons.size(); ++i){
		if (weapons[i].getName() == thisWeapon.getName()) {
			//remove object
			weapons.erase(weapons.begin() + i);
		}
	}
}

void Inventory::removeItem(Potion thisPotion){
	for (int i = 0; i < potions.size(); ++i){
		if (potions[i].getName() == thisPotion.getName()) {
			//remove object
			potions.erase(potions.begin() + i);
		}
	}
}

void Inventory::removeItem(Armor thisArmor){
	for (int i = 0; i < armorSets.size(); ++i){
		if (armorSets[i].getName() == thisArmor.getName()) {
			//remove object
			armorSets.erase(armorSets.begin() + i);
		}
	}
}
*/
Weapon Inventory::removeWeapon(string itemName, int xCord, int yCord){
	Weapon newWeapon;
	for (int i = 0; i < weapons.size(); ++i){
		if (weapons[i].getName() == itemName) {
			//Invoke new Weapon
			newWeapon = weapons[i];
			//set item location to player current location
			newWeapon.setCord(xCord, yCord);
			//Delete old weapon
			weapons.erase(weapons.begin() + i);
		}
	}
	return newWeapon;
}

Armor Inventory::removeArmor(string itemName, int xCord, int yCord){
	Armor newArmor;
	for (int i = 0; i < armorSets.size(); ++i){
		if (armorSets[i].getName() == itemName) {
			//Invoke new Weapon
			newArmor = armorSets[i];
			newArmor.setCord(xCord, yCord);
			//Delete old weapon
			armorSets.erase(armorSets.begin() + i);
		}
	}
	return newArmor;
}

Potion Inventory::removePotion(string itemName, int xCord, int yCord){
	Potion newPotion;
	for (int i = 0; i < potions.size(); ++i){
		if (potions[i].getName() == itemName) {
			//Invoke new Weapon
			newPotion = potions[i];
			newPotion.setCord(xCord, yCord);
			//Delete old weapon
			potions.erase(potions.begin() + i);
		}
	}
	return newPotion;
}



//return number of items of each type.
int Inventory::getItemCount(){
	return itemCount;
}

//get number of items at a specific location
int Inventory::getItemCount(int xCord, int yCord){
	int count = 0;
	for (auto & weapon : weapons){
		if (weapon.getXCord() == xCord && weapon.getYCord() == yCord) {
			count += 1;
		}
	}

	for (auto & armor : armorSets){
		if (armor.getXCord() == xCord && armor.getYCord() == yCord) {
			count += 1;
		}
	}

	for (auto & potion : potions){
		if (potion.getXCord() == xCord && potion.getYCord() == yCord) {
			count += 1;
		}
	}
	return count;
}

//check X & Y coordinates in invenory.  If there is a match, return true, else return false.
bool Inventory::checkLocations(const int & xCord, const int & yCord) {
	bool result = false;
	for (auto & weapon : weapons){
		if (weapon.getXCord() == xCord && weapon.getYCord() == yCord) {
			result = true;
		}
	}

	for (auto & armor : armorSets){
		if (armor.getXCord() == xCord && armor.getYCord() == yCord) {
			result = true;
		}
	}

	for (auto & potion : potions){
		if (potion.getXCord() == xCord && potion.getYCord() == yCord) {
			result = true;
		}
	}
	return result;
}

//Show name of all items with specific X and Y Coordinates.
string Inventory::getItemsAt(int xCord, int yCord){
	string itemString = "Items:\n";
	for (auto &weapon : weapons){
		if (weapon.getXCord() == xCord && weapon.getYCord() == yCord) {
			itemString += weapon.getName() + "\n";
		}
	}

	for (auto &armor : armorSets){
		if (armor.getXCord() == xCord && armor.getYCord() == yCord) {
			itemString += armor.getName() + "\n";
		}
	}

	for (auto &potion : potions){
		if (potion.getXCord() == xCord && potion.getYCord() == yCord) {
			itemString += potion.getName() + "\n";
		}
	}
	return itemString;
}

//Search all items with specific X and Y coordinates.  Remove an item based on sequence.
void Inventory::removeItem(int xCord, int yCord, int arrayPosition){
	int apos = 1;
	for (int i = 0; i < weapons.size(); ++i){
		if (weapons[i].getXCord() == xCord && weapons[i].getYCord() == yCord) {
			if (arrayPosition == apos){
				weapons.erase(weapons.begin() + i);
			}else{
				++apos;
			}
		}
	}

	for (int i = 0; i < armorSets.size(); ++i){
		if (armorSets[i].getXCord() == xCord && armorSets[i].getYCord() == yCord) {
			if (arrayPosition == apos){
				armorSets.erase(armorSets.begin() + i);
			}
			else{
				++apos;
			}
		}
	}

	for (int i = 0; i < potions.size(); ++i){
		if (potions[i].getXCord() == xCord && potions[i].getYCord() == yCord) {
			if (arrayPosition == apos){
				potions.erase(potions.begin() + i);
			}
			else{
				++apos;
			}
		}
	}
}

Weapon Inventory::getItemByName(string itemName){
	Weapon chosenWeapon;
	for (auto &weapon : weapons){
		if (weapon.getName() == itemName) {
			chosenWeapon = weapon;
		}
	}
	return chosenWeapon;
}

//List name of all items with specific X and Y Coordinates.
void Inventory::listItemsAt(int xCord, int yCord){
	int itemNum = 0;
	for (auto &weapon : weapons){
		if (weapon.getXCord() == xCord && weapon.getYCord() == yCord) {
			++itemNum;
			cout << itemNum << ". " << weapon.getName() << "\n";
		}
	}

	for (auto &armor : armorSets){
		if (armor.getXCord() == xCord && armor.getYCord() == yCord) {
			++itemNum;
			cout << itemNum << ". " << armor.getName() << "\n";
		}
	}

	for (auto &potion : potions){
		if (potion.getXCord() == xCord && potion.getYCord() == yCord) {
			++itemNum;
			cout << itemNum << ". " << potion.getName() << "\n";
		}
	}
}

string Inventory::getItemType(int arrayPosition){
	int itemNum = 0;
	for (auto &weapon : weapons){
		if (arrayPosition == itemNum){
			return weapon.getItemType();
		}
		else{
			++itemNum;
		}
	}

	for (auto &armor : armorSets){
		if (arrayPosition == itemNum){
			return armor.getItemType();
		}
		else{
			++itemNum;
		}
	}

	for (auto &potion : potions){
		if (arrayPosition == itemNum){
			return potion.getItemType();
		}
		else{
			++itemNum;
		}
	}
}

string Inventory::getItemName(int arrayPosition){
	int itemNum = 0;
	for (auto &weapon : weapons){
		if (arrayPosition == itemNum){
			return weapon.getName();
		}
		else{
			++itemNum;
		}
	}

	for (auto &armor : armorSets){
		if (arrayPosition == itemNum){
			return armor.getName();
		}
		else{
			++itemNum;
		}
	}

	for (auto &potion : potions){
		if (arrayPosition == itemNum){
			return potion.getName();
		}
		else{
			++itemNum;
		}
	}
}

//index all items at a specifix location and return the name of one item based on sequence
string Inventory::getItemTypeAt(int xCord, int yCord, int arrayPosition){
	int itemNum = 0;
	for (auto &weapon : weapons){
		if (weapon.getXCord() == xCord && weapon.getYCord() == yCord) {
			if (arrayPosition == itemNum){
				return weapon.getItemType();
			}
			else{
				++itemNum;
			}
		}
	}

	for (auto &armor : armorSets){
		if (armor.getXCord() == xCord && armor.getYCord() == yCord) {
			if (arrayPosition == itemNum){
				return armor.getItemType();
			}
			else{
				++itemNum;
			}
		}
	}

	for (auto &potion : potions){
		if (potion.getXCord() == xCord && potion.getYCord() == yCord) {
			if (arrayPosition == itemNum){
				return potion.getItemType();
			}
			else{
				++itemNum;
			}
		}
	}
}

//index all items at a specifix location and return the name of one item based on sequence
string Inventory::getItemNameAt(int xCord, int yCord, int arrayPosition){
	int itemNum = 0;
	for (auto &weapon : weapons){
		if (weapon.getXCord() == xCord && weapon.getYCord() == yCord) {
			if (arrayPosition == itemNum){
				return weapon.getName();
			}
			else{
				++itemNum;
			}
		}
	}

	for (auto &armor : armorSets){
		if (armor.getXCord() == xCord && armor.getYCord() == yCord) {
			if (arrayPosition == itemNum){
				return armor.getName();
			}
			else{
				++itemNum;
			}
		}
	}

	for (auto &potion : potions){
		if (potion.getXCord() == xCord && potion.getYCord() == yCord) {
			if (arrayPosition == itemNum){
				return potion.getName();
			}
			else{
				++itemNum;
			}
		}
	}
}

void Inventory::printInventory(){
	weaponCount = 0;
	armorCount = 0;
	potionCount = 0;
	itemCount = 0;

	cout << "Inventory\n";
	//Show weapons
	cout << "\nWeapons:\n";
	cout << setw(5) << std::left << "No." 
		 << setw(20) << std::left << "Name" 
		 << setw(10) << "Weight" 
		 << setw(10) << "Gold" 
		 << setw(10) << "Dammage" << endl;
	for (auto & weapon : weapons){
		++weaponCount;
		++itemCount;
		cout << setw(5) << itemCount
			 << setw(22) << std::left << weapon.getName() 
			 << setw(9) << weapon.getWeight() 
			 << setw(10) << weapon.getValue()
			 << weapon.getMinDammage() << " - " << weapon.getMaxDammage() << endl;

	}//end for

	//Show Armor
	cout << "\nArmor:\n";
	cout << setw(5) << std::left << "No."
		<< setw(20) << std::left << "Name"
		<< setw(10) << "Weight"
		<< setw(10) << "Gold"
		<< setw(10) << "Defense" << endl;
	for (auto & armor : armorSets){
		++armorCount;
		++itemCount;
		cout << setw(5) << itemCount
			<< setw(22) << std::left << armor.getName()
			<< setw(9) << armor.getWeight()
			<< setw(10) << armor.getValue()
			<< armor.get_dr() << endl;

	}//end for

	//Show potions
	cout << "\npotions:\n";
	cout << setw(5) << std::left << "No."
		<< setw(20) << std::left << "Name"
		<< setw(10) << "Weight"
		<< setw(10) << "Gold"
		<< setw(15) << "Effect"
		<< setw(10) << "Points" << endl;
	for (auto & potion : potions){
		++potionCount;
		++itemCount;
		cout << setw(5) << itemCount
			<< setw(22) << std::left << potion.getName()
			<< setw(9) << potion.getWeight()
			<< setw(10) << potion.getValue()
			<< setw(15) << potion.getEffect() 
			<< potion.getPoints()
			<< endl;

	}//end for

}