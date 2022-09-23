#pragma once
#include <stdlib.h>
#include <time.h>
#include "Player.h"
#include "Scoreboard.h"
#include <queue>
#include "Weapon.h"
#include "WeaponsList.h"
class SideQuest {


private:
	//floor one
	bool s1=false;

	//floor two
	bool s2= false;
	int beginM=0, endM=0;
	//floor three
	bool s3= false;

	//floor four
	bool s4= false; 

	queue<string> SQstring;




public:
	// dont forget setter and getter methods

	bool getS1();
	void setS1(bool sone);

	bool getS2();
	void setS2( bool stwo);
	int getBeginM();
	void setBeginM(int money);
	int getEndM();
	void setEndM(int money);

	bool getS3();
	void setS3( bool sthree);

	bool getS4();
	void setS4( bool sfour);


	void printSideQuest(player p, scoreboard SB); 
	bool sideQuestChecker(player p, scoreboard SB, WeaponsList Inv); // we need SB to check the floor
	void addSideQuest();
	void printQueue();
};





/*
function to print introduce Side quest
switch case floor
prints out the side quest
*/





/*
Function to check if side question completed
return boolean
switch case floor
 
 check condition is met, set s# to true;

*/

/*Add side quest to queue, side quest is does not have to be an object, can be queue of strings*/

/*print all side quests*/
