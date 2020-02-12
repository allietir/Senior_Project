//
// Room6.cpp
// Created by Claudia Rodriguez-Schroeder on 1/3/20.

#include "Room6.h"
//exit south->upstrais hallway:3  west->bathroom:9
Room6::Room6() {
	set_name("Nursury");
	set_extra_description("The room is painted in colors that were once bright, are cracked and faded by time.");
	set_room_id(5);

	set_feature_x(new Feature11, 0);
	set_feature_x(new Feature12, 1);
	
	set_exit_name("Door to hallway", 1);
	set_exit_name("Doorway to bathroom", 3);
	string exit_desc1 = "There's a mirrored door back to the hallway, strange and fogged. ";
	string exit_dex3 = "There's a dooway to what looks like a bathroom. You can hear water running";
	set_exit_desc(exit_desc1, 1);
	set_exit_desc(exit_desc1, 3);
	set_exit_id(2, 1);//exit at south goes to upstairs hallway
	set_exit_id(8, 3);//exit at south goes to upstairs hallway
	
	init_long_short_desc();
	//object set in Game, therefor description initialized in Game	
}
//when you take the locket
int Room6::event_one(){
	printf("The locket is hard and small and silver in your hand. There is something comforting and yet powerful about it.");
	return 4;
}
//locket made avaibale to you
int Room6::event_two(){
	printf("The little girl places the locket before you. 'Here. You should take this. You will need it.\n'");
	return 31;
}
Room6::~Room6() {
	//printf("Destroying derived class Room6\n");
}
