//
// Room12.cpp
// Created by Claudia Rodriguez-Schroeder on 1/3/20.

#include "Room12.h"
//#define ROOM12 "Conservatory"//exit south->front garden:1 (SECRET) east->library:11
Room12::Room12() {
	set_name("\033[0;36mConservatory\033[0m");
	set_extra_description("The smell of life and earth, the sound of water, and the feeling that something important is coming; all these sensations are perceived by you. ");
	set_room_id(11);

	set_feature_x(new Feature23, 0);//Fountain
	set_feature_x(new Feature24, 1);//Gaurdina
	//OBJECTS: holy water
	
	set_exit_name("Door to \033[0;36mfront garden\033[0m", 1);//SOUTH
	set_exit_name("Door to \033[0;36mlibrary\033[0m", 2);//west

	
	string exit_desc1 = "A door out ot the \033[0;36mfront garden\033[0m is to the \033[0;32msouth\033[0m. ";
	string exit_desc2 = "A door to the \033[0;36mlibrary\033[0m is to the \033[0;32mwest\033[0m. ";

	set_exit_desc(exit_desc1, 1);
	set_exit_desc(exit_desc2, 2);

	set_exit_id(0, 1);//exit south
	set_exit_id(10, 2);//exit west
	
	init_long_short_desc();
	//object set in Game, therefor description initialized in Game	
	set_num_events(2);
	
}
int Room12::event_one(){
	printf("The \033[1;35mchalice\033[0m glows briefly and feels warm in your hands. This is important, you feel. ");
	set_event_triggered(0, 1);
	return 4;
}
int Room12::event_two(){
	printf("The \033[1;35mchalice\033[0m is filled with holy water. ");
	set_event_triggered(1, 1);
	return 4;

}

Room12::~Room12() {
	//printf("Destroying derived class Room12\n");
}
