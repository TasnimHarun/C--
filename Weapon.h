#pragma once
#include <string>
#include<iostream>

using namespace std;
class Weapon
{
private:
	string item;
	//Name of the weapon item
	int damage;
	//Attack damage to the item. This can be added or removed by the player
	double price;
	//price of the weapon
	bool equipped;
	// used to check if you have brought the weapon to use
	int uses;
	//The amount of uses/ "durablity" the weapon has left:
	Weapon* next;

	Weapon* prev;
public:
	// constructors of the weapons
	Weapon();
	Weapon(string item, int damage, double price, bool equipped, int uses);

	// We need functions that will return the name of item and be able to change item name
	string getItem();
	void setItem(string i);

	// We need functions that will return the damage of weapon and set the damage of the weapon
	int getDamage();
	void setDamage(int d);

	// We need functions that will return the price of weapon and set the price of the weapon
	double getPrice();
	void setPrice(double p);

	bool getEquipped();
	void setEquipped(bool e);

	int getUses();
	void setUses(int u);

	void setNext(Weapon* next);
	void setPrev(Weapon* prev);

	Weapon* getNext();
	Weapon* getPrev();

	void print();
};