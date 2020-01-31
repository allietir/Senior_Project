//
// Feature13.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature13.h"

Feature13::Feature13() {
	set_name("Feature13");
	set_desc("Feature13 description");
	set_index_id(12);
}
string Feature13::read(){
	string read_response = "The " + get_name() + "'s first name is too faded to read, but the last name says 'Smith'.\n 'Hey', says" + FRIEND_NAME + ". 'Wasn't that your mom's maiden name?'. 'Yeah', you reply, ";
	func_togg_count_x(0);
	
	return read_response;
	
	
}
Feature13::~Feature13() {
	
}
