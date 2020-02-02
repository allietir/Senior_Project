//
// Feature21.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature21.h"

Feature21::Feature21() {
	set_name("Feature21");
	set_desc("Feature21 description");
	set_index_id(20);
}
void Feature21::read(){
	string read_response = "The " + get_name() + "'s first name is too faded to read, but the last name says 'Smith'.\n 'Hey', says" + FRIEND_NAME + ". 'Wasn't that your mom's maiden name?'. 'Yeah', you reply, ";
	func_togg_count_x(0);
	
	printf("%s\n", read_response.c_str());
	
	
}
Feature21::~Feature21() {
	
}
