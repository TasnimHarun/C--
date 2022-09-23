#include "Weapon.h"
#include <string>
#include<iostream>
#include <iomanip>
using namespace std;

Weapon::Weapon()// this is the default constuctor, therefore it is not necessary to set a value to anything yet
{
	item = "N/A";
	damage = 12;
	price = 30;
	equipped = false;
	uses = 5;

}
Weapon::Weapon(string i, int d, double p, bool e, int u)//this constuctor will be used to create the weapons within our game with the values we want
{
	item = i;
	damage = d;
	price = p;
	equipped = e;
	uses = u;
}
string Weapon::getItem() // This will return items name
{
	return item;
}
void Weapon::setItem(string i) //this will change the items name
{
	item = i;
}
int Weapon::getDamage() // this will return the weapon damage
{
	return damage;
}
void Weapon::setDamage(int d) // this will change the weapon damage
{
	damage = d;
}
double Weapon::getPrice() // this will return the weapon damage
{
	return price;
}
void Weapon::setPrice(double p) // this will change the weapon damage
{
	price = p;
}
bool Weapon::getEquipped() // this will return the weapon is equpiied or not
{
	return equipped;
}
void Weapon::setEquipped(bool e) // this change if the weapon is equipped or not
{
	equipped = e;
}
int Weapon::getUses() // this will return the weapon damage
{
	return uses;
}
void Weapon::setUses(int u) // this will change the weapon damage
{
	uses = u;
}
void Weapon::setNext(Weapon* next)
{
	this->next = next;
}
void Weapon::setPrev(Weapon* prev)
{
	this->prev = prev;
}

Weapon* Weapon::getNext()
{
	return next;
}
Weapon* Weapon::getPrev()
{
	return prev;
}
void Weapon::print()
{
	cout << setw(15) << left << item
		<< setw(10) << left << damage
		<< setw(10) << left << price
		<< setw(10) << left << equipped
		<< setw(10) << left << uses << endl;
}