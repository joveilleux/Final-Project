#include <string>
#include <iostream>

#ifndef CREATURE_H
#define CREATURE_H

using namespace std;

class Creature
{
public:
	//CONSTRUCTOR
	Creature(string n, string t, int h, int s) {
		this->name = n;
		this->type = t;
		this->health = h;
		this->strength = s;
	}

	//SETTERS AND GETTERS
	void setHealth(int h) { health = h; }
	void setStrength(int s) { strength = s; }
	int getHealth() { return health; }
	int getStrength() { return strength; }
	string getName() { return name; }
	string getType() { return type; }

	//METHODS
	void decreaseHealth(int h) {
		int cur_health = getHealth();
		int new_health = cur_health - h;
		setHealth(new_health);
	}

private:
	//ATTRIBUTES
	string name;
	string type;
	int health;
	int strength;
	
};
#endif
