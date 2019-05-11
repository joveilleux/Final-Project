#include <string>
#include <iostream>
using namespace std;

#ifndef ITEM_H
#define ITEM_H


class Item
{
public:
	//CONSTRUCTOR
	Item(string n, string t, int num) {
		this->name = n;
		this->type = t;
		this->health_strength = num;
	}

	//SETTERS AND GETTERS
	string getName() { return name; }
	string getType() { return type; }
	int getHealth_Strength() { return health_strength; }
	void setHealth_Strength(int h) { this->health_strength = h; }

	/*
		FUNCTION TO COMPARE ITEMS
	*/
	bool operator==(Item item) {
		return this->name == item.name &&
			this->type == item.type;
	}
	

private:
	//ATRRIBUTES
	string name;
	string type;
	int health_strength;
	

};

#endif