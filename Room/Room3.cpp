//
// Room3.cpp
// Created by Claudia Rodriguez-Schroeder on 1/3/20.

#include "Room3.h"

Room3::Room3() {
	
	set_name("Upstairs Hallways");
	set_extra_description("The hallway is so dark and cold, it seems to go on forever. Your teeth start chattering and you pull yourself closer. ");//FEATURE mirror at end of hall
	set_room_id(2);
	set_feature_x(new Feature5, 0);
	set_feature_x(new Feature6, 1);
	init_long_short_desc();
	//set exits; name, direction
	set_exit_name("Mirrored door", 0);//to chils bedroom room 6/5
	set_exit_name("Staricase down", 1);//to Entranceway room 2/1
	set_exit_name("Left doorway", 2);//to guest bedroom, room 7/6
	set_exit_name("Right doorway", 3);//to master bedroom, room 8/7
	set_exit_id(5, 0);//
	set_exit_id(1, 1);//
	set_exit_id(6, 2);//
	set_exit_id(7, 3);//
	string exit_desc_0 = "At the end of the hallway, you see a mirrored door.";
	string exit_desc_1 = "Behind you is the exit back to the entranceway";
	string exit_desc_2 = "At the left side of the hallway, you see a door";
	string exit_desc_3 = "At the west side of the hallway, you see a second door";
	set_exit_desc(exit_desc_0, 0);
	set_exit_desc(exit_desc_1, 1);
	set_exit_desc(exit_desc_2, 2);
	set_exit_desc(exit_desc_3, 3);
	
	init_long_short_desc();
	set_num_events(1);

}
int Room3::event_one(){
	printf("The clock strikes midnight:\n ");
	printf("You find yourself upstairs. \n");
	get_feature_x(0)->func_togg_count_x(OPEN);
	printf("You open the grandfather clock door and you see a staircase down. Looks like you'll need to climb quite a bit to get down there... but where does it go?");
	string desc = "The grandfather clock is open and a staircase down is revealed.\n" + get_feature_x(0)->get_time_str();
	get_feature_x(0)->set_desc(desc);
	set_event_triggered(0, 1);
	return 4;
	
	
}

Room3::~Room3() {
	//printf("Destroying derived class Room3\n");
}