//
// Room9.cpp
// Created by Claudia Rodriguez-Schroeder on 1/3/20.

#include "Room9.h"
//#define ROOM9 "Bathroom"//exit south->master bedroom:8 east->child room:6 exit 
Room9::Room9() {
	set_name("Bathroom");
	set_extra_description("The sound of water and weeping, and a sense of anxiety and horror permeates your very bones.");
	set_room_id(8);

	set_feature_x(new Feature17, 0);
	set_feature_x(new Feature18, 1);
	
	set_exit_name("Door to master bedroom", 1);//south
	set_exit_name("Door to nursury", 2);//east

	string exit_desc1 = "The doorway back to the master bedroom is in the south.";
	string exit_desc2 = "The doorway back to the nursuery is in the east.";
	set_exit_desc(exit_desc1, 1);
	set_exit_desc(exit_desc1, 2);
	set_exit_id(7, 1);//exit south
	set_exit_id(5, 2);//exit east
	init_long_short_desc();
	//object set in Game, therefor description initialized in Game	
	set_num_events(1);
}
int Room9::event_one(){
	printf("You fill the chalice with blood.\n");
	return 4;
}
Room9::~Room9() {
	//printf("Destroying derived class Room9\n");
}
