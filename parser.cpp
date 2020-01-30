#include <iostream> 
#include <vector> 
#include <string>
#include <sstream>

int inputParsing(string userInput);
string cleanInput(string userInput); 
int checkBasicCommands(string cleanInput); 
vector splitCleanInput(string cleanInput);
int checkMoveCommands(vector inputVector); 
int checkActions(vector input Vector); 


//main parsing function that will be called from the main game
//takes user input as string
//calls any necessary commands
//returns 0 if command recognized and executed
//prints error and returns 1 if invalid command
inputParsing(userInput){
	string cleanInputs = cleanInputs(userInput); 
	int status = 0; 
	status = checkBasicCommands(cleanInput);
	if (status == 1) return 0; 
	vector wordList = splitCleanInput(cleanInput); 
	status = checkMoveCommands(wordList); 
	if (status == 1) return 0; 
	status = int checkActions(wordList); 
	if (status == 1) return 0;
	else (give error statement);
	return 1;
}

//sub function that cleans the input string up. 
//Takes string as input
//Removes punctuation, special characters, any extra spacing.
//returns clean string back
//NOT IMPLEMENTED

cleanInput(userInput){
	return userInput;
}

//sub function that checks clean string against basic commands
//recognizes look, inventory, savegame, loadgame, and help
//calls the corresponding functions
//Returns an int 0 if no basic command is found or 1 if command found and executed
//needs current room, player, and game
checkBasicCommands(cleanInput){
	int basicStatus =1;
	if (cleanInput == "look"){
		//call current room long description
	}
	else if (cleanInput == "help"){
		//call help function
	}
	else if (cleanInput == "inventory"){
		//call display player inventory
	}
	else if (cleanInput == "savegame"){
		//call savegame
	}
	else if (cleanInput == "loadgame"){
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
splitCleanInput(cleanInput){
	stringstream stream(cleanInput);
	istream_iterator<string> begin(stream);
	istream_iterator<string> end;
	vector<string> wordlist(begin, end);
	copy(wordlist.begin(), wordlist.end();
	return wordlist;
}

//checks for movement commands 
//recognizes: go <direction/room>, <direction/room>
//calls the correct movement function
//returns an int 0 if no movement command is found or 1 if command found and executed
//NOT IMPLEMENTED
checkMoveCommands(inputVector){
	int moveStatus = 0;
	
	return moveStatus;
}

//checks for verbs and features/objects to execute them on
//If a pair is found calls the correct function
//Returns an int 0 if no action command is found or 1 if command found and executed
//NOT IMPLEMENTED
int checkActions(vector inputVector){
	int actionStatus = 0;
	
	return actionStatus;
}


