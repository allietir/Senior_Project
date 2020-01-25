//
// Room2.cpp
// Created by Claudia Rodriguez-Schroeder on 1/3/20.

#include "Room2.h"

Room2::Room2() {

	set_name("Entranceway");
	set_extra_description("The room is dark and damp, simultaneously cloistering yet overwhelmingly large. ");
	set_room_id(1);
	//set_feature_x(feature_1, 0);
	init_long_short_desc();
	//set exits; name, direction
	set_exit_name("Upstairs hallway", 0);
	set_exit_name("Front Garden", 1);
	set_exit_name("Dining Room", 2);
	set_exit_name("Parlor", 3);
	
	init_long_short_desc();
	//object set in Game, therefor description initialized in Game

}

Room2::~Room2() {
	
}