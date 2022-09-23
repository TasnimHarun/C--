#pragma once
#include <iostream>
#include <string> 
#include "Weapon.h"

using namespace std;

class player
{
private:
	string Name;
	// This should hold the player’s name

	int MaxHealth;
	// This should hold the maximum health of the player

	int HealthPoints;
	// This should hold the current health of the player

	int AttackDamage;
	// This should hold the attack damage of the player

	int Level;
	// This should hold the player level. 

	int Money;
	// This should hold the currency of the player


public:
	player();
	// Default constructor

	player(string, int, int, int, int);
	// Paramaterized constructor


	// ~ ~ ~ Getter Functions ~ ~ ~ 
	string getName();
	// Returns the player name

	int getMaxHP();
	// Returns the players maximum health

	int getHP();
	// Returns the players current health

	int getDMG();
	// Returns the players current damage

	int getMoney();
	// Returns the players money

	int getLVL();
	// Returns the players level

	// ~ ~ ~ Setter Functions ~ ~ ~
	void setName(string);
	// Sets the players name

	void setMaxHP(int);
	// Sets the players maxmimum health points

	void setHP(int);
	// Sets the players current health

	void setDMG(int);
	// Sets the players current damage

	void setMoney(int);
	// Sets the players money

	void setLVL(int);
	// Sets the 

	// ~ ~ ~ Modifiers ~ ~ ~
	void ModifyHealth(int);
	// Increments or decrements the player’s health by the input value

	void ModifyDamage(int);
	// Increments or decrements the player’s attack damage by the input value

	void ModifyMoney(int);
	// Increments or decrements the player's currency.

	friend ostream& operator <<(ostream& os, const player& p);

	// ~ ~ ~ Test ~ ~ ~ 
	int getCritical(int);

};

// Inherits "Enemy" from the Player class 
class enemy : public player
{
public:
	// Default construtor for Enemy
	enemy() {
		setName("");
		setMaxHP(0);
		setHP(0);
		setDMG(0);
		setLVL(0);
	}

	// Paramaterized constructor for Enemy
	enemy(string Name, int MaxHealth, int HealthPoints, int AttackDamage, int Level) {
		setName(Name);
		setMaxHP(MaxHealth);
		setHP(HealthPoints);
		setDMG(AttackDamage);
		setLVL(Level);
		setMoney(0);
	}

	// Returns the money dropped by an enemy
	int getMoney() {
		return (getLVL() + 1) * 5;
	}

	// Returns the damage dealt by an enemy
	int getAttack(int AttackDamage) {
		srand(time(NULL));
		int chance = rand() % 100; // Assings chance a random number between 0 and 100
		int damage = AttackDamage;

		if (chance >= 95) { // %5 chance that Damage is increased by 50%
			damage = AttackDamage + (int)(getDMG() / 2);
		}

		else if (chance >= 90) { // 5% chance that Damage is increased by 25%
		damage = AttackDamage + (int)(getDMG() / 4);
		}
	
		else if (chance >= 80) { // 10% chance that Damage is increased by 20%
			damage = AttackDamage + (int)(getDMG() / 5);
		}

		else if (chance >= 70) { // 10% chance that Damage is decreased by 10%
			damage = AttackDamage - (int)(getDMG() / 10);
		}
	
		else if (chance >= 45) { // 25% chance that Damage is increased by 10%
			damage = AttackDamage + (int)(getDMG() / 10);
		}

		else if (chance >= 20) { // 20% chance that Damage is increased by 5%
			damage = AttackDamage + (int)(getDMG() / 20);
		}

		return damage;
	}

};