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

map<string, int> roomIDmap = {
	{ "front", 1 },
	{ "entranceway", 2 },
	{ "upstairs", 3 },
	{ "dining", 4},
	{ "parlor", 5},
	{ "nursery", 6},
	{ "guest", 7},
	{ "master", 8},
	{ "bathroom", 9},
	{ "attic", 10},
	{ "library", 11},
	{ "conservatory", 12},
	{ "kitchen", 13},
	{ "basement", 14},
	{ "crypt", 15}
};

//map to look up object ID
static const map<string, int> objectIDmap = {
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
static const map<string, int> featureIDmap = {
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