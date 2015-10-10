 /*
Desmond Darveau
Aug 03, 2015
Ver 1.01
Enemy.h


*/

//Include guard.
#ifndef ENEMY_H
#define ENEMY_H

#include "Creature.h"

#include <string> //C++ standard string class
#include <time.h>  //for random seed

using namespace std;

//Location class defenition

class Enemy : public Creature{
public:
	Enemy(); //default constructor.
	//X, Y, name, description,  hasEncountered, response, drops, max_hp, Cur_hp, defencePoints, MinDammage, MaxDammage
	Enemy(int, int, string, string, bool, string, string, int, int, int, int, int);
	
	string getDescription() const;
	bool getHasEncountered() const;
	string getResponse() const;
	string getDrops() const;
	int getDammage() const; //get the amount of dammage enemy deals on a "dice roll"

	void setDescription(string);
	void setHasEncountered(bool);
	void setResponse(string);
	void setDrops(string);

private:


	string description;		//A detailed description of the enemy.  
	bool hasEncountered;	//print description only on first encounter of the enemy.
	string response;		//what the enemy says when player talks to it.
	string drops;			//what the enemy drops when killed.
};

#endif