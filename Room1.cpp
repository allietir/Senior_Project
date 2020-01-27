//
// Room1.cpp
// Created by Claudia Rodriguez-Schroeder on 1/3/20.

#include "Room1.h"

Room1::Room1() {
	set_name("Front Garden");
	set_extra_description("There is a general feeling of drearyness and unease in the air.");
	set_room_id(0);

	set_feature_x(new Feature1, 0);
	set_feature_x(new Feature2, 1);
	
	init_long_short_desc();
	//set exits; name, direction
	set_exit_name("Front door", 0);
	string exit_desc = "A large, imposing " + get_exit_name(0) + " in the " + get_exit_dir(0) + ", dark and heavy looking. It appears to be slightly adjar. ";
	set_exit_desc(exit_desc, 0);
	set_exit_id(1, 0);//exit at north goes to Room2

	init_long_short_desc();
	//object set in Game, therefor description initialized in Game
	
}

Room1::~Room1() {
	
}