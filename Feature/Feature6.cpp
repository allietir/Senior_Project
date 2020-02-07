//
// Feature6.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature6.h"

Feature6::Feature6() {
	set_name("Carpet");
	set_desc("Feature6 description");
	set_index_id(5);
}
int Feature6::read(){
	string read_response = "The " + get_name() + "'s first name is too faded to read, but the last name says 'Smith'.\n 'Hey', says" + FRIEND_NAME + ". 'Wasn't that your mom's maiden name?'. 'Yeah', you reply, ";
	func_togg_count_x(0);
	
	printf("%s\n", read_response.c_str());
	return 0;
	
	
}
Feature6::~Feature6() {
	
}
