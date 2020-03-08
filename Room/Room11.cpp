//
// Room11.cpp
// Created by Claudia Rodriguez-Schroeder on 1/3/20.

#include "Room11.h"
//#define ROOM11 "Library"//exit north->attic:10 east->parlor/lounge:5 west->conservatory:12
Room11::Room11() {
	set_name("\033[0;36mLibrary\033[0m");
	set_extra_description("The comforting crackling of a fire and the smell of books surround you. ");
	set_room_id(10);

	set_feature_x(new Feature21, 0);//Fire
	set_feature_x(new Feature22, 1);//Bookshelf
	
	set_exit_name("Ladder to \033[0;36mattic\033[0m", 0);//north
	set_exit_name("Door to \033[0;36mparlor\033[0m", 2);//west
	set_exit_name("Door to \033[0;36mconservatory\033[0m", 3);//east
	
	string exit_desc0 = "A ladder up to the \033[0;36mattic\033[0m is in the \033[0;32mnorth\033[0m";
	string exit_desc2 = "A door to the \033[0;36mparlor\033[0m is in the \033[0;32mwest\033[0m";
	string exit_desc3 = "A door to the \033[0;36mconsevatory\033[0m is in the \033[0;32mweast\033[0m";
	set_exit_desc(exit_desc0, 0);
	set_exit_desc(exit_desc2, 2);
	set_exit_desc(exit_desc3, 3);
	set_exit_id(9, 0);//exit south
	set_exit_id(4, 2);//exit west
	set_exit_id(11, 3);//exit east
	init_long_short_desc();
	//object set in Game, therefor description initialized in Game	
	set_num_events(1);
	
}
int Room11::event_one()
{
	printf("The \033[1;35mkey\033[0m swirls briefly in your hand as if by magic, and points up before stilling in your hand.");
	set_event_triggered(0, 1);
	return 4;
}
Room11::~Room11() {
	//printf("Destroying derived class Room11\n");
}
