#include <string> 
#include <stdlib.h>
#include <time.h>
#include "Player.h"

player::player() {
	setName("");
	setMaxHP(0);
	setHP(0);
	setDMG(0);
	setMoney(0);
}
//Default constructor

player::player(string Name, int MaxHealth, int HealthPoints, int AttackDamage, int Level) {
	setName(Name);
	setMaxHP(MaxHealth);
	setHP(HealthPoints);
	setDMG(AttackDamage);
	setLVL(0);
	setMoney(0);
}
//Paramaterized Constructor

// ~ ~ ~ Getter Functions ~ ~ ~ 
string player::getName() {
	return Name;
}
// Returns the players name

int player::getMaxHP() {
	return MaxHealth;
}
// Returns the players maximum health

int player::getHP() {
	return HealthPoints;
}
// Returns the players current health points

int player::getDMG() {
	return AttackDamage;
}
// Returns the players attack damage

int player::getMoney() {
	return Money;
}

int player::getLVL() {
	return Level;
}
// Returns the players money


// ~ ~ ~ Setter Functions ~ ~ ~ 
void player::setName(string Name) {
	this->Name = Name;
}
// Sets players name

void player::setMaxHP(int MaxHealth) {
	this->MaxHealth = MaxHealth;
}
// Sets players maximum health

void player::setHP(int HealthPoints) {
	this->HealthPoints = HealthPoints;
}
// Sets players current health

void player::setDMG(int AttackDamage) {
	this->AttackDamage = AttackDamage;
}
// Sets players attack damage

void player::setMoney(int Money) {
	this->Money = Money;
}
// Sets the players money

void player::setLVL(int Level) {
	this->Level = Level; 
}

// ~ ~ ~ Modifiers ~ ~ ~ 
void player::ModifyHealth(int value) {
	HealthPoints -= value;
}
// Modifies the players health by the value given

void player::ModifyDamage(int value) {
	AttackDamage += value;
}
// Modifies the players damage by the value given

void player::ModifyMoney(int Money) {
	this->Money += Money;
}
// Modifies the players money by the value given

// Player Crit
int player::getCritical(int AttackDamage) {
	srand(time(NULL));
	int chance = rand() % 100;
	if (chance > AttackDamage) {
		return 1;
	}
	else {
		return 2;
	}
}