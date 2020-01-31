//
// Feature8.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature8.h"

Feature8::Feature8() {
	set_name("Feature8");
	set_desc("Feature8 description");
	set_index_id(7);
}
string Feature8::read(){
	string read_response = "The " + get_name() + "'s first name is too faded to read, but the last name says 'Smith'.\n 'Hey', says" + FRIEND_NAME + ". 'Wasn't that your mom's maiden name?'. 'Yeah', you reply, ";
	func_togg_count_x(0);
	
	return read_response;
	
	
}
Feature8::~Feature8() {
	
}
