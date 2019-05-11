#include "Character.h"
#include "Item.h"
#include "Creature.h"
#include "Battle.h"
#include "Wisdom.h"
#include "Instantiate.h"
#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h> 
#include <stdio.h> 
#include <time.h>

using namespace std;
int keys_needed;		//GLOBAL VARIABLE

/*
	FUNCTION TO DISPLAY INSTRUCTIONS AND GET USER INPUT
*/
void instructions() {
	//INTRODUCTION
	cout << "****************************************************************" << endl;
	cout << "*                 GAME PLAY INSTRUCTIONS		       *" << endl;
	cout << "****************************************************************" << endl;
	cout << "****************************************************************" << endl;
	cout << "*               WELCOME TO MY ADVENTURE GAME!                  *" << endl;
	cout << "*          Your challenge will be to collect KEYS,             *" << endl;
	cout << "*             Each KEY will unlock other LEVEL.                *" << endl;
	cout << "*       To collect a KEY you must do ONE of TWO things:        *" << endl;
	cout << "*       1) DEFEAT a CREATURE in a terrifying battle OR         *" << endl;
	cout << "*   2) SOLVE a RIDDLE known to stump the smartest of them all  *" << endl;
	cout << "*        If you FAIL a challenge you will be BANISHED,         *" << endl;
	cout << "*     HOWEVER, if you manage to collect all of the KEYS...     *" << endl;
	cout << "*  You will have to PROVE yourself by DEFEATING the strongest  *" << endl;
	cout << "*             and most terrifying CREATURE of all!             *" << endl;
	cout << "*      So what do you say? Are you up for the QUEST?(y/n)      *" << endl;
	cout << "****************************************************************" << endl;

	//PLAYER DECIDES IF THEY WANT TO PLAY
	string answer;																
	cin >> answer;

	//VALIDATE OUTPUT
	while (answer != "y" && answer != "n") {									
		cout << "****************************************************************" << endl;
		cout << "*            That is not a valid input. Try again.             *" << endl;
		cout << "****************************************************************" << endl;
		cin >> answer;
	}

	//YES, WANTS TO PLAY
	if (answer == "y") {
		cout << "****************************************************************" << endl;
		cout << "*           You can choose between three MODES:                *" << endl;				
		cout << "*                        1) SHORT                              *" << endl;		//3 KEYS
		cout << "*                        2) MEDIUM                             *" << endl;		//5 KEYS
		cout << "*                        3) LONG                               *" << endl;		//7 KEYS
		cout << "*                What do you CHOOSE?(1/2/3)                    *" << endl;
		cout << "****************************************************************" << endl;

		//PLAYER CHOOSES GAME MODE
		string mode;															
		cin >> mode;

		//VALIDATE INPUT
		cout << "" << endl;
		while (mode != "1" && mode != "2" && mode != "3") {						
			cout << "* That is not a valid input. TRY AGAIN.                        *" << endl;
			cin >> mode;

		}
		//SET KEYS NEEDED
		if (mode == "1") { keys_needed = 3; }									
		else if (mode == "2") { keys_needed = 5; }
		else { keys_needed = 7; }
	}
	//NO, DOES NOT WANT TO PLAY
	else {
		cout << "" << endl;
		cout << "* Sorry to see you go!                                         *" << endl;
		cout << "* Maybe you will come around another day...                    *" << endl;
		cout << "" << endl;

		//END PROGRAM
		exit(0);																
	}

}

/*
	FUNCTION TO INSTANTIATE DUMMY DATABASES
*/
Instantiate instantiate() {
	Instantiate game_dbs = Instantiate();
	game_dbs.makeItems();		
	game_dbs.makeCreatures();	//http://www.namenerds.com/uucn/shakes.html & http://www.gods-and-monsters.com/list-of-mythical-creatures.html
	game_dbs.makeWisdoms();		//http://brainden.com/logic-riddles.htm & https://riddles.fyi/
	return game_dbs;
}

/*
	FUNCTION TO CREATE CHARACTER OBJECT
*/
Character createCharacter(Instantiate dbs) {
	
	//GENERATE INVENTORY AND DEFAULT ITEMS
	vector<Item> inventory;														 
	for (int i = 0; i < 2; i++) {												
		inventory.push_back(dbs.items.at(i));
	}
	//SET DEFAULT HEALTH AND STRENGTH
	int health = 100;															
	int strength = 25;

	//GET PLAYER NAME
	string name;	
	cout << "****************************************************************" << endl;
	cout << "*               What is your name player?                      *" << endl;
	cout << "****************************************************************" << endl;
	cin >> name;
	cout << "" << endl;

	//INSTANTIATE CHARACTER OBJECT
	Character player = Character(name, 100, 50, inventory);						
	return player;
}

/*
	FUNCTION TO END THE GAME
*/
void endGame() {
	cout << "****************************************************************" << endl;
	cout << "*     Sorry, it looks like your quest must come to an end.     *" << endl;
	cout << "****************************************************************" << endl;

	exit(0);
}

/*
	FUNCTION TO PLAY GAME
*/
void playGame(Character player, Instantiate dbs) {
	Character* player_p = &player;

	//PLAY UNTIL YOU HAVE NUMBER OF KEYS NEEDED
	for(int i = 1; i <= keys_needed; i++){
		cout << "****************************************************************" << endl;
		cout << "*                       ROUND: " << i << "                               *" << endl;
		cout << "****************************************************************" << endl;
		
		//GENERATE RANDOM NUMBER FOR CHALLENGE MODE
		srand(time(NULL));
		int challenge_type = rand() % 100;		

		//BATTLE CHALLENGE     
		if (challenge_type % 2 == 0) {
			//GENERATE A RANDOM CREATURE TO FIGHT
			srand(time(NULL));
			int random_creature = rand() % 19;
			Creature creature = dbs.creatures.at(random_creature);
			Creature* creature_p = &creature;

			//INSTANTIAT BATTLE OBJECT
			Battle battle = Battle(creature_p, player_p);						
			
			//INITIATE BATTLE
			battle.meetCreature();												
			bool result = battle.fightCreature();	

			//WINS	
			if (result) {
				//ADD RANDOM ITEM TO INVENTORY
				srand(time(NULL));
				int random_item = rand() % 9;
				player.addItem(dbs.items.at(random_item));						
				//ADD KEY
				player.addKey();												
			}
			//LOSES
			else {
				//END GAME
				endGame();
			}
		}
		//WISDOM CHALLENGE
		else {
			//GENERATE RANDOM RIDDLE TO SOLVE
			srand(time(NULL));
			int random_riddle = rand() % 19;
			Wisdom wisdom = Wisdom(dbs.wisdomQuestions, dbs.wisdomAnswers);		
			string question = wisdom.getRiddle(random_riddle);			

			//GET ANSWER
			string correct_answer = wisdom.getAnswer(random_riddle);	

			//GIVE RIDDLE
			cout << "" << endl;
			cout  << player.getName() << " ANSWER me this RIDDLE:" << endl;
			cout << question << endl;
			

			//GET PLAYER GUESS
			string answer;
			cin >> answer;		
			cout << "" << endl;

			//WINS
			if (answer == correct_answer) {
				cout << "****************************************************************" << endl;
				cout << "*           CONGRATULATIONS, you have bested me!               *" << endl;
				cout << "*      Here is a KEY and an ITEM for your efforts...           *" << endl;
				cout << "****************************************************************" << endl;
				//ADD RANDOM ITEM TO INVENTORY
				srand(time(NULL));
				int random_item = rand() % 9;
				player.addItem(dbs.items.at(random_item));						
				//ADD KEY
				player.addKey();												


			}
			//LOSES
			else {
				cout << "" << endl;
				cout << "OOF! That is not the correct answer!" << endl;
				cout << "Better luck next time...NOT!" << endl;
				cout << "" << endl;
				//END GAME
				endGame();
			}

		}

	}
	//FIGHT FINAL BOSS
	cout << "****************************************************************" << endl;
	cout << "*                       ROUND: FINAL BOSS                      *" << endl;
	cout << "****************************************************************" << endl;
	cout << "" << endl;
	cout << "Wow! I severely underestimated you..." << endl;
	cout << "You have proven you are worthy, but can you live through" << endl;
	cout << "this final battle? We will see..." << endl;
	cout << "" << endl;

	//GET FINAL BOSS
	Creature creature = dbs.creatures.at(20);									
	Creature* creature_p = &creature;

	//INSTANTIATE AND INITIATE BATTLE
	Battle battle = Battle(creature_p, player_p);								
	battle.meetCreature();												
	bool result = battle.fightCreature();	

	//WINS
	if (result) {
		cout << "Wow! I severely underestimated you..." << endl;
		cout << "You have proven your worth, I dub you a knight of the realms" << endl;
		cout << "Go and keep watch, we are counting on you..." << endl;

	}
	//LOSES
	else {
		cout << "****************************************************************" << endl;
		cout << "*  Looks like you could not beat the final creature...BYE BYE  *" << endl;
		cout << "****************************************************************" << endl;
		//END GAME
		endGame();
	}
	
}
/*
	MAIN FUNCTION
*/
int main() {
	//INSTRUCTIONS
	instructions();
	//INSTANTIATE DUMMY DATABASES
	Instantiate game_databases = instantiate();
	//CREATE CHARACTER OBJECT FOR PLAYER
	Character player = createCharacter(game_databases);
	//PLAY GAME
	playGame(player, game_databases);
};