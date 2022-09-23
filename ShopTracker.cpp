#include <stack>
#include <iostream>
#include <list>
#include "ShopTracker.h"


ShopTracker::ShopTracker()
{
}
void ShopTracker::insert(string w)
{
	WeaponStack.push(w);
	cout << "Insert" << w << endl;
}
void ShopTracker::print()
{
	stack <string> temp;
	temp = WeaponStack;
	if (WeaponStack.empty()) 
	{
		cout << "Stack is Empty" << endl;
	}
	else {
		cout << "\nShop Receipt" << endl;
		while (!temp.empty())
		{
			temp.pop();\
			//not print
		}
	}
}



void ShopTracker::clear()
{
	while (!WeaponStack.empty())
	{
		WeaponStack.pop();
	}
}


