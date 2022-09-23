#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <list>
#include "Scoreboard.h"

using namespace std;

class ScoreboardList {
private:
	//creates a vector of scoreboards
	vector<scoreboard> scoreboardList;
	//creates a list of scoreboards
	list<scoreboard*> scoreboardLink;
	// an iterator to help go through the list
	list<scoreboard*>::iterator it;
public:
	//Constructor for ScoreboardList
	ScoreboardList();
	//Function that adds a scoreboard item to the vector
	void addItem(string name, int score);
	//Function that adds a scoreboard item to the list
	void insert(scoreboard* scoreboard);
	//Function which allows access to the vector of scoreboards
	vector <scoreboard> getScoreboardL();
	//Function which adds elements from the list to the vector
	void addtoVec();
	//Function used to create a heap from the vector
	void Heapify(vector<scoreboard>& vec, int n, int root);
	//Function used to sort the heap
	void HeapSort();

	//Function which returns the List
	list<scoreboard*>getScoreboardList();
	//Function which searches and outputs all the items with the given name
	void search(string name);
	//Function which clears the list
	void clear();
	//Function which creates a list of scoreboards with the average for all those with the same name
	void AverageScore();
	//Function which returns the scoreboard in the vector at index i
	scoreboard getScoreboard(int i);
	//Function which adds an element into a sorted list
	void insertSort(scoreboard* scoreboard);
	//Function which sorts the list by score from highest to lowest
	void SortScore();
	//Function which sorts the list by names
	void SortName();
	//Operator overload which makes it easier to output every element in the list
	friend ostream& operator <<(ostream& os, const ScoreboardList& sl)
	{
		//scoreboard i;
		for (const auto& i : sl.scoreboardLink) os << i->getName() << " " << i->getScore() << endl;
		return os;
	}
};