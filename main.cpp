#include <iostream>
#include "Game.h"
using namespace std;
int main(int argc, char *argv[]) {
	printf("This is the main function, which includes the Game.h class");	
	Game new_game;
	//TEMPORARY; these will actually be set in the files
	
	printf("\n-----GAME START-----:\n");
	new_game.start();
	string sd = new_game.r_array[new_game.player1.get_current_room()].look();
	printf("\n------PLAYER LOOKS AT ROOM AGAIN------:\n");
	printf("%s", sd.c_str());
	printf("\n------PLAYER TAKES KNIFE OBJECT------:\n");
	new_game.take(0);
	printf("\n------PLAYER DROPS KNIFE OBJECT------:\n");
	new_game.drop(0);
	
}