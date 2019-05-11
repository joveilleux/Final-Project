#include <string>
#include <iostream>
#include <vector>
#include "Item.h"

#ifndef CHARACTER_H
#define CHARACTER_H

using namespace std;

class Character
{
public:

	//CONSTRUCTOR
	Character(string n, int h, int s, vector<Item> i) {
		this->name = n;
		this->health = h;
		this->strength = s;
		this->inventory = i;
	}

	//SETTERS AND GETTERS 
	void setHealth(int h) { this->health = h; }
	void setStrength(int s) { this->strength = s; }
	int getHealth() { return health; }
	int getStrength() { return strength; }
	int getKeys() { return keys; }
	string getName() { return name; }
	vector<Item> getInventory() { return inventory; }

	/*
		FUNTION TO 
		INCREASE HEALTH
	*/
	void increaseHealth(int h) {
		int cur_health = getHealth();
		int new_health = cur_health + h;
		setHealth(new_health);
	}

	/*
		FUNTION TO 
		DECREASE HEALTH
	*/
	void decreaseHealth(int h) {
		int cur_health = getHealth();
		int new_health = cur_health - h;
		setHealth(new_health);
	}

	/*
		FUNTION TO ADD ITEM
	*/
	void addItem(Item i) {
		inventory.push_back(i);
	}

	/*
		FUNTION TO REMOVE 
		ITEM FROM INVENTORY
	*/
	bool removeItem(Item item) {
		auto it = find(inventory.begin(), inventory.end(), item);
		if (it != inventory.end()) { inventory.erase(it); return true; }
		return false;
	}

	/*
		FUNTION TO 
		PRINT INVENTORY
	*/
	void showInventory() {
		int count = 0;
		for (Item i : inventory) {
			cout << count << ") " << i.getName() << " " << i.getHealth_Strength() << endl;
			count += 1;
		}
	}

	/*
		FUNTION TO ADD KEY
	*/
	void addKey() {
		keys += 1;
	}
private:
	//ATTRIBUTES
	string name;
	int health;
	int strength;
	vector<Item> inventory;
	int keys = 0;

};
#endif
