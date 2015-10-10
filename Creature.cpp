/*
Desmond Darveau
Aug 03, 2015
Ver 1.01
Creature.cpp

*/

#include "Creature.h" //Creature class definition
//#include <iostream> //for cout and cin. for debugging.
using namespace std;

//Default constructor
Creature::Creature(){
	int xCord = 0;
	int yCord = 0;
	name = "strange creature";
	int max_hp = 10;
	int hp = 10;
	int minDammage = 2;
}

//constructor
Creature::Creature(int xCord, int yCord, string name, 
	int max_hp, int cur_hp, int dp, int minDammage, int maxDammage):
	xCord(xCord), yCord(yCord), name(name), 
	max_hp(max_hp), cur_hp(cur_hp), dp(dp), minDammage(minDammage), maxDammage(maxDammage){
	/*setCord(xCord, yCord);
	setName(name);
	setMax_hp(max_hp);
	set_hp(cur_hp);
	set_dp(dp);
	setMinDammage(minDammage);
	setMaxDammage(maxDammage);*/

}

void Creature::setCord(int xCord, int yCord){
	this->xCord = xCord;
	this->yCord = yCord;
	
}

void Creature::setName(string name){
	this->name = name;
}

void Creature::setMax_hp(int max_hp){
	this->max_hp = max_hp;
}

void Creature::set_hp(int cur_hp){
	this->cur_hp = cur_hp;
}

void Creature::set_dp(int dp){
	this->dp = dp;
}

void Creature::setMinDammage(int minDammage){
	this->minDammage = minDammage;
}

void Creature::setMaxDammage(int maxDammage){
	this->maxDammage = maxDammage;
}

int Creature::getXCord() const{
	return xCord;
}

int Creature::getYCord() const{
	return yCord;
}

string Creature::getName() const{
	return name;
}

int Creature::getMax_hp() const{
	return max_hp;
}

int Creature::getCur_hp() const{
	return cur_hp;
}

int Creature::get_dp() const{
	return dp;
}

int Creature::getMinDammage() const{
	return minDammage;
}

int Creature::getMaxDammage() const{
	return maxDammage;
}

//get the amount of dammage enemy deals on a "dice roll"
int Creature::getDammage()  const{
	//dammage = rand() % 3 + 1;
	int dammage = rand() % getMaxDammage() + getMinDammage();
	return dammage;
}

//return true if remaining HP are less than or equal to zero
bool Creature::sufferDammage(int dammage) {
	cur_hp -= dammage;
	if (cur_hp <= 0) {
		return true;
	}else{
		return false;
	}
}
//
void die() {

}