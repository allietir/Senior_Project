#include <iostream> 
#include <vector> 
#include <string>
#include <sstream>
#include <iterator>
#include <map>
#include <algorithm>

#include "Game.h"
#include "parser.h"
#include "savesystem.h"

using namespace std;
/*
int inputParsing(Game &game, string userInput);
string cleanInput(string userInput); 
int checkBasicCommands(Game &game, string cleanInput); 
vector<string> splitCleanInput(string cleanInput);
int checkMoveCommands(Game &game, vector<string> inputVector); 
int checkActions(Game &game, vector<string> inputVector); 

*/
/*
//independent main for testing functions
int main() {
	string input = "help"; 
	int status = inputParsing(input);
	input = "look"; 
	status = inputParsing(input); 
	input = "inventory";
	status = inputParsing(input);
	input = "savegame";
	status = inputParsing(input);
	input = "loadgame";
	status = inputParsing(input);
	input = "one two three four five";
	status = inputParsing(input);
	input = "north";
	status = inputParsing(input);
	input = "go east";
	status = inputParsing(input);
	input = "go to south";
	status = inputParsing(input);
	input = "go to the west";
	status = inputParsing(input);
	input = "take dagger";
	status = inputParsing(input);
	input = "look at gravestone";
	status = inputParsing(input);
	return 0;
}

*/
//main parsing function that will be called from the main game
//takes user input as string
//calls any necessary commands
//returns 0 if command recognized and executed
//prints error and returns 1 if invalid command
int inputParsing(Game &game, string userInput){
	string clean = cleanInput(userInput); 
	int status = 0; 
	status = checkBasicCommands(game, clean);
	if (status == 1) return 0; 
	vector<string> wordList = splitCleanInput(clean); 
	status = checkMoveCommands(game, wordList); 
	if (status == 1) return 0; 
	status = checkActions(game, wordList); 
	if (status == 1) return 0;
	else cout << "unknown command \n";
	return 1;
}

//sub function that cleans the input string up. 
//Takes string as input
//Removes punctuation, special characters, any extra spacing.
//returns clean string back
//NOT IMPLEMENTED

string cleanInput(string userInput){
	return userInput;
}

//sub function that checks clean string against basic commands
//recognizes look, inventory, savegame, loadgame, and help
//calls the corresponding functions
//Returns an int 0 if no basic command is found or 1 if command found and executed
//needs commands for help, savegame, loadgame
int checkBasicCommands(Game &game, string cleanInput){
	int basicStatus =1;
	if (cleanInput == "look"){
		//cout << "look called\n";
		game.look();
	}
	else if (cleanInput == "help"){
		cout << "help called \n";
		//call help function
		game.help();
	}
	else if (cleanInput == "inventory"){
		//cout << "inventory called \n"; 
		game.inventory();
	}
	else if (cleanInput == "savegame"){
		save_game(game);
		//call savegame
	}
	else if (cleanInput == "loadgame"){
		load_game(game);
		//call load game
	}
	else {
		basicStatus = 0;
	}
	return basicStatus;	
}

//splits the cleanInput string into individual words 
//words are stored in a vector for ease of parsing
//returns wordListvector
//reference: https://stackoverflow.com/questions/5607589/right-way-to-split-an-stdstring-into-a-vectorstring
vector<string> splitCleanInput(string cleanInput){
	stringstream stream(cleanInput);
	istream_iterator<string> begin(stream);
	istream_iterator<string> end;
	vector<string> wordlist(begin, end);
	//copy(wordlist.begin(), wordlist.end(), ostream_iterator<string>(cout, "\t"));
	//cout << "\n";
	return wordlist;
}

//checks for movement commands 
//recognizes: go <direction/room>, <direction/room>
//calls the correct movement function
//returns an int 0 if no movement command is found or 1 if command found and executed
//call needed for room by ID
int checkMoveCommands(Game &game, vector<string> inputVector){
	int moveStatus = 1;
	while (inputVector[0] == "go" || inputVector[0] == "to" || inputVector[0] == "the") {
		inputVector.erase(inputVector.begin());
	}

	map<string, int>::const_iterator it;
	it = roomIDmap.find(inputVector[0]);
	
	if (it != roomIDmap.end()) {
		// room name matched
		//cout << "room name found \n"; 
		int roomID = it->second;
		game.exit_current_from_room_id(roomID);
	}
	else if (inputVector[0] == "north") {
		//cout << "called move north\n";
		game.exit_room(0);
	}
	else if (inputVector[0] == "east") {
		//cout << "called move east\n";
		game.exit_room(2);
	}
	else if (inputVector[0] == "south") {
		//cout << "called move south\n";
		game.exit_room(1);
	}
	else if (inputVector[0] == "west") {
		//cout << "called move west\n";
		game.exit_room(3);
	}
	else {
		moveStatus = 0;
	}
	return moveStatus;
}

//checks for verbs and features/objects to execute them on
//If a pair is found calls the correct function
//Returns an int 0 if no action command is found or 1 if command found and executed
//NOT IMPLEMENTED
int checkActions(Game &game, vector<string> inputVector) {
	int actionStatus = 1;

//	if (inputVector[0] == "take" && inputVector[1] == "dagger") {
//		//cout << "call take dagger\n";
//		game.take(4);
//	}
//	else if (inputVector[0] == "drop" && inputVector[1] == "dagger") {
//		//cout << "call take dagger\n";
//		game.drop(4);
//	}
	if (inputVector[0] == "look" &&
		(inputVector[1] == "gravestone"
			|| (inputVector[1] == "at" && inputVector[2] == "gravestone"))) {
		cout << "call look at gravestone\n";
		//game.r_array[game.player1.get_current_room()]->get_feature_X(0)->look();
	}
	else actionStatus = 0;

	int verbID = -1;
	int featID = -1;
	int objID = -1;

	map<string, int>::const_iterator verbIT;
	map<string, int>::const_iterator objIT;
	map<string, int>::const_iterator featIT;

	for (int i = 0; i < inputVector.size(); i++) {

		verbIT = verbIDmap.find(inputVector[i]);
		featIT = featIDmap.find(inputVector[i]);
		objIT = objIDmap.find(inputVector[i]);

		if (verbIT != verbIDmap.end()) {
			// verb name matched
			cout << "\tverb: "; 
			cout << inputVector[i]; 
			if (verbID == -1) verbID = verbIT->second;
			else {
				actionStatus = -1;
				cout << "\ntoo many verbs\n";
				return actionStatus;
			}
		}
		else if (featIT != featIDmap.end()) {
			// feature name matched 
			cout << "\tfeature: ";
			cout << inputVector[i];
			if (featID == -1) featID = featIT->second;
			else {
				actionStatus = -1;
				cout << "\ntoo many features\n";
				return actionStatus;
			}
		}
		else if (objIT != objIDmap.end()) {
			// object name matched 
			cout << "\tobject: ";
			cout << inputVector[i];
			if (objID == -1) objID = objIT->second;
			else {
				actionStatus = -1;
				cout << "\ntoo many objects\n";
				return actionStatus;
			}
		}
	}
	cout << "\n";
	if (verbID == -1 || (featID == -1 && objID == -1)) {
		actionStatus = 0;
		cout << "incorrect arguments found\n";
	}
	else {
		int x = game.run_func(featID, objID, verbID);
		if (x == -1){
			save_game(game);
			load_game(game);
			save_game(game);
		}
		actionStatus = 1;
	}

	
	return actionStatus;
}
