/*
Desmond Darveau
Jul 25, 2015
Ver 1.01
Map.h
Game map.
A map is composed of locations.
*/
#include <fstream> //for file I/O
#include <array> //for 2D array of location objects
#include <vector> //for each row of location data read from the text file
#include <cstring> //for tokenization
#include "Location.h"

#include <iostream> //for cout and cin

using namespace std;

class Map {
public:
	Map(ifstream &);
	int getRows() const;
	int getColumns() const;
	char getMapChar(int, int) const;
	string getLocName(int, int) const;
	string getLocDesc(int, int) const; //get location description
	string getLocPreamble(int, int) const; //get location preamble

	void printMap(int, int) const;

private:
	
	Location createLocation(string);
};