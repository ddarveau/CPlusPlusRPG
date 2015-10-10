/*
Desmond Darveau
Aug 03, 2015
Ver 1.01
Wolf.cpp
*/


#include "Creature.h"
#include "Enemy.h" //Enemy class definition
//#include <iostream> //for cout and cin. for debugging.
using namespace std;

//Default constructor

Enemy::Enemy(){
	int xCord = 0;
	int yCord = 0;
	name = "base enemy";
	max_hp = 10;
	cur_hp = max_hp;
	minDammage = 1;
	maxDammage = 1;
}

//constructor
//X, Y, name, description, hasEncountered, response, drops, max_hp, cur_hp, defensePoints MinDammage, MaxDammage
Enemy::Enemy(int xCord, int yCord, string name, string description, 
	bool hasEncountered, string response, string drops,
	int max_hp, int cur_hp, int dp, int minDammage, int maxDammage)/*:
	description(description), hasEncountered(hasEncountered), response(response),
	drops(drops)*/
{
	setCord(xCord, yCord);
	setName(name);
	setDescription(description);
	setHasEncountered(hasEncountered);
	setResponse(response);
	setDrops(drops);
	setMax_hp(max_hp);
	set_hp(cur_hp);
	set_dp(dp);
	setMinDammage(minDammage);
	setMaxDammage(maxDammage);
	/* initialize random seed: */
	srand(time(NULL));
}

void Enemy::setDescription(string description){
	this->description = description;
}

void Enemy::setHasEncountered(bool hasEncountered){
	this->hasEncountered = hasEncountered;
}

void Enemy::setResponse(string response){
	this->response = response;
}

void Enemy::setDrops(string drops){
	this->drops = drops;
}

string Enemy::getDescription() const{
	return description;
	;
}
bool Enemy::getHasEncountered() const{
	return hasEncountered;
	;
}
string Enemy::getResponse() const{
	return response;
	;
}

string Enemy::getDrops() const{
	return drops;
}

//get the amount of dammage enemy deals on a "dice roll"
int Enemy::getDammage() const{
	//dammage = rand() % 3 + 1;
	int dammage = rand() % getMaxDammage() + getMinDammage();
	return dammage;
}