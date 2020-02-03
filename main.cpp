#include <iostream>
#include "Game.h"


using namespace std;
int main(int argc, char *argv[]) {
//	Game new_game;
//	printf("\n-----GAME START-----:\n");
//	new_game.start();
//	printf("\n-----GET SHORT DESC ENTRANCE-----:\n");
// 	new_game.look();
//	printf("\n------PLAYER LOOKS AT ROOM AGAIN------:\n");
//	new_game.look();
//	printf("\n------PLAYER TAKES KNIFE OBJECT------:\n");
//	new_game.take(0);
//	printf("\n------PLAYER DROPS KNIFE OBJECT------:\n");
//	new_game.drop(0);
//	printf("\n------PLAYER READS GRAVESTONE------:\n");
//	new_game.r_array[new_game.player1.get_current_room()]->get_feature_x(0)->read();
//
//	printf("\n------PLAYER LOOKS AT TREE------:\n");
//	new_game.r_array[new_game.player1.get_current_room()]->get_feature_x(1)->look();
//	
//	printf("\n------PLAYER LOOKS AT TREE AGAIN------:\n");
//	new_game.r_array[new_game.player1.get_current_room()]->get_feature_x(1)->look();
//
//	printf("\n------PLAYER EXITS TO ENTRANCEWAY------:\n");
//	new_game.exit_room(0);//player moves north;
//	printf("\n------PLAYER LOOKST AT ENTRANCEWAY AGAIN------:\n");
//	new_game.r_array[new_game.player1.get_current_room()]->look();
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
//	
//	
//	Game test_exits;
//	test_exits.start();
//	for (int j = 0; j < NUM_ROOMS; j++){
//		//test exit for each room
//		for (int i = 0; i < MAX_EXITS; i++){
//			test_exits.player1.set_current_room(j);
//			test_exits.exit_room(i);
//		}
//	}
//	Game test_features;
//	
//	for (int j = 0; j < NUM_ROOMS; j++){
//		
//		test_features.r_array[j]->get_feature_x(0)->look();
//		test_features.r_array[j]->get_feature_x(1)->look();
//		
//
//	}
//	
//	Game test_objects;
//	for (int i = 0; i < NUM_ROOMS; i++){
//		test_objects.player1.set_current_room(i);
//		//try to take each object in each room
//		for (int j = 0; j < NUM_OBJECTS; j++){
//			test_objects.take(j);
//		}
//	}
//	//after you have all items in your inventory...
//	for (int i = 0; i < NUM_ROOMS; i++){
//		test_objects.player1.set_current_room(i);
//		//...try to drop each item in each room and then take it again
//		for (int j = 0; j < NUM_OBJECTS; j++){
//			test_objects.drop(j);
//			test_objects.take(j);
//		}
//	}
// 	Game test_obj_exits;
//	for (int j = 0; j < NUM_ROOMS; j++){
//		//test exit for each room
//		for (int i = 0; i < MAX_EXITS; i++){
//			test_obj_exits.player1.set_current_room(j);
//			test_obj_exits.exit_room(i);
//		}
//	}
//	printf("-------TESTING WHEN USER HAS NEEDED OBJECTS----\n");
//	//now when you do have the object
//	test_obj_exits.player1.set_has_objects(0, 1);
//	for (int j = 0; j < NUM_ROOMS; j++){
//		//test exit for each room
//		for (int i = 0; i < MAX_EXITS; i++){
//			test_obj_exits.player1.set_current_room(j);
//			test_obj_exits.exit_room(i);
//		}
//	}

	/*******ALLIE'S TESTS START HERE*******/
	Game flow_test;
	printf("////////////////START///////////////////\n\n");
	flow_test.start();
	
	//----parser helper demo---//
	string x = "Gravestone";
	int y = flow_test.get_context_id_from_string(x);
	printf("%s: %i", x.c_str(), y);
	
	string obj = "Gilded dagger";
	int obj_num = flow_test.get_obj_id_from_string(obj);
	printf("gilded dagger: %i", obj_num);
	
	printf("\n+++++++++++++++PLAYER STARTS IN FRONT GARDEN++++++++++++++\n");
	flow_test.r_array[0]->look();
	
	printf("+++++++++++++++PLAYER look() at Gravestone++++++++++++++\n");
	flow_test.r_array[0]->get_feature_x(0)->look();

	printf("+++++++++++++++PLAYER look() at knife++++++++++++++\n");
	flow_test.o_array[4]->look();
	printf("+++++++++++++++PLAYER take() knife++++++++++++++\n");
	flow_test.take(4);
	printf("+++++++++++++++PLAYER look at gravestone++++++++++++++\n");
	flow_test.r_array[0]->get_feature_x(0)->look();
	printf("+++++++++++++++PLAYER drop knife++++++++++++++\n");
	flow_test.drop(4);
	printf("+++++++++++++++PLAYER look at room++++++++++++++\n");
	flow_test.look();
	printf("+++++++++++++++PLAYER look() at tree++++++++++++++\n");
	flow_test.r_array[0]->get_feature_x(1)->look();
	printf("+++++++++++++++ Player exits front garden to entranceway ++++++++++++++\n");	
	flow_test.exit_room(0);
	
	printf("-------PLAYER LOOK AT ROOM---------\n");
	flow_test.r_array[1]->look();
	/*******ALLIE'S TESTS END HERE*******/

/*
	Game flow_test;
	printf("////////////////START///////////////////\n\n");
	flow_test.start();
	
	//----parser helper demo---//
	string x = "Gravestone";
	int y = flow_test.get_context_id_from_string(x);
	printf("%s: %i", x.c_str(), y);
	
	string obj = "Gilded dagger";
	int obj_num = flow_test.get_obj_id_from_string(obj);
	printf("gilded dagger: %i", obj_num);
	

	
	printf("\n+++++++++++++++PLAYER STARTS IN FRONT GARDEN++++++++++++++\n");
	flow_test.r_array[0]->look();
	
	printf("+++++++++++++++PLAYER look() at Gravestone++++++++++++++\n");
	flow_test.r_array[0]->get_feature_x(0)->look();
	
	printf("+++++++++++++++PLAYER look() Gravestone again ++++++++++++++\n");
	flow_test.r_array[0]->get_feature_x(0)->look();
	printf("+++++++++++++++PLAYER look() at knife++++++++++++++\n");
	flow_test.o_array[4]->look();
	printf("+++++++++++++++PLAYER take() knife++++++++++++++\n");
	flow_test.take(4);
	printf("+++++++++++++++PLAYER look at gravestone++++++++++++++\n");
	flow_test.r_array[0]->get_feature_x(0)->look();
	printf("+++++++++++++++PLAYER look at gravestone++++++++++++++\n");
	flow_test.r_array[0]->get_feature_x(0)->look();
	printf("+++++++++++++++PLAYER drop knife++++++++++++++\n");
	flow_test.drop(4);
	printf("+++++++++++++++PLAYER look at room++++++++++++++\n");
	flow_test.look();
	printf("+++++++++++++++PLAYER look() at tree++++++++++++++\n");
	flow_test.r_array[0]->get_feature_x(1)->look();
	printf("+++++++++++++++PLAYER look() at tree again++++++++++++++\n");
	flow_test.r_array[0]->get_feature_x(1)->look();
	printf("+++++++++++++++ example of exiting with a feature START ++++++++++++++\n");	
	printf("+++++++++++++++PLAYER climb() ++++++++++++++\n");
	flow_test.climb(1);
	printf("+++++++++++++++PLAYER climb()again ++++++++++++++\n");
	flow_test.climb(1);
		
	printf("+++++++++++++++PLAYER climb()again ++++++++++++++\n");
	flow_test.climb(1);
	
	printf("+++++++++++++++PLAYER jump()again ++++++++++++++\n");
	flow_test.jump(1);
	
//	flow_test.exit_r1_r8();
//	
	printf("+++++++++++++++ example of exiting with a feature END, back to FRONT GARDEN ++++++++++++++\n");	
	flow_test.player1.set_current_room(0);

	printf("+++++++++++++++ Player exits front garden to entranceway ++++++++++++++\n");	
	flow_test.exit_room(0);
	
	printf("-------PLAYER LOOK AT ROOM---------\n");
	flow_test.r_array[1]->look();
*/
/*
	printf("------PLAYER LOOKS AT MUSIC BOX--------\n");
	flow_test.r_array[1]->get_feature_x(1)->look();
	printf("------PLAYER TRY TO play() MUSIC BOX BEFORE OPENING --------\n");
	flow_test.r_array[1]->get_feature_x(1)->play();
	printf("------PLAYER open() MUSIC BOX--------\n");
	flow_test.r_array[1]->get_feature_x(1)->open();
	printf("------PLAYER play() MUSIC BOX--------\n");
	flow_test.r_array[1]->get_feature_x(1)->play();
	printf("------PLAYER TRY push() MUSIC BOX--------\n");
	flow_test.r_array[1]->get_feature_x(1)->push();
	printf("------PLAYER pull() MUSIC BOX--------\n");
	flow_test.r_array[1]->get_feature_x(1)->pull();
	printf("------PLAYER TRY push() MUSIC BOX--------\n");
	flow_test.r_array[1]->get_feature_x(1)->push();
	
	
	
	printf("------PLAYER LOOKS AT PAINTING--------\n");
	flow_test.r_array[1]->get_feature_x(0)->look();
	printf("------PLAYER read() PAINTING--------\n");
	flow_test.r_array[1]->get_feature_x(0)->read();
	
	printf("------PLAYER pull() PAINTING--------\n");
	flow_test.r_array[1]->get_feature_x(0)->pull();
	
	printf("------PLAYER pull() PAINTING--------\n");
	flow_test.r_array[1]->get_feature_x(0)->pull();
	
	printf("------PLAYER push() PAINTING--------\n");
	flow_test.r_array[1]->get_feature_x(0)->push();
	
	printf("------PLAYER push() PAINTING--------\n");
	flow_test.r_array[1]->get_feature_x(0)->push();
	printf("------PLAYER push() PAINTING--------\n");
	flow_test.r_array[1]->get_feature_x(0)->push();
	printf("------PLAYER TRIES TO EXIT ROOM EAST --------\n");
	flow_test.exit_room(2);
	printf("------PLAYER LOOKS AT current ROOM --------\n");
	flow_test.look();
	printf("------PLAYER TRIES OIL LAME --------\n");
	flow_test.take(0);
	printf("------PLAYER TRIES TO EXIT ROOM AGAIN --------\n");
	flow_test.exit_room(2);
	
	
	printf("------PLAYER TRIES TO ATTACK Faceless Man-------\n");
	int res = flow_test.attack(0, 4);
	if (res == -1)
	{
		printf("ask user if they want to start a new game; if so, start a new game\n");
	}	
	printf("----give player gilded dagger to show death sequence----");
	flow_test.player1.set_has_objects(4, 1);
	res = flow_test.attack(0, 4);
	if (res == -1)
	{
		printf("ask user if they want to start a new game; if so, start a new game\n");
	}
	printf("-----ELSE IF DOESN'T ATTACK------\n");
	printf("------PLAYER LOOKS AT Faceless Man-------\n");
	flow_test.r_array[3]->get_feature_x(0)->look();
	printf("------PLAYER speak() Faceless Man------\n");
	flow_test.r_array[3]->get_feature_x(0)->speak();
	printf("------PLAYER listen() Faceless Man------\n");
	flow_test.r_array[3]->get_feature_x(0)->listen();
	printf("------PLAYER speak() Faceless Man------\n");
	flow_test.r_array[3]->get_feature_x(0)->speak();
	printf("------PLAYER listen() Faceless Man------\n");
	flow_test.r_array[3]->get_feature_x(0)->listen();
	printf("------PLAYER push() table-----\n");
	flow_test.r_array[3]->get_feature_x(1)->push();
	printf("------PLAYER pull() table-----\n");
	flow_test.r_array[3]->get_feature_x(1)->pull();
	printf("------PLAYER push() table-----\n");
	flow_test.r_array[3]->get_feature_x(1)->push();
	//if you pull the table you go back a step; you unjostle
	printf("------PLAYER push() table AGAIN-----\n");
	flow_test.r_array[3]->get_feature_x(1)->push();
	printf("------PLAYER take diary----\n");
	flow_test.take(1);
*/
	
}