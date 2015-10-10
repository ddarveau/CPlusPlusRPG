/*
Desmond Darveau
Jul 25, 2015
Ver 1.01
Main.cpp
Initiates game.
Game is a text adventure with a 2D map as a GUI.
Note:	If you want to run this program from the console, you must copy locations.txt to the debug folder.
		If you run from MS Visual Studio, the file is read from the directory above the debug folder.
*/
#include <iostream> //for cout and cin
#include <iomanip> //for setw(n)
#include <fstream> //for file I/O
#include <vector>  //for collection of enemies
#include <algorithm>

#include "Map.h"
#include "Player.h"
#include "Enemy.h"
#include "Weapon.h"
#include "Inventory.h"
using namespace std;

void printMessage(string);
Enemy setActiveEnemy(Enemy&);

Enemy activeEnemy;
int activeEnemyArrayPos = -1;
Weapon activeWeapon;
Armor activeArmor;
Potion activePotion;

string getIntroMessage();
Enemy spawnEnemy(string);		//takes a text string, tokenizes it and returns an enemy object.
Weapon spawnWeapon(string);		//takes a text string, tokenizes it and returns a weapon object.

int main() {

	system("cls"); //clear screen
	string diag = "\nStarting game. \n";//troubleshooting

	//load enemies file.  For standard enemies.
	ifstream mapFile("locations.txt", ios::in);  //"ios::in" opens the file for reading only
	if (!mapFile) { //file could not be opened
		cerr << "locations file could not be opened." << endl;
		exit(EXIT_FAILURE);
	}
	//invoke Map object by passing a reference to the text file
	Map firstMap(mapFile);
	
	mapFile.close();
	//Load map text file
	ifstream enemyFile("enemies.txt", ios::in);  //"ios::in" opens the file for reading only
	if (!enemyFile) { //file could not be opened
		cerr << "enemies file could not be opened." << endl;
		exit(EXIT_FAILURE);
	}

	//Load weapons text file
	/*ifstream weaponFile("weapons.txt", ios::in);  //"ios::in" opens the file for reading only
	if (!weaponFile) { //file could not be opened
		cerr << "weapons file could not be opened." << endl;
		exit(EXIT_FAILURE);
	}*/

	/*Variable declarations*/
	int playerDammage = 0;		//Player dammage. Needed in Attack switch.  
	bool playerAttacked = false;	//to manage player/monster attack turns
	

	int monsterDammage = 0;
	string userInput = ""; //Input for main game loop
	string userInput2 = ""; //For inventory loop
	string userInput3 = ""; //For inventory item interaction loop

	string message = getIntroMessage(); //Message to user.
	string message2 = ""; //For inventory screen.
	string message3 = ""; //For inventory item interaction screen.

	string chosenItemType; //For inventory management
	string chosenItemName; //For inventory management

	/*flag to denote monster, NPC or weapon event.
	Player must then be given different options to choose from.
	To do: May want to create an Event object.
	*/
	string event = "";


	//load all enemy types in a vector
	string line;
	//int lines = 0;
	vector<Enemy> enemies;
	while (getline(enemyFile, line)) {
		Enemy enemy(spawnEnemy(line));
		enemies.push_back(enemy);
		//lines++;
	}//end while
	enemyFile.close();

	//load weapons
	//string line;
	//int lines = 0;
	/*vector<Weapon> weapons;
	while (getline(weaponFile, line)) {
		Weapon weapon(spawnWeapon(line));
		weapons.push_back(weapon);
		//lines++;
	}//end while
	weaponFile.close();
	*/

	//Weapon testWeapon(0, 0, "test weapon", "", 1, 1, 0, 1);
	//Item testItem(0, 0, "test item", "", 0, 0);
	//X, Y, name, description, itemType, weight, value, minDammage, maxDammage
	Weapon fist(-1,-1,"fist", "bare hands", "weapon", 0,0,0,1);
	//cout << "Test weapon value: " << testWeapon.getValue();
	//Item testItem;

	//create player
	//XCord, yCord, name, max_hp, cur_hp, defense points,  min_dammage, max_dammage, max_carry, cur_carry, 
	//rightHand, leftHand, gold
	Player player1(1, 2, "Ric Fre", 25, 25, 0, 0, 1, 50, 0, fist, fist, 0);
	//Player player1();

	//Load player inventory
	Inventory playerInventory("playerInventory.txt");

	//Load map inventory
	Inventory mapInventory("mapInventory.txt");

	//Show map and message for the first time.
	firstMap.printMap(player1.getXCord(), player1.getYCord());
	printMessage(message);

	/*MAIN GAME LOOP*/
	//process player moves and redraw map.
	//"q" to quit game. Also exit on player death.
	while ((userInput != "q" && userInput != "Q")  && player1.getCur_hp() > 0) {
		//Player options
		cout << "Go:" << endl;
		cout << "1. North" << endl;
		cout << "2. East" << endl;
		cout << "3. South" << endl;
		cout << "4. West" << endl;
		cout << "Q. Quit" << endl;
		cout << "" << endl;
		if (event == "monster") {
			cout << "5. Attack" << endl;
			cout << "6. Talk" << endl; 
		}
		
		if (event == "item") {
			cout << "7. Take" << endl;
		}

		cout << "8. Inventory" << endl;

		if (!(cin >> userInput)){
			cin.clear(); //clear error flag
			cin.ignore(80, '\n'); //empty buffer
			message = "Could not store player response.";
		}
		else if (userInput == "q" || userInput == "Q") {
			message = "Thanks for playing!";
		}
		else {
			//convert string to int for switch statement
			int mapDir = atoi(userInput.c_str());
			switch (mapDir){
			
			case 1:
				//Move north
				if (player1.getXCord() - 1 < 0){ //we know that values less that zero are out of map bounds
					message = "You can't go further north.";
				}
				else if (firstMap.getMapChar(player1.getXCord() - 1, player1.getYCord()) == 'R'){//check the map char of next location
					message = "you can't move there.  Jagged rocks block your way.";
				}
				else {//move player
					player1.setCord(player1.getXCord() - 1, player1.getYCord());
					event = "move";
					//read description of current location from text file
					message = firstMap.getLocDesc(player1.getXCord(), player1.getYCord());
					//Read prequil of each adjoning location (N,W,E,S)
					message += firstMap.getLocPreamble(player1.getXCord(), player1.getYCord());
				}
				break;

			case 2:
				//Move east
				if (player1.getYCord() + 1 >= firstMap.getColumns()){ //Check to see if next move takes player beyond map boundaries
					message = "You can't go further east.";
				}
				else if (firstMap.getMapChar(player1.getXCord(), player1.getYCord() + 1) == 'R'){//check the map char of next location
					message = "you can't move there.  Jagged rocks block your way.";
				}
				else {//move player
					player1.setCord(player1.getXCord(), player1.getYCord() + 1);
					event = "move";
					//read description of current location from text file
					message = firstMap.getLocDesc(player1.getXCord(), player1.getYCord());
					//Read prequil of each adjoning location (N,W,E,S)
					message += firstMap.getLocPreamble(player1.getXCord(), player1.getYCord());
				}
				break;

			case 3:
				//Move south
				if (player1.getXCord() + 1 >= firstMap.getRows()){ //Check to see if next move takes player beyond map boundaries
					message = "You can't go further south.";
				}
				else if (firstMap.getMapChar(player1.getXCord() + 1, player1.getYCord()) == 'R'){//check the map char of next location
					message = "you can't move there.  Jagged rocks block your way.";
				}
				else {//move player
					player1.setCord(player1.getXCord() + 1, player1.getYCord());
					event== "move";
					//read description of current location from text file
					message = firstMap.getLocDesc(player1.getXCord(), player1.getYCord());
					//Read prequil of each adjoning location (N,W,E,S)
					message += firstMap.getLocPreamble(player1.getXCord(), player1.getYCord());
				}
				break;

			case 4:
				//Move west
				if (player1.getYCord() - 1 < 0){ //we know that values less that zero are out of map bounds
					message = "You can't go further west.";
				}
				else if (firstMap.getMapChar(player1.getXCord(), player1.getYCord() - 1) == 'R'){//check the map char of next location
					message = "you can't move there.  Jagged rocks block your way.";
				}
				else {//move player
					player1.setCord(player1.getXCord(), player1.getYCord() - 1);
					event = "move";
					//read description of current location from text file
					message = firstMap.getLocDesc(player1.getXCord(), player1.getYCord());
					//Read prequil of each adjoning location (N,W,E,S)
					message += firstMap.getLocPreamble(player1.getXCord(), player1.getYCord());
				}
				break;

			case 5:
				//Attack
				playerAttacked = true;
				playerDammage = player1.getDammage();
				//diag += "weapon min dammage is " + to_string(player1.getRightHand().getMinDammage()) + "\n";
				//diag += "Weapon dammage is " + to_string(player1.getRightHand().getDammage()) + "\n";
				//diag += "Weapon dammage is " + to_string(player1.getRightHand().getDammage()) + "\n";

					message = "-" + to_string(playerDammage) + " dammage to " + activeEnemy.getName() + ".\n";
				//diag += activeEnemy.getName() + " has " + to_string(activeEnemy.getCur_hp()) + " HP.\n";
				//check to see if enemy dies
				if (activeEnemy.sufferDammage(playerDammage) == true) {
					message += activeEnemy.getName() + " dies of its wounds.\n ";
					event = "";
					//activeEnemy.setCord(-1, -1); //move enemy off map.  It is dead.
					enemies[activeEnemyArrayPos].setCord(-1, -1);
					playerAttacked = false;
				}
				else {
					message += activeEnemy.getName() + " has " + to_string(activeEnemy.getCur_hp()) + " HP.\n";
					message += " the " + activeEnemy.getName() + " circles around you and readies for another attack.";
				}//end else
				break;

			case 6:
				//Talk
				break;

			case 7:
				//Take
				//Show numerated list of items at current location.
				system("cls");
				mapInventory.listItemsAt(player1.getXCord(), player1.getYCord());
				//while user does not press "q", allow her to take items.  
				//Reprint items available each time a item is taken.
				while (userInput2 != "q"){
					if (mapInventory.getItemCount(player1.getXCord(), player1.getYCord()) < 1){
						cout << "There is nothing else to take.";
					}else {
						cout << "\nSelect an item: ";
					}
					if (!(cin >> userInput2)){
						cin.clear(); //clear error flag
						cin.ignore(80, '\n'); //empty buffer
						message = "\nCould not store player response.";
					}else if (atoi(userInput2.c_str()) > mapInventory.getItemCount(player1.getXCord(), player1.getYCord()) ||
						atoi(userInput2.c_str()) < 1 ){
						//selection is out of bounds
						message = "\n" + userInput2 + " is an invalid selection.\n";
					}else if (userInput2 != "q"){
						//We need to know the item type that we are dealing with in order to allocate to the correct inventory array.
						//Get item type and then have inventory return the entire object to us.  
						chosenItemType = mapInventory.getItemTypeAt(player1.getXCord(), player1.getYCord(), stoi(userInput2) - 1);
						chosenItemName = mapInventory.getItemNameAt(player1.getXCord(), player1.getYCord(), stoi(userInput2) - 1);
						message = "You took " + chosenItemName + "\n";

						if (chosenItemType == "weapon"){
							//remove and return a Weapon object from map inventory and add it to player inventory.
							playerInventory.addItem(mapInventory.removeWeapon(chosenItemName, player1.getXCord(), player1.getYCord()));
						}
						else if (chosenItemType == "armor"){
							playerInventory.addItem(mapInventory.removeArmor(chosenItemName, player1.getXCord(), player1.getYCord()));
						}
						else if (chosenItemType == "potion"){
							playerInventory.addItem(mapInventory.removePotion(chosenItemName, player1.getXCord(), player1.getYCord()));
						}
						else {
							message = "There is nothing to take.\n";
						}
					}//end else
					printMessage(message);
					mapInventory.listItemsAt(player1.getXCord(), player1.getYCord());
				}//end while

				userInput2 = "";
				break;

			case 8:
				//Inventory
	
				while (userInput2 != "q"){
					system("cls");
					playerInventory.printInventory();

					//cout << message;

					cout << "\nSelect an item: ";

					//Show options for interaction (equip, use, drop)

					if (!(cin >> userInput2)){
						cin.clear(); //clear error flag
						cin.ignore(80, '\n'); //empty buffer
						message = "\nCould not store player response.";
					}
					else if (atoi(userInput2.c_str()) > playerInventory.getItemCount()){
						//selection is out of bounds
						message = "\n" + userInput2 + " is an invalid selection.\n";
						//message += "";
					}
					else if (userInput2 != "q"){
						while (userInput3 != "q" && userInput3 != "3"){

							//Select item and show options to drop, equip, use, etc.
							//message2 = "\nUser selected " + userInput2 + ".\n";
							//message2 = "Item is: " + playerInventory.getItem(stoi(userInput2)).getName() + ".\n";
							//cout << message2;
							


							//Player options
							cout << "1. Use" << endl;
							cout << "2. Equip" << endl;
							cout << "3. Drop" << endl;

							if (!(cin >> userInput3)){
								cin.clear(); //clear error flag
								cin.ignore(80, '\n'); //empty buffer
								message = "\nCould not store player response.";
							}
							//enter switch if input is between 1 and 3
							else if (atoi(userInput3.c_str()) > 0 && atoi(userInput3.c_str()) < 4) {
							//else {
								//convert string to int for switch statement
								int itemInt2 = atoi(userInput3.c_str());
								switch (itemInt2){
								case 1:
									//Use.  For Potions
									message = "You can't yet use things.";
									break;

								case 2:
									//Equip.  For armor and weapons
									
									chosenItemType = playerInventory.getItemType(stoi(userInput2) - 1);
									chosenItemName = playerInventory.getItemName(stoi(userInput2) - 1);
									
									if (chosenItemType == "weapon"){
										player1.setRightHand(playerInventory.getItemByName(chosenItemName));
										message = "\nYou equipped " + chosenItemName	 + "\n";
									}else if (chosenItemType == "armor"){
										player1.setRightHand(playerInventory.getItemByName(chosenItemName));
										message = "\nYou equipped " + chosenItemName + "\n";
									}else {
										message = "\nYou can not equip " + chosenItemName + "\n";
									}

									break;
								case 3:
									//Drop
									chosenItemType = playerInventory.getItemType(stoi(userInput2) - 1);
									chosenItemName = playerInventory.getItemName(stoi(userInput2) - 1);
									message = "\nYou dropped " + playerInventory.getItemName(stoi(userInput2) - 1) + "\n";

									//remove and return a Item object from map inventory and add it to player inventory.	
									if (chosenItemType == "weapon"){
										//set item location before dropping
										mapInventory.addItem(playerInventory.removeWeapon(chosenItemName, player1.getXCord(), player1.getYCord()));
									}else if(chosenItemType == "armor"){
										mapInventory.addItem(playerInventory.removeArmor(chosenItemName, player1.getXCord(), player1.getYCord()));
									}else if (chosenItemType == "potion"){
										mapInventory.addItem(playerInventory.removePotion(chosenItemName, player1.getXCord(), player1.getYCord()));
									}
								break;

								default:
									message = "You can't do that here (Error).";
								}//end switch
							}//end else. For item interactions
							printMessage(message);
						}//End while. For item interactions.
						userInput3 = "";
					}//end else.  For Inventory item selection.
					//cout << message2;
				}//end while.

				

				userInput2 = ""; //Must reset in order to access inventory again.
				userInput3 = ""; //Must reset in order to access inventory again.
				//message2 = "";
				break;
			case 9:
				//Help screen(?)

				break;
			default:
				message = "You can't do that here (Error).";
			}//end switch (for N,E,S,W move cases, attack, talk etc.)
		}//end else

		/*check to see if player is currently in battle.  
		If yes, don't bother looking for another monster on that location.*/
		if (event != "monster"){
			for (int i = 0; i < enemies.size(); i++){
				//Check to see if player lands on a location with a monster. 
				if (player1.getXCord() == enemies[i].getXCord() && player1.getYCord() == enemies[i].getYCord()) {
					//two below variables are needed by "attack" switch.
					activeEnemy = setActiveEnemy(enemies[i]);
					activeEnemyArrayPos = i;
					//Add notification that player has encountered a monster event.
					message += "A " + activeEnemy.getName() + " jumps out of the bushes.";
					event = "monster";
					//diag += "Found " + activeEnemy.getName() + "with " + to_string(activeEnemy.getCur_hp()) + "\n";
				}
			}//end for.  Marks the end of initial enemy encounter.
			//If player attacked, it's the enemy's turn.  Attack player!
		}//end if.  Check for enemy.
		
		//if currently in battle, monster gets to attack.
		if (event  == "monster"){
			monsterDammage = activeEnemy.getDammage();
			if (player1.sufferDammage(monsterDammage) == true) {
				//Player dies.  Game over.
				/*To do: Allow player the option to continue.  Take player back to village,
				but remove 50 gold in healing costs*/
				message += "You suffer -" + to_string(monsterDammage) + " dammage and die of your wounds.\n\n";
				message += "GAME OVER!\n";
			}
			else {
				message += "You suffer - " + to_string(monsterDammage) + " dammage.\n";
				message += "You have " + to_string(player1.getCur_hp()) + " HP remaining.\n";
			}
		}//end if
		
		//check to see if player lands on a village
		else if (firstMap.getLocName(player1.getXCord(), player1.getYCord()).compare("Village") == 0){
			player1.set_hp(player1.getMax_hp());
			message += "You are able to rest and restore your health.\n";
		}

		//check to see if player lands on a location with an item
		else if (mapInventory.checkLocations(player1.getXCord(), player1.getYCord())){
			event = "item";
			message += mapInventory.getItemsAt(player1.getXCord(), player1.getYCord());
		}

		/*for (auto &weapon : weapons){
			if (player1.getXCord() == weapon.getXCord() && player1.getYCord() == weapon.getYCord()) {
				activeWeapon = weapon;
				//Add notification that player has encountered a monster event.
				message += "You notice the glint of a " + activeWeapon.getName() + " within your reach.";
				event = "weapon";
			}
		}//end for.  Marks the end of initial weapon encounter.
		*/

		//clear screen
		system("cls");

		//redraw map
		firstMap.printMap(player1.getXCord(), player1.getYCord());
		printMessage(message);
		cout << "Diagnostics:\n";

		cout << diag << "End round.\n\n";
		//diag += "Player X: " + to_string(player1.getXCord()) + "\n";
		//diag += "Player Y: " + to_string(player1.getYCord()) + "\n";


	}//end while
}

void printMessage(string message) {
	cout << message << endl << endl;
}

string getIntroMessage() {
	string introMessage1 = "***************\n*The Alchemist\n****************\n";
	string introMessage2 = "You are a young child in a remote village.\n";
	string introMessage3 = "You often wonder about the world beyond these huts and fields.\n";
	string introMessage4 = "But it is forbidden to venture out alone.\n";
	string message = introMessage1 + introMessage2 + introMessage3 + introMessage4;
	return message;
}

Enemy spawnEnemy(string line) {
	//cout << "Line is " << line << endl;
	char *tokenPtr = strtok(&line[0], ";");
	int xCord = stoi(tokenPtr);	//convert string to int
	int yCord = stoi(strtok(NULL, ";"));
	string name = strtok(NULL, ";");
	string description = strtok(NULL, ";");
	bool hasEncountered = strtok(NULL, ";");
	string response = strtok(NULL, ";");
	string drops = strtok(NULL, ";");
	int max_hp = stoi(strtok(NULL, ";"));
	int cur_hp = stoi(strtok(NULL, ";"));
	int dp = stoi(strtok(NULL, ";"));
	int minDammage = stoi(strtok(NULL, ";"));
	int maxDammage = stoi(strtok(NULL, ";"));

	//X, Y, name, description,  hasEncountered, response, drops, max_hp, cur_hp, minDammage, maxDammage
	Enemy enemy(xCord, yCord, name, description, hasEncountered, response, drops, max_hp, cur_hp, dp, minDammage, maxDammage);
	return enemy;
}

Weapon spawnWeapon(string line){
	//cout << "Line is " << line << endl;
	char *tokenPtr = strtok(&line[0], ";");
	int xCord = stoi(tokenPtr);	//convert string to int
	int yCord = stoi(strtok(NULL, ";"));
	string name = strtok(NULL, ";");
	string description = strtok(NULL, ";");
	string itemType = strtok(NULL, ";");
	int weight = stoi(strtok(NULL, ";"));
	int value = stoi(strtok(NULL, ";"));
	int minDammage = stoi(strtok(NULL, ";"));
	int maxDammage = stoi(strtok(NULL, ";"));

	//X, Y, name, description, weight, value, minDammage, maxDammage
	Weapon weapon(xCord, yCord, name, description, itemType, weight, value, minDammage, maxDammage);
	return weapon;
}

//For attack switch to know what enemy to attack. 
//I'm trying to pass by reference here, but I don't think it is working properly.
Enemy setActiveEnemy(Enemy& enemy){
	return enemy;
	
}

