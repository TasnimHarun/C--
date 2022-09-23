#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <stack>
#include <queue>
#include <list>
#include "FileOperations.h"
#include "Scoreboard.h"
#include "Weapon.h"
#include "WeaponsList.h"
#include "Player.h"
#include "ScoreboardList.h"
#include "EnemyQueue.h"
#include "SideQuest.h"
using namespace std;

// Function Deeclarations (Defined below main) 
void PlayerOptions(player& p, FileOperations& f, scoreboard& sb, WeaponsList& inv, WeaponsList& shop, int floor, EnemyQueue enemyQueue, ScoreboardList& sl, SideQuest SQ);
void EndGame(player& p, scoreboard& sb, FileOperations& f, WeaponsList& wl, EnemyQueue enemyQueue, ScoreboardList& sl, SideQuest SQ);
void Combat(player& p, enemy e, WeaponsList& w, int difficulty, scoreboard& sb, FileOperations& f, stack<int> log);
bool isInt(string input);
void master(ScoreboardList& sl, FileOperations& file);
void gameplay(ScoreboardList& sl, FileOperations& file);

// Main File
int main() {
	ScoreboardList sl;
	FileOperations file;

	file.Scoreboard(sl);	//opens existing scoreboard, or creates one if it doesnt exist.
	//file.ReadFile(sl);	//reads scoreboard and write into list

	master(sl, file);
	//gameplay();
}
//Function which calls the main menu with options for the player to choose from
void master(ScoreboardList& sl, FileOperations& file) {
	char input;
	cout << "Main Menu: " << endl;
	cout << "(a) Scoreboard sorted by score" << '\n'
		<< "(b) Scoreboard sorted by name" << '\n'
		<< "(c) Averaged scoreboard" << '\n'
		<< "(d) Search by name" << '\n'
		<< "(g) Heap Sort" << '\n'
		<< "(e) Enter game" << '\n'
		<< "(f) Quit" << endl;
	cin >> input;
	//loops through until the player chooses to exit
	while (input != 'f') {
		switch (input) {
		case 'a':
		{
			cout << "Sorted by score: " << endl;
			sl.SortScore();
			cout << sl;
			break;
		}
		case 'b':
		{
			cout << "Sorted by name: " << endl;
			sl.SortName();
			cout << sl;
			break;
		}
		case 'c':
		{
			cout << "Sorted by average: " << endl;
			sl.AverageScore();
			cout << sl;
			break;
		}
		case 'd':
		{
			string n;
			cout << "Enter name of player to search by: " << endl;
			cin >> n;
			sl.search(n);
			break;
		}
		case 'g':
		{
			sl.addtoVec();
			sl.HeapSort();
			break;
		}
		case 'e':
		{
			gameplay(sl, file);
			break;
		}
		default:
		{
			cout << "invalid input" << endl;
			break;
		}
		}
		cout << "Main Menu: " << endl;
		cout << "(a) Scoreboard sorted by score" << '\n'
			<< "(b) Scoreboard sorted by name" << '\n'
			<< "(c) Averaged scoreboard" << '\n'
			<< "(d) Search by name" << '\n'
			<< "(g) Heap Sort" << '\n'
			<< "(e) Enter game" << '\n'
			<< "(f) Quit" << endl;
		cin >> input;
	}
	sl.clear();
	cout << "Thank you for playing" << endl;
	exit(1);
}
//Function which runs the actual game
void gameplay(ScoreboardList& sl, FileOperations& file) {
	//Player starting part, opening and closing files
	string diff;
	string choice;
	string filename;
	string name;
	string decision1;
	char c;
	enemy e;
	//FileOperations file;
	player p1("name", 150, 150, 10, 0);	//creates a player with full health and attack damage
	p1.setMoney(10);
	scoreboard sb("name", 0);	//sets initial score to 0
	//ScoreboardList sl;
	Weapon w;
	WeaponsList Inv;
	WeaponsList shopList;
	int difficulty = 0;
	int floor;
	int enemyID = 0;
	bool nextFloor = false;
	srand(time(NULL));
	SideQuest SQ;
	stack<int> combatLog;
	EnemyQueue enemyQueue;
	

	int index = 0;
	cout << "Do you have an existing Player file?" << endl;
	cout << setw(10) << left << "[Y]es" << setw(10) << "[N]o" << endl;
	cin >> decision1;
	c = decision1[0];

	// Decides whether a new file is created or a previous one is read
	if (c == 'N' || c == 'n') {
		Inv.addItem("Dagger", 4, 0, 1, -1);
		cout << "Creating new save file ";
		cout << "\nWhat would you like to name the new player file?" << endl;
		cin >> filename;
		while (filename._Equal("scoreboard")) {
			cout << "Invalid save name. Try again." << endl;
			cin >> filename;
		}
		file.Player(filename);
		cout << "Success in creating new file" << endl;
		cout << "What is your name?" << endl;
		cin >> name;
		p1.setName(name);
		sb.setName(name);
		floor = 1;
		sb.setFloor(floor);	//game starts at floor 1 for new player
		cout << "Choose a difficulty from the options below: " << endl;
		while (difficulty == 0) {
			cout << setw(10) << left << "[E]asy" << setw(12) << "[M]edium" << setw(10) << "[H]ard" << endl;
			cin >> choice;
			c = choice[0];

			// Allows the player to choose a difficulty option 
			switch (toupper(c)) {
			case 'E':
				cout << "You have chosen the Easy difficulty." << endl;
				difficulty = 1;
				sb.setDifficultyMod(1);
				diff = "Easy";
				sb.setDifficulty(diff);
				break;
			case 'M':
				cout << "You have chosen the Medium difficulty." << endl;
				difficulty = 2;
				sb.setDifficultyMod(2);
				diff = "Medium";
				sb.setDifficulty(diff);
				p1.ModifyHealth(-100);
				p1.setMaxHP(p1.getMaxHP() + 100);
				break;
			case 'H':
				cout << "You have chosen the Hard difficulty. " << endl;
				difficulty = 3;
				sb.setDifficultyMod(3);
				diff = "Hard";
				sb.setDifficulty(diff);
				p1.ModifyHealth(-200);
				p1.setMaxHP(p1.getMaxHP() + 200);
				break;
			default:
				cout << "Invalid input. Please select from the difficulty options." << endl;
				break;
			}
		}


	}
	else if (c == 'Y' || c == 'y')
	{
		cout << "What is the name of the existing file?" << endl;
		cin >> filename;
		file.ChooseFile(sb, p1, filename, Inv); //check here

	}
	else {
		cout << "Invalid input" << endl;
		exit(1);
	}

	sb.setDifficulty(diff);
	//Player ending part of choosing files and making new files

	// Addition of Enemies to the enemy queue - Name, MaxHP, HP, Damage, Level
	EnemyQueue eQueue;
	enemy eTemp;
	eQueue.insert(new enemy("Angry Chair", 10, 10, 10, difficulty));
	eQueue.insert(new enemy("Angry Table", 10, 10, 10, 1 + difficulty));
	eQueue.insert(new enemy("Haunted Mic", 25, 25, 7, 2 + difficulty));
	eQueue.insert(new enemy("Haunted Lecturn", 30, 30, 7, 3 + difficulty));
	eQueue.insert(new enemy("Horrified Seawolf", 50, 50, 9, 4 + difficulty));
	eQueue.insert(new enemy("Werewolfie", 50, 50, 9, 5 + difficulty));
	eQueue.insert(new enemy("Corrupted TA David", 175, 175, 30, difficulty));

	// End of initlization of Enemies
	//file.Scoreboard();	//checks for existing scoreboard or else creates one


	//// Game Intro
	Sleep(300);
	cout << " _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
	Sleep(300);
	cout << "|          The Legend of          |" << endl;
	Sleep(300);
	cout << "|               David             |" << endl;
	Sleep(300);
	cout << " _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
	Sleep(300);

	// Checks whether to play the player intro or not
	floor = sb.getFloor();
	int temp = floor;
	if (floor == 1) {
		cout << "\nYou rush into the Melville Library, late to submit your ESE 224 Final Project." << endl;
		cout << "You get an ominous feeling as you enter the elevator. Fog starts to take over the ground floor as the doors close." << endl;
		cout << "Wait why are all the buttons lit up?" << endl;
	}
	if (temp > 1) {
		cout << "Floor: " << temp << endl;
		for (int i = 0; i < 2 * (temp - 1); i++) {
			eQueue.slice();
		}
	}

	// Loops if the player is below Floor 4 and is ALIVE
	while (floor < 4 && p1.getHP() > 0) {
		// Sets up Shop loop and lets the player know what floor they are on.
		nextFloor = false;
		SQ.printSideQuest(p1, sb);
		cout << "The elevator breaks down and you enter Floor " << floor << endl;

		// Shows the paths the player can take and allows for player input
		PlayerOptions(p1, file, sb, Inv, shopList, floor, enemyQueue, sl, SQ);
		cout << "You see two paths:" << endl;
		cout << setw(10) << left << "[L]eft" << setw(10) << "[R]ight" << endl;
		cin >> choice;
		char c = choice[0];
		switch (toupper(c)) {
		case 'L':  //Left
			cout << "You have chosen the Left path." << endl;

			// Determines enemy from enemyList and prints out their name.
			eTemp = eQueue.top();
			cout << "\nYou have encountered a " << eTemp.getName() << endl;

			// Initiates Combat with the enemy. Saves after combat ends, whether by victory or defeat
			Combat(p1, eTemp, Inv, difficulty, sb, file, combatLog);
			if (p1.getHP() > 0) {
				enemyQueue.insert(eTemp);
				eQueue.slice();
				eQueue.slice();
			}

			break;

		case 'R': // Right
			cout << "You have chosen the Right path." << endl;

			// Determines enemy from enemyList and prints out their name. Can be reduced to function
			eQueue.slice();
			eTemp = eQueue.top();
			cout << "\nYou have encountered a " << eTemp.getName() << "!" << endl;

			// Initiates Combat with the enemy. Saves after combat ends, whether by victory or defeat
			Combat(p1, eTemp, Inv, difficulty, sb, file, combatLog);
			if (p1.getHP() > 0) {
				enemyQueue.insert(eTemp);
				eQueue.slice();
			}

			break;

		default: // Invalid Input - Sets floor back to avoid skipping floors
			cout << "Invalid input. Please try again." << endl;

			break;
		}

		// Ensures that the player finished one of the paths
		if (toupper(c) == 'L' || toupper(c) == 'R') {
			int input = 0;
			// Determines if the player has survived
			if (p1.getHP() > 0) {
				// Allows the option for an upgrade to the player stats
				cout << "\nYou have completed the floor and found a chest at the end! Which of these upgrades will you take? " << endl;
				cout << "1)  Potion: Raises Max Health and Health by 50" << endl;
				cout << "2)  Attack Charm: Raises your Critical Attack chance by 20%" << endl;
				

				// Checks for correct input. Updates specific stat for each input
				while (input != 49 && input != 50) {
					cin >> choice;
					c = choice[0];
					if (isdigit(c)) {
						input = c;
					}
					switch (input) {
					case 49: // Input "1": Increases HP and MaxHP by 50
						p1.setMaxHP(p1.getMaxHP() + 50);
						p1.setHP(p1.getHP() + 50);
						file.Save2File(p1, sb, shopList);
						break;

					case 50: //Input "2": Increases Critical Hit chance by 20%
						p1.setDMG(p1.getDMG() + 20);
						file.Save2File(p1, sb, shopList);
						break;

					default:
						cout << "Invalid input. Try again." << endl;
						break;
					}
				}
			}
			SQ.sideQuestChecker(p1, sb, Inv);
			floor++;
			sb.setFloor(floor);

			// Story
			if (p1.getHP() > 0) {
				cout << endl;
				cout << "The elevator creaks back to life and you take it to the next floor." << endl;
			}
		}
	}

	// Checks if the player is still alive and has finished the first 3 floors.
	if (floor == 4 && p1.getHP() > 0) {
		
		SQ.printSideQuest(p1,sb);
		// Story
		PlayerOptions(p1, file, sb, Inv, shopList, floor, enemyQueue, sl, SQ);
		cout << "Finally you reached the 4th Floor. As you enter Room 4550, you see TA David... but he looks... different..." << endl;
		cout << "\"I can't stop him! It's up to you, " << p1.getName() << "!\" The professor exclaims in terror." << endl;
		cout << "Corrupted TA David approaches you for battle! " << endl;


		// Boss strikes first to add difficulty
		eTemp = eQueue.top();
		enemyID = eTemp.getDMG(); // Sets damage to the enemys AttackDamage stat
		for (int i = 0; i < difficulty - 1; i++) { // Loops depending on difficulty, allowing for more chances of damage increase
			enemyID = eTemp.getAttack(enemyID);
		}

		// Modifies player HP and prints out the interaction
		p1.ModifyHealth(enemyID);
		combatLog.push(p1.getHP());
		cout << "Corrupt TA David inflicted " << enemyID << " damage." << endl;

		// Determines whether the boss has defeated you or to continue another round of combat
		if (p1.getHP() <= 0) {
			cout << "The corrupted TA David has defeated you.";
			if (p1.getHP() <= 0) {
				cout << "G ";
				Sleep(200);
				cout << "A ";
				Sleep(200);
				cout << "M ";
				Sleep(200);
				cout << "E ";
				Sleep(200);
				cout << "O ";
				Sleep(200);
				cout << "V ";
				Sleep(200);
				cout << "E ";
				Sleep(200);
				cout << "R " << endl;
				sb.setFloor(floor);
				EndGame(p1, sb, file, shopList, enemyQueue, sl, SQ);
			}

		}

		// Loops the Combat sequence
		else {
			Combat(p1, eTemp, Inv, difficulty, sb, file, combatLog);

			// Plays victory text if the player wins 
			if (p1.getHP() > 0) {
				cout << "A gleam of light overtakes the room. As it fades, TA David wakes up." << endl;
				cout << "\"Thank you for saving me " << p1.getName() << "\" He says" << endl;
				cout << "Overtaken by emotion, TA David slowly approaches you..." << endl;
				cout << "\"You get a 100 for the Final\" and he runs away, never to be seen again..." << endl;
				EndGame(p1, sb, file, shopList, enemyQueue, sl, SQ);

			}
		}
	}

	// Determines if the player lost all their HP
	if (p1.getHP() <= 0) {
		cout << "\nG ";
		Sleep(200);
		cout << "A ";
		Sleep(200);
		cout << "M ";
		Sleep(200);
		cout << "E ";
		Sleep(200);
		cout << "O ";
		Sleep(200);
		cout << "V ";
		Sleep(200);
		cout << "E ";
		Sleep(200);
		cout << "R " << endl;
		sb.setFloor(floor);
		EndGame(p1, sb, file, shopList, enemyQueue, sl, SQ);
	}
}

void Combat(player& p, enemy e, WeaponsList& wl, int difficulty, scoreboard& sb, FileOperations& f, stack<int> log) {
	// Declaration of variables
	int ehp;
	string input;
	string sin;
	int in;
	char c;
	int damage;
	bool weaponCheck = false;
	srand(time(0));
	time_t t;

	// Prompts the user to make a choice during combat. Reads this choice
	cout << "What would you like to do? " << endl;
	cout << setw(14) << left << "[A]ttack" << setw(20) << "Examine [S]elf" << setw(20) << "Examine [E]nemy" << endl;
	cin >> input;
	c = input[0]; // Determines the first letter of the choice

	switch (toupper(c)) {
	case 'A': // [A]ttack - runs Combat() until either the player or enemy HP drop to 0
		// Prints equipped weapons and prompts the player to choose a weapon to use
		cout << "\nSelect your weapon: " << endl;
		wl.printAllL();
		while (!weaponCheck) {
			cin >> sin;
			if (isInt(sin)) {
				in = stoi(sin) - 1;
				if (in < 7 && in >= 0) {
					if (wl.getWeapon(in).getEquipped() != 0) {
						weaponCheck = true;
					}
					else {
						cout << "Please select a valid weapon number" << endl;
					}
				}
				else {
					cout << "Please select a valid weapon number" << endl;
				}
			}
			else {
				cout << "Please select a valid weapon number" << endl;
			}
		}

		// Prints out your weapon interaction with the enemy. Alters Enemy HP and Weapon Uses
		damage = wl.getWeapon(in).getDamage() * p.getCritical(p.getDMG());
		//Sleep(300);
		//for (int i = 0; i < 3; i++) {
		//	cout << ". ";
		//	Sleep(300);
		//}
		cout << "\nYour " << wl.getWeapon(in).getItem() << " inflicted " << damage << " damage on the " << e.getName() << endl;
		e.ModifyHealth(damage);
		if (e.getHP() < 0) {
			log.push(0);
		}
		else {
			log.push(e.getHP());
		}
		wl.getWeapon(in).setUses(wl.getWeapon(in).getUses() - 1);

		//Checks if Weapon is out of Uses
		if (wl.getWeapon(in).getUses() == 0) {
			wl.getWeapon(in).setEquipped(0);
		}

		// Determines if the enemy is defeated or if the enemy attacks
		if (e.getHP() <= 0) {
			if (e.getName().compare("Corrupted TA David") == 0) {
				cout << "You have defeated Courrupted TA David. He drops 224 coins and a card with 3 funky numbers on the back." << endl;
				cout << "Combat Log: " << endl;
				int turn = log.size();
				while (!log.empty()) {
					if (turn % 2 == 0) {
						cout << "Turn " << turn << " - Boss HP: " << log.top() << endl;
						log.pop();
					}
					else {
						if (turn % 2 != 0) {
							cout << "Turn " << turn << " - Player HP: " << log.top() << endl;
							log.pop();
						}
					}
					turn--;
				}
			}
			else {
				p.ModifyMoney(e.getMoney());
				sb.setScore(sb.getScore() + (10 * e.getLVL()));
				if (e.getHP() < 0) {
					e.setHP(0);
				}
				cout << "You have defeated the " << e.getName() << ". The " << e.getName() << " dropped " << e.getMoney() << " coins." << endl;
				cout << "Combat Log:" << endl;
				int turn = log.size();
				while (!log.empty()) {
					if (turn % 2 == 0) {
						cout << "Turn " << turn << " - Player HP: " << log.top() << endl;
						log.pop();
					}
					else {
						if (turn % 2 != 0) {
							cout << "Turn " << turn << " - Enemy HP: " << log.top() << endl;
							log.pop();
						}
					}
					turn--;
				}
			}
		}

		else { // Enemy Damages the player

			damage = e.getDMG(); // Sets damage to the enemys AttackDamage stat
			for (int i = 0; i < e.getLVL(); i++) { // Loops depending on difficulty, allowing for more chances of damage increase
				damage = e.getAttack(damage);
			}

			// Modifies player HP and prints out the interaction
			p.ModifyHealth(damage);
			cout << "The " << e.getName() << " strikes! " << "The " << e.getName() << " inflicted " << damage << " damage." << endl;
			log.push(p.getHP());
		}
		break;

	case 'S': // Examine [S]elf - prints out player stats
		cout << p.getName() << " Stats: " << endl;
		cout << "-> Health: " << p.getHP() << " / " << p.getMaxHP() << endl;
		cout << "-> Crit (x2) Chance: " << p.getDMG() << "%" << endl;
		cout << "-> Money: " << p.getMoney() << "\n" << endl;
		break;

	case 'E': // Examine [Enemy] - prints out enemy stats
		cout << e.getName() << " Stats: " << endl;
		cout << "-> Health: " << e.getHP() << " / " << e.getMaxHP() << endl;
		cout << "-> Average Attack: " << e.getDMG() << endl;
		cout << "-> Level: " << e.getLVL() << endl;
		break;

	default: // Invalid input
		cout << "\nInvalid input. Please try again." << endl;
		break;
	}

	// Determines if another turn of combat is necessary. Proceeds if so
	if (p.getHP() > 0 && e.getHP() > 0) {
		// If difficulty is Medium or greater, the enemy has a chance to regain 20% of their HP
		if (e.getHP() < e.getMaxHP() && difficulty > 1) {
			int chance = rand() % 100 + 1;
			if (chance + ((difficulty - 1) * 10) > 75) {
				// Checks whether the added 20% HP exceeds the maxmimum HP and corrects the value if so 
				cout << "The " << e.getName() << " has regained 20% of their maximum health!" << endl;
				in = e.getHP() + (e.getMaxHP() / 5) > e.getMaxHP() ? e.getMaxHP() : e.getHP() + (e.getMaxHP() / 5);
				e.setHP(in);
			}
		}

		// Repeats the combat loop
		cout << "\n~ ~ ~ Next Turn ~ ~ ~" << endl;
		Combat(p, e, wl, difficulty, sb, f, log);
	}
	// Determines if the player has been defeated
	else if (p.getHP() <= 0) {
		cout << "You have been deafeated by the " << e.getName() << endl;
	}
}

//function which gives player a list of options to choose from
void PlayerOptions(player& p, FileOperations& f, scoreboard& sb, WeaponsList& inv, WeaponsList& shop, int floor, EnemyQueue enemyQueue, ScoreboardList& sl, SideQuest SQ)
{
	bool check = false;
	stack <string> ST;
	char input;
	char option;
	bool inShop = false;
	cout << "Pick an option from the menu: " << endl;
	cout << "[E]xamine Self, [C]ontinue, [S]coreboard, S[H]op, [R]eturn: " << endl;
	cin >> input;

	// Checks Player input 
	switch (toupper(input)) {
		//Examine Self
	case 'E':
		cout << p.getName() << " Stats: " << endl;
		cout << "-> Health: " << p.getHP() << " / " << p.getMaxHP() << endl;
		cout << "-> Crit (x2) Chance: " << p.getDMG() << "%" << endl;
		cout << "-> Money: $" << p.getMoney() << endl;
		cout << "\n";
		PlayerOptions(p, f, sb, inv, shop, floor, enemyQueue, sl, SQ);		//calls the function again so it loops
		break;

		// Continue
	case'C':
		break;

		// Scoreboard
	case'S':
		sb.SB_out();
		PlayerOptions(p, f, sb, inv, shop, floor, enemyQueue, sl, SQ);
		cout << "\n";
		break;

		//Shop
	case 'H':
		inShop = true;
		check = false;
		while (inShop) {
			shop.clear();
			shop.loadAll(sb, p);
			cout << setw(25) << "Print [I]nventory" << setw(25) << "[S]hop" << setw(25) << "[E]xit the Shop" << endl;
			cin >> option;
			string buyW;
			switch (tolower(option))
			{
				//Inventory 
			case 'i':
				inv.printAllL();
				break;
			case 's':

				//Shop
				cout << "\nShop selected" << endl;
				cout << "You have: $" << p.getMoney() << endl;
				cout << "\nShopList:" << endl;
				shop.printAll();
				cout << endl;
				cout << "Select a weapon: " << endl;
				cin >> buyW;


				check = shop.search(shop.getHead(), buyW);
				cout << check << endl;


				//Loops until a proper weapon is selected 
				if (check) {
					if (p.getMoney() < inv.getWeapon(buyW).getPrice() || p.getMoney() < 0) {
						cout << "You do not have enough money to buy this weapon." << endl;
					}
					else if (inv.getWeapon(buyW).getEquipped() == 1) {
						cout << "You already own this weapon, please buy a new weapon" << endl;
					}
					else {
						ST.push(shop.buyWeapon(buyW, inv));

						p.ModifyMoney(inv.getWeapon(buyW).getPrice() * -1);
						cout << "You now own a " << inv.getWeapon(buyW).getItem() << " which costs $" <<
							inv.getWeapon(buyW).getPrice() << " Your remaining money: $" << p.getMoney() << endl;
						inv.getWeapon(buyW).setEquipped(1);
						cout << "\n";
					}
				}

				else {
					cout << "Invalid Weapon. Try Again." << endl;
				}
				shop.clear();
				break;

				// Exit the Shop 
			case 'e':
				cout << "Recently Bought Weapons: " << endl;
				while (!ST.empty()) {
					cout << ST.top() << endl;
					ST.pop();
				}
				inShop = false;
				break;

			default:
				cout << "Invalid option" << endl;
			}
		}

		PlayerOptions(p, f, sb, inv, shop, floor, enemyQueue, sl, SQ);
		break;

		// Return
	case'R':
		EndGame(p, sb, f, inv, enemyQueue, sl, SQ);	//function when game ends
		sl.insertSort(new scoreboard(sb.getName(), sb.getScore()));
		master(sl, f);
		break;
	default:
		cout << "Invalid input" << endl;
		PlayerOptions(p, f, sb, inv, shop, floor, enemyQueue, sl, SQ);
		break;
	}
}
//function to call when ending game
void EndGame(player& p, scoreboard& sb, FileOperations& f, WeaponsList& wl, EnemyQueue enemyQueue, ScoreboardList& sl, SideQuest SQ) {

	SQ.sideQuestChecker(p, sb, wl);
	SQ.addSideQuest();
	SQ.printQueue();

	f.Save2File(p, sb, wl);	//saves into player file
	f.Save2File(sb);	//saves into scoreboard.txt
	sb.SB_out();	//displays current players score difficulty and name
	cout << enemyQueue;
	f.CloseFile();
}

// Determines if a string is comprised of soley digits or not
bool isInt(string input) {
	for (char& c : input) {
		if (!isdigit(c)) {
			return false;
		}
	}
	return true;
}