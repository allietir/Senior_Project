//
// Room8.cpp
// Created by Claudia Rodriguez-Schroeder on 1/3/20.

#include "Room8.h"
//#define ROOM8 "Master Bedroom"//exit east->upstairs hallway:3 north->bathroom:9 west->attic:10
Room8::Room8() {
	set_name("\033[0;36mMaster Bedroom\033[0m");
	set_extra_description("The smell of blood and death lingers heavily in the air. ");
	set_room_id(7);

	set_feature_x(new Feature15, 0);
	set_feature_x(new Feature16, 1);
	
	
	set_exit_name("Door to bathroom", 0);
	set_exit_name("Door to hallway", 2);
	set_exit_name("Ladder to attic", 3);
	string exit_desc0 = "The doorway to the \033[0;36mbathroom\033[0m is to the \033[0;32mnorth\033[0m.";
	string exit_desc2 = "The doorway back to the \033[0;36mhallway\033[0m is back to the \033[0;32mwest\033[0m.";
	string exit_desc3 = "The ladder to the \033[0;36mattic\033[0m is to the \033[0;36meast\033[0m";
	set_exit_desc(exit_desc0, 0);
	set_exit_desc(exit_desc2, 2);
	set_exit_desc(exit_desc3, 3);
	set_exit_id(8, 0);//exit at north goes to bathroom
	set_exit_id(2, 2);//exit at east goes to upstairs hallway
	set_exit_id(9, 3);//exit at west goes to attc
	
	init_long_short_desc();
	//object set in Game, therefor description initialized in Game	
	set_num_events(1);
	
}
int Room8::event_one(){
	printf("The \033[1;31mvampire\033[0m is free. 'Thank you for helping me regrain my strength. I will locate my family, and our house will be alive again.'");
	set_event_triggered(0, 1);
	return 4;
}
Room8::~Room8() {
	//printf("Destroying derived class Room8\n");
}
