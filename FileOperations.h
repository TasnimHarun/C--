
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>
#include "Scoreboard.h"
#include "ScoreboardList.h"
#include "WeaponsList.h"
#include "Weapon.h"
#include "Player.h"
using namespace std;

class FileOperations
{
private:
	string SB_file_name;
	//holds the name of the scoreboard file
	fstream SB_myFile;
	ofstream SBO_myFile;
	//opens the scoreboard file
	string P_file_name;
	//holds the name of the player file
	fstream P_myFile;
	//write and read into player file
	ifstream PI_myFile;
	//inputed into player
	ofstream Po_myFile;
	//outputs player file
public:
	//Creates object FileOperations
	FileOperations();
	//Save2File for all the player, scoreboard, and Weapons variables needed to load the game
	void Save2File(player& p, scoreboard& sb, WeaponsList& w);
	//Save2File for all the scoreboard objects 
	void Save2File(scoreboard& sb);
	//ChooseFile allows the player to select a preexisting file which has their history saved, and allows them to play from they have started
	void ChooseFile(scoreboard& sb, player& p, string name, WeaponsList& w);
	//Function which reads the text file and loads into the scoreboard list
	void ReadFile(ScoreboardList& sl);
	//checks if the file exists already, if it does not it creates one
	void Player(string name);
	//checks if a scoreboard exists, if not it creates one.
	void Scoreboard(ScoreboardList& sl);
	//Closes file after use
	void CloseFile();
};