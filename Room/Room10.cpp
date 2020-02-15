//
// Room10.cpp
// Created by Claudia Rodriguez-Schroeder on 1/3/20.

#include "Room10.h"
//#define ROOM10 "Attic"//exit south->library:11 east->master bedroom:8
Room10::Room10() {
	set_name("Attic");
	set_extra_description("The sound of coins and the smell of salt assault your senses as you enter the attic.");
	set_room_id(9);

	set_feature_x(new Feature19, 0);//treasure chest
	set_feature_x(new Feature20, 1);//pirate
	
	set_exit_name("Ladder to library", 1);//south
	set_exit_name("Ladder to master bedroom", 2);//east

	string exit_desc1 = "A ladder down to the library is in the south";
	string exit_desc2 = "A ladder down to the master bedroom is in the east";
	set_exit_desc(exit_desc1, 1);
	set_exit_desc(exit_desc2, 2);
	set_exit_id(10, 1);//exit south
	set_exit_id(7, 2);//exit east
	init_long_short_desc();
	set_num_events(2);
	
	//object set in Game, therefor description initialized in Game	
	
}
int Room10::event_one(){
	printf("There porcelin doll seems to whisper things but when you try to listen the whispers fade into nothing.\n");
	set_event_triggered(0, 1);
	return 4;
}
int Room10::event_two(){
	printf("There's a porcelin doll in the chest.\n");
	set_event_triggered(1, 1);
	return 32;
}
Room10::~Room10() {
	//printf("Destroying derived class Room10\n");
}
