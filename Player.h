/*
Desmond Darveau
Jul 25, 2015
Ver 1.01
Player.h
Player can move around the map (as long as location is not locked).
Player can interact with objects at some locations.  
Player has inventory.  
Player can:
-move in four directions
-take and drop items(effects location contents)
-talk to some things (NPCs)
-attack some things (mosters)
*/

//Include guard.
#ifndef PLAYER_H
#define PLAYER_H

#include "Creature.h"
#include "Weapon.h"

#include <string> //C++ standard string class
#include <time.h>  //for random seed


using namespace std;

//Location class defenition

class Player: public Creature{
public:
	Player(); //default constructor
	//XCord, yCord, name, max_hp, cur_hp, defense points,  min_dammage, max_dammage, max_carry, cur_carry, 
	//rightHand, leftHand, gold
	Player(int, int, string, int, int, int, int, int, int, int, Weapon &, Item &, int);
	void setMaxCarry(int);
	void setCurCarry(int);
	void setRightHand(Weapon);
	void setLeftHand(Item);
	void setGold(int);

	int getMaxCarry(void) const;
	int getCurCarry(void) const;
	Weapon getRightHand(void) const;
	Item getLeftHand(void) const;
	int getGold(void) const;

	int getDammage() const; //override base class function

private:
	int maxCarry; //Maxumum amount of inventory that the player can carry
	int curCarry; //Current amount of inventory that player is carrying
	Weapon rightHand; //Weapon player currently has in right hand
	Item leftHand; //Can only be a weapon or a sheild
	int gold;

};

#endif