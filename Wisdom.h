#include <map>
#include <string>
#include <iostream>

#ifndef WISDOM_H
#define WISDOM_H

using namespace std;

class Wisdom
{
public:
	//CONSTRUCTOR
	Wisdom(map<int, string> questions, map<int, string> answers) {
		this->riddle_q = questions;
		this->riddle_a = answers;
	}

	//METHODS
	string getRiddle(int index_num) { return riddle_q.at(index_num); }
	string getAnswer(int index_num) { return riddle_a.at(index_num); }
	void addRiddle(int num, string r) {riddle_q.insert(pair<int, string>(num, r));}
	void addAnswer(int num, string a) { riddle_a.insert(pair<int, string>(num, a)); }

private:
	//ATTRIBUTES
	int index_num;
	map<int, string> riddle_q;
	map<int, string> riddle_a;
};

#endif

