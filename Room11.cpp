//
// Room11.cpp
// Created by Claudia Rodriguez-Schroeder on 1/3/20.

#include "Room11.h"
//#define ROOM11 "Library"//exit north->attic:10 east->parlor/lounge:5 west->conservatory:12
Room11::Room11() {
	set_name("Library");
	set_extra_description("The comforting crackling of a fire and the smell of books surround you. ");
	set_room_id(10);

	//set_feature_x(new Feature21, 0);//Fire
	//set_feature_x(new Feature22, 1);//Bookshelf
	
	set_exit_name("Ladder to attic", 0);//north
	set_exit_name("Door to parlor", 2);//east
	set_exit_name("Door to conservatory", 3);//west
	
	string exit_desc0 = "A ladder up to the attic is in the north";
	string exit_desc2 = "A door to the parlor is in the east";
	string exit_desc3 = "A door to the consevatory is in the west";
	set_exit_desc(exit_desc0, 0);
	set_exit_desc(exit_desc2, 2);
	set_exit_desc(exit_desc3, 3);
	set_exit_id(9, 0);//exit south
	set_exit_id(4, 2);//exit east
	set_exit_id(11, 3);//exit east
	init_long_short_desc();
	//object set in Game, therefor description initialized in Game	
	
	
}

Room11::~Room11() {
	//printf("Destroying derived class Room11\n");
}