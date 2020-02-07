//
// Feature9.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature9.h"

Feature9::Feature9() {
	set_name("Piano");
	set_desc("Feature9 description");
	set_index_id(8);
}
int Feature9::read(){
	string read_response = "The " + get_name() + "'s first name is too faded to read, but the last name says 'Smith'.\n 'Hey', says" + FRIEND_NAME + ". 'Wasn't that your mom's maiden name?'. 'Yeah', you reply, ";
	func_togg_count_x(0);
	
	printf("%s\n", read_response.c_str());
	return 0;
	
	
}
Feature9::~Feature9() {
	
}
