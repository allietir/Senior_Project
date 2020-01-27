#include <iostream>
#include "Game.h"


using namespace std;
int main(int argc, char *argv[]) {
//	Game new_game;
//	printf("\n-----GAME START-----:\n");
//	new_game.start();
//	printf("\n-----GET SHORT DESC ENTRANCE-----:\n");
//	string s_d = new_game.r_array[1]->get_short_description();
//	printf("%s", s_d.c_str());
//	string sd = new_game.r_array[new_game.player1.get_current_room()]->look();
//	printf("\n------PLAYER LOOKS AT ROOM AGAIN------:\n");
//	printf("%s", sd.c_str());
//	printf("\n------PLAYER TAKES KNIFE OBJECT------:\n");
//	new_game.take(0);
//	printf("\n------PLAYER DROPS KNIFE OBJECT------:\n");
//	new_game.drop(0);
//	printf("\n------PLAYER READS GRAVESTONE------:\n");
//	string read_action = new_game.r_array[new_game.player1.get_current_room()]->get_feature_x(0)->read();
//	printf("%s", read_action.c_str());
//	printf("\n------PLAYER LOOKS AT TREE------:\n");
//	string look_action = new_game.r_array[new_game.player1.get_current_room()]->get_feature_x(1)->look();
//	printf("%s", look_action.c_str());
//	printf("\n------PLAYER LOOKS AT TREE AGAIN------:\n");
//	look_action = new_game.r_array[new_game.player1.get_current_room()]->get_feature_x(1)->look();
//	printf("%s", look_action.c_str());
//	printf("\n------PLAYER EXITS TO ENTRANCEWAY------:\n");
//	new_game.exit_room(0);//player moves north;
//	printf("\n------PLAYER LOOKST AT ENTRANCEWAY AGAIN------:\n");
//	printf("%s\n", new_game.r_array[new_game.player1.get_current_room()]->look().c_str());
//	
//	printf("\n------PLAYER EXITS TO UPSTAIRS------:\n");
//	new_game.exit_room(0);//player moves north;
//	
//	printf("\n------PLAYER EXITS BACK TO ENTRANCEWAY------:\n");
//	new_game.exit_room(1);//player moves south;
//	
//	printf("\n------PLAYER EXITS TO DINING ROOM------:\n");
//	new_game.exit_room(2);//player moves east;
//	
//	printf("\n------PLAYER EXITS TO ENTRANCEWAY ------:\n");
//	new_game.exit_room(3);//player moves west
//	
//	printf("\n------PLAYER EXITS TO DINING ROOM------:\n");
//	new_game.exit_room(2);//player moves east
//	
//	printf("\n------PLAYER EXITS TO ENTRANCEWAY------:\n");
//	new_game.exit_room(3);//player moves WEST
//	
//	printf("\n------PLAYER EXITS TO PARLOR------:\n");
//	new_game.exit_room(3);//player moves WEST;
//	
//	printf("\n------PLAYER EXITS TO ENTRANCEWAY------:\n");
//	new_game.exit_room(2);//player moves WEST;
//	
//	printf("\n------PLAYER EXITS TO UPSTAIRS HALLWAY------:\n");
//	new_game.exit_room(0);//player moves NORTH;
//	
//	printf("\n------PLAYER EXITS TO NURSURY------:\n");
//	new_game.exit_room(0);//player moves NORTH;
//	
//	printf("\n------PLAYER EXITS TO HALLWAYS ------:\n");
//	new_game.exit_room(1);//player moves SOUTH
//	
//	printf("\n------PLAYER EXITS TO GUEST BEDROOM ------:\n");
//	new_game.exit_room(2);//player moves EAST
//	
//	printf("\n------PLAYER EXITS TO HALLWAY ------:\n");
//	new_game.exit_room(3);//player moves WEST
//		
//	printf("\n------PLAYER EXITS TO MASTER BEDROOM ------:\n");
//	new_game.exit_room(3);//player moves WEST
//	
//	printf("\n------PLAYER EXITS TO BATHROOM------:\n");
//	new_game.exit_room(0);//player moves WEST
//	
//	printf("\n------PLAYER EXITS TO MASTER BEDROOM ----:\n");
//	new_game.exit_room(1);//player moves SOUTH
//	
//	printf("\n------PLAYER EXITS TO ATTIC ----:\n");
//	new_game.exit_room(3);//player moves WEST
//	
//	printf("\n------PLAYER EXITS TO LIBRARY ----:\n");
//	new_game.exit_room(1);//player moves SOUTH
//	
//	printf("\n------PLAYER EXITS TO CONSERVATORY ----:\n");
//	new_game.exit_room(3);//player moves WEST
//	
//	printf("\n------PLAYER EXITS TO FRONT GARDEN----:\n");
//	new_game.exit_room(1);//player moves SOUTH
//	
//	printf("\n------PLAYER EXITS TO ENTRANCEWAY----:\n");
//	new_game.exit_room(0);//player moves NORTH
//	
//	printf("\n------PLAYER EXITS TO DINING ROOM----:\n");
//	new_game.exit_room(2);//player moves EAST
//	
//	printf("\n------PLAYER EXITS TO KITCHEN----:\n");
//	new_game.exit_room(2);//player moves EAST
//	
//	
//	printf("\n------PLAYER EXITS TO BASEMENT----:\n");
//	new_game.exit_room(0);//player moves north
//	
//	
//	printf("\n------PLAYER EXITS TO CRYPT----:\n");
//	new_game.exit_room(0);//player moves north
//	
//	printf("\n------PLAYER EXITS TO CRYPT----:\n");
//	new_game.exit_room(0);//player moves north
	
	
	Game test_exits;
	test_exits.start();
	for (int j = 0; j < NUM_ROOMS; j++){
		//test exit for each room
		for (int i = 0; i < MAX_EXITS; i++){
			test_exits.player1.set_current_room(j);
			test_exits.exit_room(i);
		}
	}
}