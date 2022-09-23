#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include "Player.h"

using namespace std;

class scoreboard {
private:
	string SB_Name;	//name of player
	int SB_Score;	//score of player. Updates after every combat
	string SB_Difficulty;
	int SB_Difficulty_Mod;
	int SB_Floor;
	scoreboard* next;
	scoreboard* prev;
public:
	//Contructor for the class
	scoreboard();
	//Parameterized constructor which takes in name and score of player
	scoreboard(string name, int score);

	/*Getter methods*/
	//Function which returns the string name of the player
	string getName();
	//Function which returns integer score of the player
	int getScore();
	//Function which returns string difficulty of the player
	string getDifficulty();
	//Function which returns the integer value of the selected difficulty
	int getDifficultyMod();
	//Function which returns the integer value of the floor
	int getFloor();
	void setNext(scoreboard* next);
	void setPrev(scoreboard* prev);
	scoreboard* getNext();
	scoreboard* getPrev();


	/*Setter methods*/
	//Function which sets the name of the player
	void setName(string n);
	//Function which sets the value of the score
	void setScore(int score);
	//Function which sets the string difficulty
	void setDifficulty(string difficulty);
	//Function which sets the integer difficulty
	void setDifficultyMod(int mod);
	//Function which sets the floor value
	void setFloor(int floor);

	//operator overload
	//bool operator <(const scoreboard& s2) const;
	//Function which prints the name and score of the player
	void sprint();
	//Function which adds points to the score
	void SB_AddScore(int points);
	//Function which prints information about the player's score and difficulty
	void SB_out();
	friend ostream& operator <<(ostream& os, const scoreboard& p);
	//outputs scoreboard data to the file
};