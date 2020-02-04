//
// Feature12.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature12.h"

Feature12::Feature12() {
	set_name("Dollhouse");
	set_desc("Feature12 description");
	set_index_id(11);
}
int Feature12::read(){
	string read_response = "The " + get_name() + "'s first name is too faded to read, but the last name says 'Smith'.\n 'Hey', says" + FRIEND_NAME + ". 'Wasn't that your mom's maiden name?'. 'Yeah', you reply, ";
	func_togg_count_x(0);
	
	printf("%s\n", read_response.c_str());
	return 0;
	
	
}
Feature12::~Feature12() {
	
}
