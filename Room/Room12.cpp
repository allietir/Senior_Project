//
// Room12.cpp
// Created by Claudia Rodriguez-Schroeder on 1/3/20.

#include "Room12.h"
//#define ROOM12 "Conservatory"//exit south->front garden:1 (SECRET) east->library:11
Room12::Room12() {
	set_name("Conservatory");
	set_extra_description("The smell of life and earth, the sound of water, and the feeling that something important is coming; all these sensations are perceived by you.");
	set_room_id(11);

	set_feature_x(new Feature23, 0);//Fountain
	set_feature_x(new Feature24, 1);//Gaurdina
	//OBJECTS: holy water
	
	set_exit_name("Door to front garden", 1);//SOUTH
	set_exit_name("Door to library", 2);//east

	
	string exit_desc1 = "A door out ot the garden is to the south.";
	string exit_desc2 = "A door to the library is to the east";

	set_exit_desc(exit_desc1, 1);
	set_exit_desc(exit_desc2, 2);

	set_exit_id(0, 1);//exit south
	set_exit_id(10, 2);//exit east
	
	init_long_short_desc();
	//object set in Game, therefor description initialized in Game	
	set_num_events(2);
	
}
int Room12::event_one(){
	printf("The chalice glows briefly and feels warm in your hands. This is important, you feel.\n");
	set_event_triggered(0, 1);
	return 4;
}
int Room12::event_two(){
	printf("The chalice is filled with holy water\n");
	set_event_triggered(1, 1);
	return 4;

}

Room12::~Room12() {
	//printf("Destroying derived class Room12\n");
}
