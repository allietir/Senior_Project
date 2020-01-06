//
// Room1.cpp
// Created by Claudia Rodriguez-Schroeder on 1/3/20.

#include "Room1.h"

Room1::Room1() {
	//printf("Constructing derived class Room1\n");
	set_name("Room1");
	set_room_id(0);
	set_exit("exit_1");
	Feature f1;
	Feature f2;
	f1.name = "Room1.feature_1";
	f1.description = "Room1.feature_1.description";
	set_feature_1(f1);
	f2.name = "Room1.feature_2";
	f2.description = "Room1.feature_2.description";
	set_feature_2(f2);
	string short_descr = "This is " + get_name() + ".\n" + " YOU SEE " + get_exit() + ".\n YOU SEE " + get_feature_1().description + ".\n YOU SEE " + get_feature_2().description + "\n";
	string long_descr = "LONG DESC: " + short_descr;
	set_short_description(short_descr);
	set_long_description(long_descr);

	
	//printf("Room Name: %s\n", this->get_name().c_str());
	
}

Room1::~Room1() {
	//printf("Destroying derived class Room1\n");
}