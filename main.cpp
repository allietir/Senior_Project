#include <iostream>
#include "Game.h"
#include "parser.h"
#include "savesystem.h"


using namespace std;
int main(int argc, char *argv[]) {
Game new_game;

	/*string userInput = ""; 
	while (1) {
		cout << "what would you like to do: \n";
		getline(cin, userInput);
		inputParsing(new_game, userInput);
	}*/


new_game.start();
save_game(new_game);
load_game(new_game);
save_game(new_game);

	
}