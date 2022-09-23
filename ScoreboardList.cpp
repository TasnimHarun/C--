//array to add and delete in the scoreboard
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <list>
#include <vector>
#include "ScoreboardList.h"

using namespace std;

//Emtpy constructor
ScoreboardList::ScoreboardList() {
}

//Function which adds a scoreboard variable to the vector ScoreboardList
void ScoreboardList::addItem(string name, int score)
{
	scoreboardList.push_back(scoreboard(name, score));
}
//Function which adds a scoreboard variable to the list scoreboardLink
void ScoreboardList::insert(scoreboard* scoreboard) {
	scoreboardLink.push_back(scoreboard);
}
//Sorts the list by name is the list is not already empty
void ScoreboardList::SortName() {
	if (scoreboardLink.empty()) {
		cout << "Scoreboard is empty" << endl;
	}
	else {
		scoreboardLink.sort([](scoreboard* lhs, scoreboard* rhs) {
			return lhs->getName() < rhs->getName(); });
	}
}
//Sorts the list by score if the list not already empty
void ScoreboardList::SortScore() {
	if (scoreboardLink.empty()) {
		cout << "Scoreboard is empty" << endl;
	}
	else {
		scoreboardLink.sort([](scoreboard* lhs, scoreboard* rhs) {
			return lhs->getScore() > rhs->getScore(); });
	}
}
//This function recursively creates a heap from the given vector with the given size and root
void ScoreboardList::Heapify(vector<scoreboard>& vec, int n, int root) {
	int largest = root;
	int l = 2 * root + 1;
	int r = 2 * root + 2;
	if (l<n && vec[l].getScore() > vec[largest].getScore()) {
		largest = l;
	}
	if (r<n && vec[r].getScore() > vec[largest].getScore()) {
		largest = r;
	}
	if (largest != root) {
		//swap root and largest
		scoreboard temp = vec[root];
		vec[root] = vec[largest];
		vec[largest] = temp;
		//recursively call
		Heapify(vec, n, largest);
	}
}
//Function which creates a heap from the scoreboardList and sorts it
void ScoreboardList::HeapSort() {
	vector<scoreboard> vec = scoreboardList;
	int n = scoreboardList.size();
	for (int i = n / 2 - 1; i >= 0; i--) {
		Heapify(vec, n, i);
	}
	for (int i = n - 1; i >= 0; i--) {
		scoreboard temp = vec[0];
		vec[0] = vec[i];
		vec[i] = temp;
		Heapify(vec, i, 0);
	}
	for (int i = vec.size(); i >= 0; i--) {
		cout << vec[i] << " ";
	}
	cout << endl;
}
//Function which adds an element into a sorted list
void ScoreboardList::insertSort(scoreboard* s) {
	if (scoreboardLink.empty()) {
		scoreboardLink.push_back(s);
	}
	else {
		SortScore();	//sorts the list
		list<scoreboard*> temp;
		bool flag = true;	//flag which checks if the item has been added already
		int score = s->getScore();
		while (!scoreboardLink.empty())
		{
			if (flag) {
				if (score > scoreboardLink.front()->getScore()) {
					temp.push_back(s);
					flag = false;
				}
			}
			temp.push_back(scoreboardLink.front());	//this is to iterate through every element in the list
			scoreboardLink.pop_front();
		}
		if (flag) {	//if the given score is smaller than all the elements in the list than it adds it to the end
			temp.push_back(s);
			flag = false;
		}
		while (!temp.empty()) {
			scoreboardLink.push_back(temp.front());		//puts all values back in the list
			temp.pop_front();
		}
	}
}

//Function which returns the list of scoreboards
vector <scoreboard> ScoreboardList::getScoreboardL()
{
	return scoreboardList;
}
//Function which adds all elements in the list to the vector for it be heapified
void ScoreboardList::addtoVec() {
	scoreboardList.clear();		//prevents duplicate scoreboard objects from being added to the vector
	string name;
	int score;
	for (const auto i : scoreboardLink) {
		addItem(i->getName(), i->getScore()); //goes through every item in the list and adds it to the vector
	}
}
//Function which creates a list with the objects with the same name averaged
void ScoreboardList::AverageScore()
{
	if (scoreboardLink.empty()) {
		cout << "Scoreboard is empty" << endl;
	}
	else {
		SortName();	//first sorts the list by name so every item with the same list is next to each other
		list<scoreboard*> average;		//list which will hold the new items
		int sum = 0;
		int count = 0;
		int avg;
		scoreboard* temp = scoreboardLink.front();	//holds the first element in the list
		scoreboardLink.pop_front();	//allows access to the second element in the list
		while (!scoreboardLink.empty()) {
			if (scoreboardLink.front()->getName()._Equal(temp->getName())) {
				sum += temp->getScore();
				count++;
			}
			else {
				if (sum == 0) {	//if sum == 0, there is no duplicate of this name
					average.push_back(temp);
				}
				else {	//there was a duplicate and finds the average score and adds to the new list
					sum += temp->getScore();
					count++;
					avg = sum / count;
					temp->setScore(avg);
					average.push_back(temp);
					sum = 0;
					count = 0;
				}
			}
			temp = scoreboardLink.front();	//accesses the next item in the list
			scoreboardLink.pop_front();
		}
		average.push_back(temp);

		SortScore();

		for (const auto& i : average) cout << i->getName() << " " << i->getScore() << endl;	//outputs the new list
		while (!average.empty()) {
			scoreboardLink.push_back(average.front());		//puts all values back in the list
			average.pop_front();
		}
	}
}

//Returns the list of scoreboard objects
list<scoreboard*>ScoreboardList::getScoreboardList()
{
	return scoreboardLink;
}
//Function which searches through every element and outputs those with the given name
void ScoreboardList::search(string name)
{
	if (scoreboardLink.empty()) {
		cout << "Scoreboard is empty" << endl;
	}
	else {
		list<scoreboard*> temp;
		while (!scoreboardLink.empty()) {
			if (scoreboardLink.front()->getName()._Equal(name)) {
				cout << scoreboardLink.front()->getName() << " " << scoreboardLink.front()->getScore() << endl;
			}
			temp.push_back(scoreboardLink.front());	//stores the front element in a temporary list
			scoreboardLink.pop_front();
			//cout << "in first ";
		}
		cout << endl;
		while (!temp.empty()) {
			scoreboardLink.push_back(temp.front());		//puts all values back in the list
			temp.pop_front();
		}
	}
}
//Clears the list
void ScoreboardList::clear() {
	scoreboardLink.clear();
}

//Function which returns the element in the vector at index i
scoreboard ScoreboardList::getScoreboard(int i) {
	return scoreboardList[i];
}
