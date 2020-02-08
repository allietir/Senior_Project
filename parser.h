// parser.h
// maps used by parser

#ifndef _parser_h_
#define _parser_h_
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>

#include "Game.h"

using namespace std; 

int inputParsing(Game& game, string userInput);
string cleanInput(string userInput);
int checkBasicCommands(Game& game, string cleanInput);
vector<string> splitCleanInput(string cleanInput);
int checkMoveCommands(Game& game, vector<string> inputVector);
int checkActions(Game& game, vector<string> inputVector);

//map to look up room ID
const map<string, int> roomIDmap = {
	{ "front", 0 },
	{ "entranceway", 1 },
	{ "upstairs", 2 },
	{ "dining", 3},
	{ "parlor", 4},
	{ "nursery", 5},
	{ "guest", 6},
	{ "master", 7},
	{ "bathroom", 8},
	{ "attic", 9},
	{ "library", 10},
	{ "conservatory", 11},
	{ "kitchen", 12},
	{ "basement", 13},
	{ "crypt", 14}
};

const map<string, int> verbIDmap = {
	{ "read", 0 },
	{ "smell", 1 },
	{ "use", 2 },
	{ "eat", 3},
	{ "play", 4},
	{ "open", 5},
	{ "speak", 6},
	{ "give", 7},
	{ "climb", 8},
	{ "attack", 9},
};

//map to look up object ID
const map<string, int> objIDmap = {
    { "lamp", 0 },
	{ "diary", 1 },
    { "locket", 2 },
	{ "music", 3 },
	{ "dagger", 4}, 
	{ "doll", 5}, 
	{ "key", 6}, 
	{ "chalice", 7}, 
};

//map to look up feature ID
const map<string, int> featIDmap = {
    { "gravestone", 0},
	{ "tree", 1 },
    { "portrait", 2 },
	{ "musicbox", 3 },
	{ "mirror", 4}, 
	{ "carpet", 5}, 
	{ "faceless", 6}, 
	{ "table", 7}, 
	{ "piano", 8}, 
	{ "trapdoor", 9},
	{ "child", 10}, 
	{ "dollhouse", 11}, 
	{ "mother", 12}, 
	{ "dresser", 13}, 
	{ "vampire", 14}, 
	{ "blood", 15},
	//{ "mirror", 16}, can't have 2 of same name but different ID
	{ "sink", 17 },
    { "chest", 18 },
	{ "pirate", 19 },
	{ "bookshelf", 20}, 
	{ "fireplace", 21}, 
	{ "fountain", 22}, 
	{ "guardian", 23}, 
	{ "stove", 24}, 
	{ "cupboard", 25},
	{ "pedestal", 26}, 
	{ "statue", 27}, 
	{ "alex", 28}, 
	{ "demon", 29}, 
};


#endif