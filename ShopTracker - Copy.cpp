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




/*
top
pop
push
is empty
size
swap
*/


/*

~stack() {}



*/
/*
insert ()
{

stack.push(weapon);

}
*/

/*
*
* print {
while (!stack.empty){
cout << stack.pop() << endl;


}

}


for (int i = top; i>=0; i--){
	cout stack[i] << \t << endl;
}
*/

/*

Weapon* temp = new Weapon();
	while (head != NULL)
	{
		temp = head;
		head = head->getNext();
		free(temp);

	}
	cout << "All nodes are deleted successfully.\n";



*/