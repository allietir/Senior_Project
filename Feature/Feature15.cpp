//
// Feature15.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature15.h"

Feature15::Feature15() {
	set_name("Vampire");
	set_desc("A sleeping vampire that doesn't seem to adhere to the rule of sleeping in a coffin.\n");
	set_index_id(14);
}
int Feature15::read(){
	string read_response = "The " + get_name() + "'s first name is too faded to read, but the last name says 'Smith'.\n 'Hey', says" + FRIEND_NAME + ". 'Wasn't that your mom's maiden name?'. 'Yeah', you reply, ";
	func_togg_count_x(0);
	
	printf("%s\n", read_response.c_str());
	return 0;
	
	
}
Feature15::~Feature15() {
	
}
