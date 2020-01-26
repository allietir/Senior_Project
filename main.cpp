#include <iostream>
#include "Game.h"


using namespace std;
int main(int argc, char *argv[]) {
	Game new_game;
	printf("\n-----GAME START-----:\n");
	new_game.start();
	string sd = new_game.r_array[new_game.player1.get_current_room()]->look();
	printf("\n------PLAYER LOOKS AT ROOM AGAIN------:\n");
	printf("%s", sd.c_str());
	printf("\n------PLAYER TAKES KNIFE OBJECT------:\n");
	new_game.take(0);
	printf("\n------PLAYER DROPS KNIFE OBJECT------:\n");
	new_game.drop(0);
	printf("\n------PLAYER READS GRAVESTONE------:\n");
	string read_action = new_game.r_array[new_game.player1.get_current_room()]->get_feature_x(0)->read();
	printf("%s", read_action.c_str());
	printf("\n------PLAYER LOOKS AT TREE------:\n");
	string look_action = new_game.r_array[new_game.player1.get_current_room()]->get_feature_x(1)->look();
	printf("%s", look_action.c_str());
	printf("\n------PLAYER EXITS TO ------:\n");
	
	

	
	
}