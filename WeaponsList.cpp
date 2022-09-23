#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "WeaponsList.h"
#include "Weapon.h"
#include "Player.h"
#include <iomanip>


using namespace std;

WeaponsList::WeaponsList()
{
	head = NULL;
	tail = NULL;
	current = NULL;
}
/*We want this function to only print the user's weapons that they have in their inventory
Therefore we check the boolean Equipped to check if the user has the weapon before printing the weapon
if the player does not have the weapon we do not print the weapon*/
WeaponsList:: ~WeaponsList()
{
	
		if (head == NULL)
			return;

		if (head->getNext() != 0)
		{
			delete this->head->getNext();
		}
		delete this->head;

}
// Adds a weapon into the linked list 
void WeaponsList::addWeapon(Weapon* weapon)
{
	if (head == NULL)
	{
		head = current = tail = weapon;
	}
	else
	{	
		tail->setNext(weapon);
		weapon->setPrev(tail);
		tail = tail->getNext();
	
	}

}

Weapon* WeaponsList::getCurrent()
{
	return current;
}

void WeaponsList::setTail(Weapon* tail)
{
	this->tail = tail;
}


//moves to the next node
void WeaponsList::moveToNext()
{
	if (current->getNext() != NULL) {
		current = current->getNext();
	}
	else {
		moveToHead();
	}

}
//moves current to the previous  
void WeaponsList::moveToPrev()
{
	if (current->getPrev() != NULL) {
		current = current->getPrev();
	}
	else {
		moveToTail();
	}
}
//moves current to tail
void WeaponsList::moveToTail() 
{ 
	current = tail;
}
//moves to the the head
void WeaponsList::moveToHead() {
	current = head;
}
//Using the addWeapon function, adds certain weapons depending on the floor the player is on
void WeaponsList::loadAll(scoreboard sb, player p)
{
	
	switch (sb.getFloor())
	{
	case 1:

			addWeapon(new Weapon("Ruler", 9, 5, 0, 8));
			addWeapon(new Weapon("Slingshot", 8, 5, 0, 9));
			addWeapon(new Weapon("Pen", 15, 4, 0, 7));
			break;
	


	case 2:
		addWeapon(new Weapon("Ruler", 9, 5, 0, 8));
		addWeapon(new Weapon("Slingshot", 8, 5, 0, 9));
		addWeapon(new Weapon("Pen", 15, 4, 0, 7));
		addWeapon(new Weapon("Bow", 20, 15, 0, 10));
		break;

	case 3:
		addWeapon(new Weapon("Ruler", 9, 5, 0, 8));
		addWeapon(new Weapon("Slingshot", 8, 5, 0, 9));
		addWeapon(new Weapon("Pen", 15, 4, 0, 7));
		addWeapon(new Weapon("Bow", 20, 15, 0, 10));
		addWeapon(new Weapon("Sword", 25, 15, 0, 8));
		addWeapon(new Weapon("Axe", 35, 25, 0, 7));
		break;

	case 4:
		addWeapon(new Weapon("Ruler", 9, 5, 0, 8));
		addWeapon(new Weapon("Slingshot", 8, 5, 0, 9));
		addWeapon(new Weapon("Pen", 15, 4, 0, 7));
		addWeapon(new Weapon("Bow", 20, 15, 0, 10));
		addWeapon(new Weapon("Sword", 25, 15, 0, 8));
		addWeapon(new Weapon("Axe", 35, 25, 0, 7));
		addWeapon(new Weapon("Mace", 60, 40, 0, 5));
		break;

	default:
		cout << "Floor is not accurate to print out weapons" << endl;
		break;
	}
}

// Prints all the weapons in the double linked list
void WeaponsList::printAll()
{
	WeaponPtr temp = head;

	cout << setw(15) << "Item" << setw(10) << "Damage" << setw(10) << " Price" << setw(10) << "Equipped" << setw(10) << "Uses" << endl;
	cout << "________________________________________________" << endl;
	while (temp != NULL) {

		temp->print();
		temp = temp->getNext();

	}

}

//Clears all nodes in the double linked list
void WeaponsList::clear()
{
	Weapon* temp = new Weapon();
	while (head != NULL)
	{
		temp = head;
		head = head->getNext();
		free(temp);

	}
}
// Returns the weapons List vector
vector <Weapon> WeaponsList::getWeaponsL()
{
	return WeaponsL;
}
/*This Weapon List is used to add items into the game, directly with their values*/
void WeaponsList::addItem(string i, int d, double p, bool e, int u)
{
	WeaponsL.push_back(Weapon(i, d, p, e, u));
}
// Deleted the Item given the name
void WeaponsList::deleteItem(string item)
{
	for (int i = 0; i < WeaponsL.size(); i++)
	{
		if (WeaponsL[i].getItem() == item) {
			WeaponsL.erase(WeaponsL.begin() + i);
		}
	}
}
//Returns the weapon& given the name of the weapon by finding match in name and getItem
Weapon& WeaponsList::getWeapon(string name) {

	for (int i = 0; i < WeaponsL.size(); i++) {

		if (WeaponsL[i].getItem() == name)
		{
			return WeaponsL[i];
			break;
		}

	}
}
//Returns the Weapon at index i
Weapon& WeaponsList::getWeapon(int i) {
	return WeaponsL[i];
}
// Prints the weapons in the vector
void WeaponsList::printAllL()
{

	cout << setw(10) << left << "Number" << setw(10) << "Item" << setw(10) << "Damage" << setw(10) << " Price" << setw(10) << "Equipped" << setw(10) << "Uses" << endl;
	cout << "____________________________________________________" << endl;
	for (int i = 0; i < WeaponsL.size(); i++)// for now I put -1
	{

		cout << setw(1) << left << i + 1 << setw(9) << ")" << setw(12) << WeaponsL.at(i).getItem() << setw(11)//calling a position that does not exist, 
			<< WeaponsL.at(i).getDamage() << setw(10)
			<< WeaponsL.at(i).getPrice();

		if (WeaponsL[i].getItem()._Equal("Dagger")) {
			cout << setw(8) << WeaponsL.at(i).getEquipped() << setw(6) << "Unl" << "\n";
		}
		else {
			cout << setw(9) << WeaponsL.at(i).getEquipped() << setw(6) << WeaponsL[i].getUses() << "\n";
		}

	}
	cout << "\n";
}
//Looks if the weapon exists within the linked list, if not return false
bool WeaponsList::search(Weapon* head, string w)
{

	if (head == NULL)
		return false;


	if (head->getItem() == w)
		return true;

	return search(head->getNext(), w);
}

/* By iterating through each node, checks if the string weapon is equal to the getItem of the node being checked. If true then it adds item to the inventory
* then it deleted the node from the list by reassigning the pointers, returns the weapon's string*/


// sorry the sloth socks stay on during debugging
string WeaponsList::buyWeapon(string weapon, WeaponsList& Inv)
{
	Weapon* temp = head;
	bool weaponFound = false;
	if (temp == NULL)
	{
		cout << "You do not have any Weapons" << endl;
	}
	while (temp != NULL)
	{
		if (temp->getItem() == weapon)
		{
			weaponFound = true;
			if (current == temp)
			{
				Inv.addItem(temp->getItem(), temp->getDamage(), temp->getPrice(), temp->getEquipped(), temp->getUses());
				if (temp == tail)
				{
						if (temp == head) {
								head = NULL;
								tail = NULL;
								current = NULL;
								cout << "Saved Weapon " << weapon << "in your inventory" << endl;
								break;
						}
					current = current->getPrev();
					tail = tail->getPrev();
				}
				else if (temp == head) 
					{
						current = current->getNext();
						head = head->getNext();
					}
				else if (temp->getNext() != NULL)
					{
						current = current->getNext();
					}
				}

			else if (temp == head && temp == tail)
			{
				Inv.addItem(temp->getItem(), temp->getDamage(), temp->getPrice(), temp->getEquipped(), temp->getUses()); 
				if (current == tail) {
				}
				cout << temp->getItem() << endl;
				head = NULL;
				tail = NULL;
				current = NULL;
				cout << "Saved Weapon " << weapon << "in your inventory" << endl;
				break;
			}
			else if (temp == head)
			{
				Inv.addItem(temp->getItem(), temp->getDamage(), temp->getPrice(), temp->getEquipped(), temp->getUses());
				head = temp->getNext();
				head->setPrev(NULL);
			}
			else if (temp->getNext() != NULL)
			{
				Inv.addItem(temp->getItem(), temp->getDamage(), temp->getPrice(), temp->getEquipped(), temp->getUses());
				temp->getPrev()->setNext(temp->getNext());
			}
			else if (temp->getPrev() != NULL)
			{
				Inv.addItem(temp->getItem(), temp->getDamage(), temp->getPrice(), temp->getEquipped(), temp->getUses());
				temp->getPrev()->setNext(temp->getNext());
			}

			cout << "Save Weapon " << weapon << " in Inventory" << endl;

		}		
		if (weaponFound)
		{
			return weapon;
			break;
		}
		temp = temp->getNext();
	}
	delete temp;
	if (!weaponFound)
	{
		cout << "Invalid Weapon:" << weapon << endl;
		weapon = "INVALID";
		return weapon;
	} 
}
