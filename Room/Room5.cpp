//
// Room5.cpp
// Created by Claudia Rodriguez-Schroeder on 1/3/20.

#include "Room5.h"

Room5::Room5() {
	set_name("\033[0;36mParlor\033[0m");
	set_extra_description("You think you can hear music, but you don't know where it is coming from. You strain to listen. The music is there, but not there. ");
	set_room_id(4);

	set_feature_x(new Feature9, 0);
	set_feature_x(new Feature10, 1);
	

	//set exits; name, direction
	set_exit_name("Hall to \033[0;36mentranceway\033[0m", 2);
	set_exit_name("\033[0;36mLibrary\033[0m Door", 3);

	string exit_desc_2 = "A dark hallway with a sinister feel to the \033[0;32mwest\033[0m. ";
	string exit_desc_3 = "A heavy door to the \033[0;32meast\033[0m; you hear the crackling of a fire beyond it. ";
	set_exit_desc(exit_desc_2, 2);
	set_exit_desc(exit_desc_3, 3);
	set_exit_id(1, 2);//exit at east goes to Room1
	set_exit_id(10, 3);//exit at east goes to Room11
	init_long_short_desc();
	//object set in Game, therefor description initialized in Game	
	set_num_events(3);
}
int Room5::event_one()
{
	get_feature_x(1)->set_desc("The woman is in the painting. Her eyes open and she smiles at you.\n");
	set_event_triggered(0, 1);
	return 4;
		
}
int Room5::event_two(){
	printf("You hope the woman finds her family.\n");
	set_event_triggered(1, 1);
	return 4;
}

int Room5::event_three(){
	printf("You ascend the staircase.\n");
	set_event_triggered(2, 1);
	return LIBRARY+10;
}
Room5::~Room5() {
	//printf("Destroying derived class Room5\n");
}
