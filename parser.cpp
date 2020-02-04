#include <iostream> 
#include <vector> 
#include <string>
#include <sstream>
#include <iterator>

using namespace std;

int inputParsing(string userInput);
string cleanInput(string userInput); 
int checkBasicCommands(string cleanInput); 
vector<string> splitCleanInput(string cleanInput);
int checkMoveCommands(vector<string> inputVector); 
int checkActions(vector<string> inputVector); 

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


//main parsing function that will be called from the main game
//takes user input as string
//calls any necessary commands
//returns 0 if command recognized and executed
//prints error and returns 1 if invalid command
int inputParsing(string userInput){
	string clean = cleanInput(userInput); 
	int status = 0; 
	status = checkBasicCommands(clean);
	if (status == 1) return 0; 
	vector<string> wordList = splitCleanInput(clean); 
	status = checkMoveCommands(wordList); 
	if (status == 1) return 0; 
	status = checkActions(wordList); 
	if (status == 1) return 0;
	else //(give error statement);
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
//needs current room, player, and game
int checkBasicCommands(string cleanInput){
	int basicStatus =1;
	if (cleanInput == "look"){
		cout << "look called\n";
		//call current room long description
	}
	else if (cleanInput == "help"){
		cout << "help called \n";
		//call help function
	}
	else if (cleanInput == "inventory"){
		cout << "inventory called \n"; 
		//call display player inventory
	}
	else if (cleanInput == "savegame"){
		cout << "savegame called \n";
		//call savegame
	}
	else if (cleanInput == "loadgame"){
		cout << "loadgame called \n"; 
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
	copy(wordlist.begin(), wordlist.end(), ostream_iterator<string>(cout, "\t"));
	cout << "\n";
	return wordlist;
}

//checks for movement commands 
//recognizes: go <direction/room>, <direction/room>
//calls the correct movement function
//returns an int 0 if no movement command is found or 1 if command found and executed
//directions IMPLEMENTD, room names NOT IMPLEMENTED
int checkMoveCommands(vector<string> inputVector){
	int moveStatus = 1;
	while (inputVector[0] == "go" || inputVector[0] == "to" || inputVector[0] == "the") {
		inputVector.erase(inputVector.begin());
	}
	if (inputVector[0] == "north") {
		cout << "called move north\n";
		//add movement to north
	}
	else if (inputVector[0] == "east") {
		cout << "called move east\n";
		//add movement to north
	}
	else if (inputVector[0] == "south") {
		cout << "called move south\n";
		//add movement to north
	}
	else if (inputVector[0] == "west") {
		cout << "called move west\n";
		//add movement to north
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
int checkActions(vector<string> inputVector) {
	int actionStatus = 1;

	if (inputVector[0] == "take" && inputVector[1] == "dagger") {
		cout << "call take dagger\n";
		//take dagger action call
	}
	else if (inputVector[0] == "look" &&
		(inputVector[1] == "gravestone"
			|| (inputVector[1] == "at" && inputVector[2] == "gravestone"))) {
		cout << "call look at gravestone\n";
		//look gravestone action
	}
	else actionStatus = 0;
	
	return actionStatus;
}


