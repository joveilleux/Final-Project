#include <string>
#include <fstream>
#include <vector>
#include "Item.h"
#include "Creature.h"
#include "Wisdom.h"

using namespace std;

#ifndef INSTANTIATE_H
#define INSTANTIATE_H
class Instantiate
{
public:

	//CONSTRUCTOR
	Instantiate() {}

	//ATTRIBUTES
	map<int, Item> items;
	map<int, Creature> creatures;
	map<int, string> wisdomQuestions;
	map<int, string> wisdomAnswers;

	/*
		FUNCTION TO MAKE 
		DUMMY DATABASE
		FOR ITEMS
	*/
	void makeItems() {

		//OPEN FILE
		ifstream file("itemDB.csv");

		//VARIABLES
		string name;
		string type;
		string snum;
		int index = 0;

		// https://github.com/tpatil2/C-Programs/blob/master/RWcsv/rwcsv.cpp
		//FOR EACH LINE SEPARATE ON COMMAS INTO THE GIVEN VARIABLE
		while (file.good()) {
			getline(file, name, ',');
			getline(file, type, ',');
			getline(file, snum, '\n');

			//TURN NUM INTO INT
			int num = stoi(snum);
			//INSTANTIATE ITEM OBJECT
			Item item = Item(name, type, num);
			//ADD TO MAP
			items.insert(pair<int, Item>(index, item));
			//INCREASE INDEX NUMBER
			index += 1;
		}

		//CLOSE FILE
		file.close();
	}

	/*
		FUNCTION TO MAKE
		DUMMY DATABASE
		FOR CREATURES
	*/
	void makeCreatures() {
		
		//OPEN FILE
		ifstream file("creatureDB.csv");

		//VARIABLES
		string name;
		string type;
		string shealth;
		string sstrength;
		int index = 0;

		// https://github.com/tpatil2/C-Programs/blob/master/RWcsv/rwcsv.cpp
		//FOR EACH LINE SEPARATE ON COMMAS INTO THE GIVEN VARIABLE
		while (file.good()) {
			getline(file, name, ',');
			getline(file, type, ',');
			getline(file, shealth, ',');
			getline(file, sstrength, '\n');

			//TURN INTO INT 
			int health = stoi(shealth);
			int strength = stoi(sstrength);

			//INSTANTIATE CREATURE OBJECT
			Creature creature = Creature(name, type, health, strength);
			//ADD TO MAP
			creatures.insert(pair<int, Creature>(index, creature));
			//INCREASE INDEX NUMBER
			index += 1;
		}
		//CLOSE FILE
		file.close();
	}

	/*
		FUNCTION TO MAKE
		DUMMY DATABASE
		FOR WISDOMS
	*/
	void makeWisdoms() {

		//OPEN FILE
		ifstream file("wisdomDB.csv");

		//VARIABLES
		string question;
		string answer;
		int index = 0;


		// https://github.com/tpatil2/C-Programs/blob/master/RWcsv/rwcsv.cpp
		//FOR EACH LINE SEPARATE ON COMMAS INTO THE GIVEN VARIABLE
		while (file.good()) {
			getline(file, question, ',');
			getline(file, answer, '\n');

			//ADD TO MAPS
			wisdomQuestions.insert(pair<int, string>(index, question));
			wisdomAnswers.insert(pair<int, string>(index, answer));
			//INCREASE INDEX NUMBER
			index += 1;
		}
		//CLOSE FILE
		file.close();
	}

};
#endif