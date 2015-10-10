/*
Desmond Darveau
Jul 27, 2015
Ver 1.01
Player.cpp
Player issues move request to map. 
Map responds to move request with yes or no.
Player then actions accordingly.
*/

#include <iostream> //for cout and cin.  For testing
#include "Creature.h"
#include "Player.h" //Player class definition

using namespace std;

//Default constructor

Player::Player(){
	int xCord = 0;
	int yCord = 0;
	name = "Player 1";
	max_hp = 10;
	cur_hp = max_hp;
	minDammage = 1;
	maxDammage = 2;
}

//constructor
//XCord, yCord, name, max_hp, cur_hp, defense points,  min_dammage, max_dammage, max_carry, cur_carry, 
//rightHand, leftHand, gold
Player::Player(int xCord, int yCord, string name, int max_hp, int hp, int dp, 
	int minDammage, int maxDammage, int maxCarry, int curCarry, 
	Weapon & rightHand, Item & leftHand, int gold){
	setCord(xCord, yCord);
	setName(name);
	setMax_hp(max_hp);
	set_hp(hp);
	set_dp(dp);
	setMinDammage(minDammage);
	setMaxDammage(maxDammage);
	setMaxCarry(maxCarry);
	setCurCarry(curCarry);

	

	setRightHand(rightHand);
	setLeftHand(rightHand);
	setGold(gold);

	/* initialize random seed: */
	srand(time(NULL));
}

void Player::setMaxCarry(int maxCarry){
	this->maxCarry = maxCarry;
}

void Player::setCurCarry(int curCarry){
	this->curCarry = curCarry;
}

void Player::setRightHand(Weapon rightHand){
	this->rightHand = rightHand;
}

void Player::setLeftHand(Item leftHand){
	this->leftHand = leftHand;
}

void Player::setGold(int gold){
	this->gold += gold;
}

int Player::getMaxCarry(void) const{
	return maxCarry;
}

int Player::getCurCarry(void) const{
	return curCarry;
}

Weapon Player::getRightHand(void) const{
	return rightHand;
}

Item Player::getLeftHand(void) const{
	return leftHand;
}

int Player::getGold(void) const{
	return gold;
}

int Player::getDammage() const{
	//get player base class dammage and add weapon dammage.

	int dammage = Creature::getDammage() + rightHand.getDammage();
	cout << "Player getDammage function called.";
	
	return dammage;

}