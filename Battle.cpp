#include "Battle.h"
#include "Item.h"

/*
	FUNCTION TO MEET CREATURE
*/
void Battle::meetCreature(){
	string creature_name = Battle::creature->getName();
	string creature_type = Battle::creature->getType();

	cout << "" << endl;
	cout << "Hello " << Battle::character->getName() << "..." << endl;
	cout << "My name is " << creature_name << " and I am a " << creature_type << ". You will have the" <<  endl;
	cout << "oppertunity to CHOOSE a WEAPON or a POTION at the beginning of" << endl;
	cout << "each ROUND. Once you've made your move, I will make mine. I will " << endl;
	cout << "do " << Battle::creature->getStrength() << " DAMAGE to you every ROUND. Let us see if you have " << endl;
	cout << "the STRENGTH and COURAGE to DEFEAT me..." << endl;
	cout << "" << endl;
}

/*
	FUNCTION TO BATTLE CREATURE
*/
bool Battle::fightCreature() {
	string character_name = Battle::character->getName();		//variable to hold player name

	//BATTLE UNTIL ONE IS DEFEATED
	while (Battle::creature->getHealth() > 0 && Battle::character->getHealth() > 0) {
		//PRINT STATS
		cout << "" << endl;
		cout << "STATS" << endl;
		cout << Battle::creature->getName() << "'s HEALTH: " << Battle::creature->getHealth() << endl;
		cout << Battle::character->getName() << "'s HEALTH: " << Battle::character->getHealth() << endl;
		cout << Battle::creature->getName() << "'s STRENGTH: " << Battle::creature->getStrength() << endl;
		cout << Battle::character->getName() << "'s STRENGTH: " << Battle::character->getStrength() << endl;
		cout << "" << endl;

		//CHOOSE ITEM TO USE 
		cout << "****************************************************************" << endl;
		cout << character_name << ", CHOOSE YOUR WEAPON: " << endl;
		Battle::character->showInventory();
		cout << "****************************************************************" << endl;

		//GET PLAYER CHOICE
		int choice;
		cin >> choice;
		
		//VALIDATE INPUT
		int inventory_size = Battle::character->getInventory().size();
		while (choice > inventory_size - 1) {
			cout << "****************************************************************" << endl;
			cout << "*         That is not a valid choice. TTRY AGAIN.               *" << endl;
			cout << "****************************************************************" << endl;
			cin >> choice;
		}

		//GET CHOSEN ITEM
		vector<Item> inventory = Battle::character->getInventory();
		//HEALING POTION
		if (inventory.at(choice).getType() == "healing") {
			Item item = inventory.at(choice);

			//INCREASE HEALTH
			Battle::character->increaseHealth(item.getHealth_Strength());
			//CHECK THAT IT IS NOT OVER 100
			if (Battle::character->getHealth() > 100) {
				Battle::character->setHealth(100);
			}
			//REMOVE FROM INVENTORY
			character->removeItem(item);

			//PRINT NEW STATS
			cout << "****************************************************************" << endl;
			cout << " YOU HAVE TAKEN A HEALING POTION                               " << endl;
			cout << " YOUR HEALTH IS NOW " << Battle::character->getHealth() << endl;
			cout << "****************************************************************" << endl;

		}
		//WEAPON
		else {
			//GET CHOSEN ITEM
			Item item = inventory.at(choice);

			//DECREASE CREATURE HEALTH
			int damage = item.getHealth_Strength() + Battle::character->getStrength();
			Battle::creature->decreaseHealth(damage);

			//PRINT NEW STATS
			cout << "****************************************************************" << endl;
			cout << Battle::character->getName() << " HAS STRUCK, " << Battle::creature->getName() << " LOSES " << damage << " HEALTH." << endl;
			cout << "****************************************************************" << endl;
		}

		//PLAYER WINS
		if (Battle::creature->getHealth() <= 0) {
			cout << "****************************************************************" << endl;
			cout << "* You have DEFEATED the CREATURE...here is a KEY and an ITEM   *" << endl;
			cout << "****************************************************************" << endl;
			return true;
		}

		//CREATURE TURN: DECREASE HEALTH 
		//PRINT NEW STATS
		cout << "****************************************************************" << endl;
		cout << Battle::creature->getName() << " HAS STRUCK, YOU LOSE " << Battle::creature->getStrength() << " HEALTH." << endl;
		Battle::character->decreaseHealth(Battle::creature->getStrength());
		cout << "****************************************************************" << endl;
	}

	//PLAYER LOSES
	cout << "****************************************************************" << endl;
	cout << "*                       YOU HAVE DIED                          *" << endl;
	cout << "****************************************************************" << endl;
	return false;


	
}