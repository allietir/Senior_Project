//
// Room15.cpp
// Created by Claudia Rodriguez-Schroeder on 1/3/20.

#include "Room15.h"
//#define ROOM15 "Crypt" //exit south->basement:14
Room15::Room15() {
	set_name("\033[0;36mCrypt\033[0m");
	set_extra_description("The final confrontation is at last upon you. Are you ready? ");
	set_room_id(14);

	set_feature_x(new Feature29, 0);//
	set_feature_x(new Feature30, 1);//
	
	set_exit_name("\033[0;36mBasement\033[0m exit", 0);//north


	
	string exit_desc1 = "The exit back to the \033[0;36mbasement\033[0m in the \033[0;32msouth\033[0m";


	set_exit_desc(exit_desc1, 1);



	set_exit_id(13, 1);//exit south
	
	init_long_short_desc();
	//object set in Game, therefor description initialized in Game
	set_num_events(1);
	
}
int Room15::event_one(){
	printf("You trap the \033[1;31mdemon\033[0m in the \033[1;35mlocket\033[0m\n");
	//trigger game event 4
	set_event_triggered(0, 1);
	return 33;
}
Room15::~Room15() {
	//printf("Destroying derived class Room15\n");
}
