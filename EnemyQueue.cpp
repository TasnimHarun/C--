#include "EnemyQueue.h"
#include <queue>
using namespace std; 

// Inserts an already created Enemy into the queue
void EnemyQueue::insert(enemy e) {
	eQueue.push(e); 
}

// Inserts an enemy constructor into the queue
void EnemyQueue::insert(enemy* e) {
	enemy temp; 
	temp.setName(e->getName()); 
	temp.setDMG(e->getDMG());
	temp.setHP(e->getHP());
	temp.setLVL(e->getLVL());
	temp.setMaxHP(e->getMaxHP());
	eQueue.push(temp); 
}

// Clears the Queue
void EnemyQueue::clear() {
	while (!eQueue.empty()) {
		eQueue.pop(); 
	}
}

// Returns the top enemy from the Queue
enemy EnemyQueue::top() {
	return eQueue.front();
}

// Clears the top enemy from the Queue
void EnemyQueue::slice() {
	eQueue.pop(); 
}

// Checks whether the queue is empty or not 
bool EnemyQueue::notEmpty() {
	return !(eQueue.empty()); 
}