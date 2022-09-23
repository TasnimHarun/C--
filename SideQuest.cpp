#pragma once
#include "SideQuest.h"
#include "Scoreboard.h"
#include <stdlib.h>
#include <time.h>
#include "Player.h"
#include "Weapon.h"
#include "WeaponsList.h"

bool SideQuest::getS1()
{
	return s1;
}
void SideQuest::setS1( bool sone)
{
	s1 = sone;
}

bool SideQuest::getS2()
{
	return s2;
}
void SideQuest::setS2(bool stwo)
{
	s2 = stwo;
}

bool SideQuest::getS3()
{
	return s3;
}
void SideQuest::setS3( bool sthree)
{
	s3 = sthree;
}

bool SideQuest::getS4()
{
	return s4;
}
void SideQuest::setS4(bool sfour)
{
	s4 = sfour;
}

int SideQuest::getBeginM()
{
	return beginM;
}
void SideQuest::setBeginM(int money)
{
	beginM = money;
}
int SideQuest::getEndM()
{
	return endM;
}
void SideQuest::setEndM(int money)
{
	endM = money;
}


void SideQuest:: printSideQuest(player p, scoreboard SB)
{
	cout << "\nAs you get out of the elevator, you look at map nearby, and see the side quest posted for floor # " << SB.getFloor() << endl;
	switch (SB.getFloor())
	{
	case 1:
		cout << "End the floor with the weapon dagger only in your inventory" << endl;
		break;

	case 2:
		cout << "Save more than 20 coins from the beginning to end of this floor" << endl;
		beginM = p.getMoney();
		break;

	case 3:
		cout << "End the floor with less money than you started " << endl;
		cout << "Your current amount of money : $ " << p.getMoney() << endl;
		beginM = p.getMoney();
		break;

	case 4:
		cout << "End the battle with more than 150 health" << endl;
		break;

	default :
		cout << "No Side Quests" << endl;
		break;
	}

}
bool SideQuest::sideQuestChecker(player p, scoreboard SB, WeaponsList Inv)
{	// add if statements before return to say if completed
	//DONT FORGET TO ADD AND CHECK BALANCE
	switch (SB.getFloor())
	{
	case 1:
		cout << "Side Quest Completed?: End the floor with the weapon dagger only in your inventory " << endl;
		if (Inv.getWeaponsL().size() == 1)
		{
			setS1(true);
			cout << getS1() << endl;
			p.ModifyMoney(50);
			cout << "Side Quest Completed!" << endl;
		}
		else
		{
			setS1(false);
			cout << getS1() << endl;
			cout << "Side Quest Not Completed :(" << endl;
		}
		return s1;

		break;

	case 2:
		cout << "Side Quest Completed?:  Save 20 or more coins from the beginning to end of this floor" << endl;
		endM = p.getMoney(); 
		if (endM - beginM >= 20)
		{
			setS2(true);
			p.ModifyMoney(50);
			cout << "Side Quest Completed!" << endl;
		}
		else {
			setS2(false);
			cout << "Side Quest Not Completed :(" << endl;
		}
		
		return s2;
		break;

	case 3:
		cout << "Side Quest Completed?: End the floor with less money than you started " << endl;
		endM = p.getMoney();
		if (endM - beginM < 0)
		{
			setS3(true);
			p.ModifyMoney(50);
			cout << "Side Quest Completed!" << endl;
		}
		else {
			setS3(false);
			cout << "Side Quest Not Completed :(" << endl;
		}

		return s3;
		break;

	case 4:
		cout << "Completed? : End the battle with more than 50 health" << endl;
		if (p.getHP() > 50) {
			setS4(true);
			p.ModifyMoney(50);
		}
		else
		{
			setS4(false);
		}
		return s4;
		break;

	default:
		cout << "No Side Quests" << endl;
		return false;
		break;
		

	}



} // we need SB to check the floor
void SideQuest::addSideQuest()
{
	//may need a flag lol or we just call this function at the end
	if (getS1())
	{
		cout << "S1" << endl;
		SQstring.push("Floor 1: End the floor with the weapon dagger only in your inventory");
	}
	if (getS2())
	{
		cout << "S2" << endl;
		SQstring.push("Floor 2: Save 20 coins or more from the beggining to end of the floor");
	}
	if (getS3())
	{
		cout << "S3" << endl;
		SQstring.push("Floor 3: End the floor with less money than you started ");
	}
	if (getS4())
	{
		cout << "S4" << endl;
		SQstring.push("Floor 4: Ended battle with more than 50 health  ");
	}

}
void SideQuest:: printQueue()
{
	cout << "Printing out all completed Side Quests" << endl;
	while (!SQstring.empty())
	{
		cout << SQstring.front() << "\n";
		SQstring.pop();
	}
	cout << endl;

}
