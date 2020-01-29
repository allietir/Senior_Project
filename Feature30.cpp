//
// Feature30.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature30.h"

Feature30::Feature30() {
	set_name("Feature30");
	set_desc("Feature30 description");
	set_index_id(29);
}
string Feature30::read(){
	string read_response = "The " + get_name() + "'s first name is too faded to read, but the last name says 'Smith'.\n 'Hey', says" + FRIEND_NAME + ". 'Wasn't that your mom's maiden name?'. 'Yeah', you reply, ";
	func_togg_count_x(0);
	
	return read_response;
	
	
}
Feature30::~Feature30() {
	
}
