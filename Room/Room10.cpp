//
// Room10.cpp
// Created by Claudia Rodriguez-Schroeder on 1/3/20.

#include "Room10.h"
//#define ROOM10 "Attic"//exit south->library:11 east->master bedroom:8
Room10::Room10() {
	set_name("\033[0;36mAttic\033[0m");
	set_extra_description("The sound of coins and the smell of salt assault your senses as you enter the attic. ");
	set_room_id(9);

	set_feature_x(new Feature19, 0);//treasure chest
	set_feature_x(new Feature20, 1);//pirate
	
	set_exit_name("Ladder to \033[0;36mlibrary\033[0m", 1);//south
	set_exit_name("Ladder to \033[0;36mmaster bedroom\033[0m", 2);//west

	string exit_desc1 = "A ladder down to the \033[0;36mlibrary\033[0m is to the \033[0;32msouth\033[0m. ";
	string exit_desc2 = "A ladder down to the \033[0;36mmaster bedroom\033[0m is to the \033[0;32mwest\033[0m. ";
	set_exit_desc(exit_desc1, 1);
	set_exit_desc(exit_desc2, 2);
	set_exit_id(10, 1);//exit south
	set_exit_id(7, 2);//exit west
	init_long_short_desc();
	set_num_events(2);
	
	//object set in Game, therefor description initialized in Game	
	
}
int Room10::event_one(){
	printf("The porcelin \033[1;35mdoll\033[0m seems to whisper things but when you try to listen the whispers fade into nothing. ");
	set_event_triggered(0, 1);
	return 4;
}
int Room10::event_two(){
	printf("There is a porcelin \033[1;35mdoll\033[0m in the \033[1;31mchest\033[0m. ");
	set_event_triggered(1, 1);
	return 32;
}
Room10::~Room10() {
	//printf("Destroying derived class Room10\n");
}
