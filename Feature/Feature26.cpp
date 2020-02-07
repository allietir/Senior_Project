//
// Feature26.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature26.h"

Feature26::Feature26() {
	set_name("Cupboard");
	set_desc("Feature26 description");
	set_index_id(25);
}
int Feature26::read(){
	string read_response = "The " + get_name() + "'s first name is too faded to read, but the last name says 'Smith'.\n 'Hey', says" + FRIEND_NAME + ". 'Wasn't that your mom's maiden name?'. 'Yeah', you reply, ";
	func_togg_count_x(0);
	
	printf("%s\n", read_response.c_str());
	return 0;
	
	
}
Feature26::~Feature26() {
	
}
