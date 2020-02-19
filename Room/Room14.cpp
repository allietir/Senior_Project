//
// Room14.cpp
// Created by Claudia Rodriguez-Schroeder on 1/3/20.

#include "Room14.h"
//#define ROOM14 "Basement"//exit north->crypt:15 south->kicthe:13
Room14::Room14() {
	set_name("Basement");
	set_extra_description("The weight of the house and its secrets seems to be crushing your spirit and your resolve. ");
	set_room_id(13);

	set_feature_x(new Feature27, 0);//lucifer statue
	set_feature_x(new Feature28, 1);//black hole in corner
	
	set_exit_name("Door to crypt", 0);//north
	set_exit_name("Ladder up to kitchen", 1);//south

	
	string exit_desc0 = "A door to the crypt is in the north";
	string exit_desc1 = "A ladder up to the kitchen is to the south";

	set_exit_desc(exit_desc0, 0);
	set_exit_desc(exit_desc1, 1);

	set_exit_id(14, 0);//exit north
	set_exit_id(12, 1);//exit south
	
	init_long_short_desc();
	//object set in Game, therefor description initialized in Game	
	set_num_events(1);
}
int Room14::event_one(){
	
	printf("The crypt door make the sound of a thousand gears opening and slides open.\n");
	return 4;
}

Room14::~Room14() {
	//printf("Destroying derived class Room14\n");
}
