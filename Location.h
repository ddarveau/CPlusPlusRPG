/*
Desmond Darveau
Jul 25, 2015
Ver 1.01
Location.h
Location data is stored in a text file.  This will allow for saving of game state.
Will also allow for better game data management.
*/

#include <string> //C++ standard string class
#include <iostream> //for cout and cin

using namespace std;

//Location class definition
class Location{
public:
	Location(); //default constructor

	//name, location, preamble, mapChare, isLocked
	Location(string, string, string, char, bool);
	void setName(string);
	void setDescription(string);
	void setPreamble(string);
	void setMapChar(char);
	void setIsLocked(bool);

	string getName() const;
	string getDescription() const; //When on the location
	string getPreamble() const; //when looking toward the location
	char getMapChar() const;
	bool getIsLocked() const;

private:
	string name; //short name of location.   A standard location like a trees or rock will have a generic description
	string description; //special description of the location.  Used for special locations like monster lairs or villages.
	string preamble; //when looking toward the location
	
	char mapChar; //Char value for map
	bool isLocked; //If locked, a player cannot move onto that cell

};
