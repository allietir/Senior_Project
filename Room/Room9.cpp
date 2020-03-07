//
// Room9.cpp
// Created by Claudia Rodriguez-Schroeder on 1/3/20.

#include "Room9.h" 
//#define ROOM9 "Bathroom"//exit south->master bedroom:8 east->child room:6 exit 
Room9::Room9() {
	set_name("\033[0;36mBathroom\033[0m");
	set_extra_description("The sound of water and weeping, and a sense of anxiety and horror permeates your very bones.");
	set_room_id(8);

	set_feature_x(new Feature17, 0);//mirror
	set_feature_x(new Feature18, 1);//sink
	
	set_exit_name("Door to \033[0;36mmaster bedroom\033[0m", 1);//south
	set_exit_name("Door to \033[0;36mnursery\033[0m", 2);//east

	string exit_desc1 = "The doorway back to the \033[0;36mmaster bedroom\033[0m is in the \033[0;32msouth\033[0m.";
	string exit_desc2 = "The doorway back to the \033[0;36mnursery\033[0m is in the \033[0;36meast\033[0m.";
	set_exit_desc(exit_desc1, 1);
	set_exit_desc(exit_desc1, 2);
	set_exit_id(7, 1);//exit south
	set_exit_id(5, 2);//exit east
	init_long_short_desc();
	//object set in Game, therefor description initialized in Game	
	set_num_events(1);
}
int Room9::event_one(){
	printf("You fill the \033[1;35mchalice\033[0m with blood.\n");
	set_event_triggered(0, 1);
	return 4;
}
Room9::~Room9() {
	//printf("Destroying derived class Room9\n");
}
