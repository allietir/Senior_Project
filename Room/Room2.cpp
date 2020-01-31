//
// Room2.cpp
// Created by Claudia Rodriguez-Schroeder on 1/3/20.

#include "Room2.h"

Room2::Room2() {
//ON EXIT: friend dissapers from the room
	set_name("Entranceway");
	set_extra_description("The room is dark and damp, simultaneously cloistering yet overwhelmingly large. ");
	set_room_id(1);
	set_feature_x(new Feature3, 0);
	set_feature_x(new Feature4, 1);
	//set exits; name, direction
	set_exit_name("Staircase", 0);//to Upstairs Hallway 3/2
	set_exit_name("Back Door", 1);//to Front Garden 1/0
	set_exit_name("East Hallway", 2);//to Dinign Room 4/3
	set_exit_name("West Hallway", 3);//to Parlor/lounge 5/4
	set_exit_id(2, 0);//room_id, exit_index
	set_exit_id(0, 1);//room_id, exit_index
	set_exit_id(3, 2);//room_id, exit_index 
	set_exit_id(4, 3);//room_id, exit_index
	string exit_desc_0 = "There is a staircase before you, winding up to an eternal unknown. Strangely, a fog seems to be drifting down from the top of the stairs";
	string exit_desc_1 = "Behind you, the back door to the garden shows the path leading out. There is still time to go back. You have the sense that you could leave and the house would forgive you. ";
	string exit_desc_2 = "There is a dark hallway to your left. You can't see a thing. ";
	string exit_desc_3 = "There is another dark hallway to your right. You hear faint music that seems to be coming from there.";
	set_exit_desc(exit_desc_0, 0);
	set_exit_desc(exit_desc_1, 1);
	set_exit_desc(exit_desc_2, 2);
	set_exit_desc(exit_desc_3, 3);
	
	init_long_short_desc();
	//object set in Game, therefor description initialized in Game

}

Room2::~Room2() {
	
}
