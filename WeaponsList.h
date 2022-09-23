#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Weapon.h"
#include "scoreboard.h"
#include "Player.h"
#include "ShopTracker.h"
using namespace std;
/*
template <class T>

T larger(T Weapon1, T Weapons2) {
	return (Weapons1 > Weapons2 ? Weapon1 : Weapon2);
}*/
class WeaponsList
{
private:
	vector<Weapon> WeaponsL;
	typedef Weapon* WeaponPtr;
	WeaponPtr head, tail, current;
	


public:
	bool flag = true;
	int currentLength;
	WeaponsList();
	~WeaponsList();
	vector <Weapon> getWeaponsL();
	//void printEquipped();
	void addItem(Weapon weapon);
	void addItem(string i, int d, double price, bool equipped, int uses);
	void deleteItem(string item);
	Weapon& getWeapon(string name);
	Weapon& getWeapon(int i); 

	void addWeapon(Weapon* weapon);
	bool search(Weapon* head, string w);

	void moveToNext();
	void moveToPrev();
	void moveToHead();
	void moveToTail();
	void printAll();
	void loadAll(scoreboard sb, player p);
	void setTail(Weapon* tail);
	string buyWeapon(string weapon, WeaponsList& Inv);
	Weapon* getCurrent();
	void clear();
	void printAllL();

	WeaponPtr getHead() {
		return head; 
	}
	//get old functuon 


};
