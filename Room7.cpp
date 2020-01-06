//
// Room7.cpp
// Created by Claudia Rodriguez-Schroeder on 1/3/20.

#include "Room7.h"

Room7::Room7() {
	//printf("Constructing derived class Room7\n");
	set_name("Room7");
	set_room_id(1);
	set_exit("exit_2");
	Feature f1;
	Feature f2;
	f1.name = "Room7.feature_1";
	f1.description = "Room7.feature_1.description";
	set_feature_1(f1);
	f2.name = "Room7.feature_2";
	f2.description = "Room7.feature_2.description";
	set_feature_2(f2);
	string short_descr = "This is " + get_name() + "." + " You see " + get_exit() + ". You see " + get_feature_1().description + " and " + get_feature_2().description;
	string long_descr = "LONG DESC: This is " + get_name() + "." + " You see " + get_exit() + ". You see " + get_feature_1().description + " and " + get_feature_2().description;

	set_short_description(short_descr);
	set_long_description(long_descr);
	

	//printf("Room Name: %s\n", this->get_name().c_str());
	
}

Room7::~Room7() {
	//printf("Destroying derived class Room7\n");
}