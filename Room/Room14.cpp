//
// Room14.cpp
// Created by Claudia Rodriguez-Schroeder on 1/3/20.

#include "Room14.h"
//#define ROOM14 "Basement"//exit north->crypt:15 south->kicthe:13
Room14::Room14() {
	set_name("\033[0;36mBasement\033[0m");
	set_extra_description("The weight of the house and its secrets seems to be crushing your spirit and your resolve. ");
	set_room_id(13);

	set_feature_x(new Feature27, 0);//lucifer statue
	set_feature_x(new Feature28, 1);//black hole in corner
	
	set_exit_name("Door to \033[0;36mcrypt\033[0m", 0);//north
	set_exit_name("Ladder up to \033[0;36mkitchen\033[0m", 1);//south

	
	string exit_desc0 = "An arcane door lies in the wall to the \033[0;32mnorth\033[0m. ";
	string exit_desc1 = "A ladder up to the \033[0;36mkitchen\033[0m is to the \033[0;32msouth\033[0m. ";

	set_exit_desc(exit_desc0, 0);
	set_exit_desc(exit_desc1, 1);

	set_exit_id(14, 0);//exit north
	set_exit_id(12, 1);//exit south
	
	init_long_short_desc();
	//object set in Game, therefor description initialized in Game	
	set_num_events(1);
}
int Room14::event_one(){
	
	printf("The \033[0;36mcrypt\033[0m door makes the sound of a thousand gears and slowly slides open. ");
	set_event_triggered(0, 1);
	return 4;
}

Room14::~Room14() {
	//printf("Destroying derived class Room14\n");
}
