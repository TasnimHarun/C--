#pragma once
#include <stack>
#include <iostream>
#include "Weapon.h"


#include <list>
#include <stack>

class ShopTracker {

private:
	

public:
	stack <string> WeaponStack;
	ShopTracker();
	void insert(string w);
	void print();
	void clear();
	

};
