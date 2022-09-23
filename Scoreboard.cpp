#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <iomanip>
#include "Scoreboard.h"
#include "Player.h"

using namespace std;
//Constructor which sets all string variables to null 
//and declares the score as 0 and floor and difficulty as 1
scoreboard::scoreboard() {
	SB_Name = "null";
	SB_Score = 0;
	SB_Difficulty = "null";
	SB_Difficulty_Mod = 1;
	SB_Floor = 1;
}
//Constructor which takes in name and score of player as a parameter
scoreboard::scoreboard(string name, int score) {
	SB_Name = name;
	SB_Score = score;
	SB_Difficulty = "null";
	SB_Difficulty_Mod = 1;
	SB_Floor = 1;
}

void scoreboard::setNext(scoreboard* node) {
	next = node;
}

void scoreboard::setPrev(scoreboard* node) {
	prev = node;
}
scoreboard* scoreboard::getNext() {
	return next;
}
scoreboard* scoreboard::getPrev() {
	return prev;
}

/*Getter methods*/
//Returns the name of the player
string scoreboard::getName() {
	return SB_Name;
}
//Returns the score of the player
int scoreboard::getScore() {
	return SB_Score;
}
//Returns the difficulty level
string scoreboard::getDifficulty() {
	return SB_Difficulty;
}
//Returns the integer value of the difficulty level
int scoreboard::getDifficultyMod() {
	return SB_Difficulty_Mod;
}
//Return the floor value
int scoreboard::getFloor() {
	return SB_Floor;
}

/*Setter methods*/
//Sets the name of the player
void scoreboard::setName(string name) {
	this->SB_Name = name;
}
//Sets the score of the player
void scoreboard::setScore(int score) {
	this->SB_Score = score;
}
//Sets the difficulty level
void scoreboard::setDifficulty(string difficulty) {
	this->SB_Difficulty = difficulty;
}
//Sets the integer value of the difficulty level
void scoreboard::setDifficultyMod(int mod) {
	this->SB_Difficulty_Mod = mod;
}
//Sets the floor level
void scoreboard::setFloor(int floor) {
	this->SB_Floor = floor;
}

//Adds points to the score
void scoreboard::SB_AddScore(int points) {
	SB_Score += points;
}
//Prints out the name, score, difficulty level, difficulty integer and floor of the player
void scoreboard::SB_out() {
	cout << "Player name: " << SB_Name << ", Score: " << SB_Score << ", Difficulty: "
		<< SB_Difficulty << ", " << "Floor: " << SB_Floor << endl;
}
//Prints the name and score of the player
void scoreboard::sprint() {
	cout << "Name: " << getName() << " " << "Score: " << getScore() << endl;
}
//outputs scoreboard data to the file
ostream& operator<<(ostream& os, const scoreboard& p)
{
	os << p.SB_Name << " " << p.SB_Score;
	return os;
}