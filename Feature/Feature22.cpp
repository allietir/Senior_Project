//
// Feature22.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature22.h"

Feature22::Feature22() {
	set_name("Feature22");
	set_desc("Feature22 description");
	set_index_id(21);
}
string Feature22::read(){
	string read_response = "The " + get_name() + "'s first name is too faded to read, but the last name says 'Smith'.\n 'Hey', says" + FRIEND_NAME + ". 'Wasn't that your mom's maiden name?'. 'Yeah', you reply, ";
	func_togg_count_x(0);
	
	return read_response;
	
	
}
Feature22::~Feature22() {
	
}
