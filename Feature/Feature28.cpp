//
// Feature28.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature28.h"

Feature28::Feature28() {
	set_name("Statue");
	set_desc("Feature28 description");
	set_index_id(27);
}
int Feature28::read(){
	string read_response = "The " + get_name() + "'s first name is too faded to read, but the last name says 'Smith'.\n 'Hey', says" + FRIEND_NAME + ". 'Wasn't that your mom's maiden name?'. 'Yeah', you reply, ";
	func_togg_count_x(0);
	
	printf("%s\n", read_response.c_str());
	return 0;
	
	
}
Feature28::~Feature28() {
	
}
