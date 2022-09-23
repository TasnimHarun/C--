#include <iostream>
#include <queue>
#include "Player.h"
#include <iomanip>

using namespace std; 

// Enemy Queue for the Enemies encountered throughout the game
class EnemyQueue {
private: 
	//Creates a queue
	queue<enemy> eQueue;

public:
	// Enemy Inserters
	void insert(enemy* e);
	void insert(enemy e); 

	// Clear Function
	void clear();

	// Pop Function
	void slice();

	// Top Function
	enemy top(); 

	// isClear
	bool notEmpty(); 


	// Overloads the << operator to print out the stack 
	friend ostream& operator << (ostream& output, EnemyQueue e) {
		output << "~ ~ ~ Enemies Defeated in this Playthrough ~ ~ ~ " << endl;
		while (e.notEmpty()) {
			output << "Name: " << setw(20) << e.top().getName() << " Level: " << e.top().getLVL() << endl;
			e.slice();
		}
		return output;
	}




};

