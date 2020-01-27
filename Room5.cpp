//
// Room5.cpp
// Created by Claudia Rodriguez-Schroeder on 1/3/20.

#include "Room5.h"

Room5::Room5() {
	set_name("Parlor");
	set_extra_description("You feel like you can hear music, but can't quite place it; you strain to listen, but fail to understand.");
	set_room_id(4);

	//set_feature_x(new Feature9, 0);
	//set_feature_x(new Feature10, 1);
	

	//set exits; name, direction
	set_exit_name("East Hallway", 2);// east
	set_exit_name("Library Door", 3);//e, west

	string exit_desc_2 = "A dark hallway with a sinister feel.";
	string exit_desc_3 = "A heavy door; you can hear the crackling of a fire byond it.";
	set_exit_desc(exit_desc_2, 2);
	set_exit_desc(exit_desc_3, 3);
	set_exit_id(1, 2);//exit at east goes to Room1
	set_exit_id(11, 3);//exit at east goes to Room11
	init_long_short_desc();
	//object set in Game, therefor description initialized in Game	
}

Room5::~Room5() {
	//printf("Destroying derived class Room5\n");
}