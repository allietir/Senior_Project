//
// Room15.cpp
// Created by Claudia Rodriguez-Schroeder on 1/3/20.

#include "Room15.h"
//#define ROOM15 "Crypt" //exit south->basement:14
Room15::Room15() {
	set_name("Crypt");
	set_extra_description("The final confrontation is at last upon you. Are you ready? ");
	set_room_id(14);

	set_feature_x(new Feature29, 0);//
	set_feature_x(new Feature30, 1);//
	
	set_exit_name("Basement exit", 0);//north


	
	string exit_desc1 = "The exit back to the basement in the south";


	set_exit_desc(exit_desc1, 1);



	set_exit_id(13, 1);//exit south
	
	init_long_short_desc();
	//object set in Game, therefor description initialized in Game
	
}
int event_one(){
	printf("You trap the demon in the locket\n");
	return 0;
}
Room15::~Room15() {
	//printf("Destroying derived class Room15\n");
}
