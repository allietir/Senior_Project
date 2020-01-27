//
// Room7.cpp
// Created by Claudia Rodriguez-Schroeder on 1/3/20.

#include "Room7.h"
//exit west->upstaris hallway:3

Room7::Room7() {
	set_name("Guest Bedroom");
	set_extra_description("You feel a heavy sadness; the grief of loss, the pain of lonliness");
	set_room_id(6);

	//set_feature_x(new Feature13, 0);
	//set_feature_x(new Feature14, 1);
	
	set_exit_name("Door to hallway", 3);

	string exit_desc3 = "The doorway back to the hallway is back to the west.";
	set_exit_desc(exit_desc3, 3);

	set_exit_id(2, 3);//exit at west goes to upstairs hallway
	
	init_long_short_desc();
	//object set in Game, therefor description initialized in Game	
	
}

Room7::~Room7() {
	//printf("Destroying derived class Room7\n");
}