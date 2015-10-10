/*
Desmond Darveau
Aug 02, 2015
Ver 1.01
Creature.h
Abstract class.  Used for things that have:
-x & y coordinates
-HP
-Can attack
Player should also inherit from creature
*/

//Include guard.
#ifndef CREATURE_H
#define CREATURE_H

#include <string> //C++ standard string class
using namespace std;

//Creature class defenition

class Creature{
public:
	Creature(); //default constructor
	//XCord, yCord, Name, max_hp, cur_hp, defencePoints, minDammage, maxDammage
	Creature(int , int , string, int, int, int, int, int);  //base class constructor
	//~Creature(); //destructor

	void setCord(int, int);
	void setName(string);
	void setMax_hp(int);
	void set_hp(int);
	void set_dp(int);
	void setMinDammage(int);
	void setMaxDammage(int);

	int getXCord() const;
	int getYCord() const;
	string getName() const;
	int getMax_hp() const;
	int getCur_hp() const;
	int get_dp() const;
	int getMinDammage() const;
	int getMaxDammage() const;

	//use min and max dammage values to calculate dammage done to player
	int getDammage() const;

	//return true if remaining HP are less than or equal to zero
	bool sufferDammage(int);
	
	bool attack();

protected:
	int xCord;			//current x coordinate on the map
	int yCord;			//current y coordinate on the map
	string name;		//creature name
	int max_hp;			//maximum hit points
	int cur_hp;			//current hit points
	int dp;				//percentage of dammage absorbed by armor
	int minDammage;		//minimum base dammage
	int maxDammage;		//maximim base dammage

private:
	void die();
};

#endif /*INCLUDE_H*/