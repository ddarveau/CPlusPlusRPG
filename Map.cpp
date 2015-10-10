/*
Desmond Darveau
Jul 26, 2015
Ver 1.01
Map.cpp
A map is composed of locations.  Location data are read from a text file.
*/

#include "Map.h"
const int rows = 10; //Will eventually be an 10 x 10 2D array, but start with 2 rows while testing.
const int columns = 10;
array<array<Location, columns>, rows> mapArray;  //Map array initialized to null

//map constructor creates locations by reading location data from a text file
Map::Map(ifstream &inputfile){
	string line;
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			getline(inputfile, line);
			//cout << "Line is " << line << endl;
			//create each map location
			Location thisLocation = createLocation(line);
			//load each map into an array
			mapArray[i][j] = thisLocation;
			//cout << "array " << i << "," << j << " loaded" << endl;
		 }
	}
	//cout << "Hit end of for rows..." << endl;
}

int Map::getRows() const{
	return rows;
}

int Map::getColumns() const{
	return columns;
}

//Get Location map char based on map coordinates
char Map::getMapChar(int x, int y) const{
	return mapArray[x][y].getMapChar();
}

string Map::getLocName(int x, int y) const{
	return mapArray[x][y].getName();
}

string Map::getLocDesc(int x, int y) const{
	return mapArray[x][y].getDescription() + "\n\n";
}

string Map::getLocPreamble(int x, int y) const{
	string northPreamble = "";
	string eastPreamble = "";
	string southPreamble = "";
	string westPreamble = "";

	if (x - 1 < 0) {
		northPreamble = "To the north lies a towering cliffside.  ";
	}
	else{
		northPreamble = "To the north lies " + mapArray[x - 1][y].getPreamble() + ".  ";
	}

	if (y + 1 >= getColumns()) {
		eastPreamble = "To the east lies a towering cliffside.  ";
	}
	else{
		eastPreamble = "To the east lies " + mapArray[x][y + 1].getPreamble() + ".  ";
	}

	if (x + 1 >= getRows()) {
		southPreamble = "To the south lies a towering cliffside.  ";
	}
	else{
		southPreamble = "To the south lies " + mapArray[x + 1][y].getPreamble() + ".  ";
	}

	if (y - 1 < 0) {
		westPreamble = "To the west lies a towering cliffside.";
	}
	else{
		westPreamble = "To the west lies " + mapArray[x][y - 1].getPreamble() + ".  ";
	}
	return northPreamble + eastPreamble + southPreamble + westPreamble + "\n\n";
}

Location Map::createLocation(string line){
	//cout << "Line read is: " << line << endl;
	char *tokenPtr = strtok(&line[0], ";");
	string name = tokenPtr;
	string description = strtok(NULL, ";");
	//cout << "Description is: " << description << endl;
	string preamble = strtok(NULL, ";");
	string mapCharS = strtok(NULL, ";");
	char mapChar =mapCharS[0];
	//cout << "char is: " << mapChar;
	bool isLocked = strtok(NULL, ";");

	Location thisLocation = Location(name, description, preamble, mapChar, isLocked);
	return thisLocation;
}

//Print map
void Map::printMap(int xCord, int yCord) const{
	cout << "Map:" << endl;
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			//If this is player location, print player char
			if (xCord == i && yCord == j){
				cout << "P" << "  ";
			//else print map char
			}else {
				cout << mapArray[i][j].getMapChar() << "  ";
			}
		}
		cout << endl;
		cout << endl;
	}
}