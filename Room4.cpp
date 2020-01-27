//
// Room4.cpp
// Created by Claudia Rodriguez-Schroeder on 1/3/20.

#include "Room4.h"

Room4::Room4() {
	set_name("Dining Room");
	set_extra_description("The room is uncomfortably warm and the smell of cooking flesh wafts in the air, of fresh blood. ");
	set_room_id(3);

	//set_feature_x(new Feature7, 0);
	//set_feature_x(new Feature8, 1);
	

	//set exits; name, direction
	set_exit_name("Kitchen Door", 2);//kitchen, east
	set_exit_name("West hallway", 3);//entranceway, west

	string exit_desc_2 = "A dirty kitchen door with burn and smoke stains upon it.";
	string exit_desc_3 = "A dark hallway you cannot see past.";
	set_exit_desc(exit_desc_2, 2);
	set_exit_desc(exit_desc_3, 3);
	set_exit_id(12, 2);//exit at east goes to Room13
	set_exit_id(1, 3);//exit at east goes to Room13
	init_long_short_desc();
	//object set in Game, therefor description initialized in Game	
}

Room4::~Room4() {
	//printf("Destroying derived class Room4\n");
}