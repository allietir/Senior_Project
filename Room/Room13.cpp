//
// Room13.cpp
// Created by Claudia Rodriguez-Schroeder on 1/3/20.

#include "Room13.h"
//#define ROOM13 "Kitchen"//exit north->basement:14 west->dining room:4
Room13::Room13() {
	set_name("Kitchen");
	set_extra_description("The smell of apple pie wafts pleasently under your nose, but you don't see any pie. However, as your eyes adjust from the dark, you smell an undertone of rot and decay. ");
	set_room_id(12);

	set_feature_x(new Feature25, 0);//stovetop
	set_feature_x(new Feature26, 1);//cupboard
	
	
	set_exit_name("Trapdoor to basement", 0);//SOUTH
	set_exit_name("Door to dining room", 2);//east

	
	string exit_desc0 = "A trapdoor to the basement is to the north";
	string exit_desc3 = "A door to the dining room is to the west";

	set_exit_desc(exit_desc0, 0);
	set_exit_desc(exit_desc3, 3);

	set_exit_id(13, 0);//exit north
	set_exit_id(3, 3);//exit west
	
	init_long_short_desc();
	//object set in Game, therefor description initialized in Game	
	
}

Room13::~Room13() {
	//printf("Destroying derived class Room13\n");
}
