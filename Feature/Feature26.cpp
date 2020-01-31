//
// Feature26.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature26.h"

Feature26::Feature26() {
	set_name("Feature26");
	set_desc("Feature26 description");
	set_index_id(25);
}
string Feature26::read(){
	string read_response = "The " + get_name() + "'s first name is too faded to read, but the last name says 'Smith'.\n 'Hey', says" + FRIEND_NAME + ". 'Wasn't that your mom's maiden name?'. 'Yeah', you reply, ";
	func_togg_count_x(0);
	
	return read_response;
	
	
}
Feature26::~Feature26() {
	
}
