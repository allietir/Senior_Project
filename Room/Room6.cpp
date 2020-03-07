//
// Room6.cpp
// Created by Claudia Rodriguez-Schroeder on 1/3/20.

#include "Room6.h"
//exit south->upstrais hallway:3  west->bathroom:9
Room6::Room6() {
	set_name("\033[0;36mNursery\033[0;36m");
	set_extra_description("The room is painted in colors that were once bright, are cracked and faded by time.");
	set_room_id(5);

	set_feature_x(new Feature11, 0);
	set_feature_x(new Feature12, 1);
	
	set_exit_name("Door to \033[0;36mhallway\033[0m", 1);
	set_exit_name("Doorway to \033[0;36mbathroom\033[0m", 3);
	string exit_desc1 = "There's a mirrored door on the \033[0;32msouth\033[0m to the \033[0;36mhallway\033[0m, strange and fogged. ";
	string exit_desc3 = "There's a dooway to what looks like a \033[0;36mbathroom\033[0m towards the \033[0;32meast\033[0m. You can hear water running";
	set_exit_desc(exit_desc1, 1);
	set_exit_desc(exit_desc3, 3);
	set_exit_id(2, 1);//exit at south goes to upstairs hallway
	set_exit_id(8, 3);//exit at south goes to upstairs hallway
	
	init_long_short_desc();
	set_num_events(2);
	//object set in Game, therefor description initialized in Game	
}
//when you take the locket
int Room6::event_one(){
	printf("The \033[1;35mlocket\033[0m is hard and small and silver in your hand. There is something comforting and yet powerful about it. The \033[1;31mchild\033[0m smiles and speaks precociously. 'Thank you. I will go find my family.'\n");
	set_event_triggered(0, 1);
	//triggers nothing
	return 4;
}
//locket made avaibale to you
int Room6::event_two(){
	printf("The little \033[1;31mgirl\033[0m places the \033[1;35mlocket\033[0m before you. 'Here. You should take this.'\n");
	set_event_triggered(1, 1);
	//griggers unlcok
	return 31;
}


Room6::~Room6() {
	//printf("Destroying derived class Room6\n");
}
