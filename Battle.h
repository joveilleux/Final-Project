#include "Creature.h"
#include "Character.h"
#include <string>
#include <iostream>

#ifndef BATTLE_H
#define BATTLE_H

using namespace std;

class Battle
{
public:
	//CONSTRUCTOR
	Battle(Creature* c, Character* ch){
		this->creature = c;
		this->character = ch;
	}
	//METHODS
	void meetCreature();
	bool fightCreature();

private:
	//ATTRIBUTES
	Creature* creature;
	Character* character;
	int rounds;
};

#endif

