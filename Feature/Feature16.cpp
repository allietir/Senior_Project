//
// Feature16.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature16.h"

Feature16::Feature16() {
	set_name("Blood");
	set_desc("A red light bathing the room in an otherworldy glow");
	set_index_id(15);
}
int Feature16::read(){
	string read_response = "The " + get_name() + "'s first name is too faded to read, but the last name says 'Smith'.\n 'Hey', says" + FRIEND_NAME + ". 'Wasn't that your mom's maiden name?'. 'Yeah', you reply, ";
	func_togg_count_x(0);
	
	printf("%s\n", read_response.c_str());
	return 0;
	
	
}
Feature16::~Feature16() {
	
}
