//
// Feature1.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature1.h"

Feature1::Feature1() {
	set_name("Gravestone");
	set_desc("A gray, dreary looking Gravestone with vines covering the name of the deceased. ");
	set_index_id(0);
}
string Feature1::read(){
	string read_response = "The " + get_name() + "'s first name is too faded to read, but the last name says 'Smith'.\n 'Hey', says" + FRIEND_NAME + ". 'Wasn't that your mom's maiden name?'. 'Yeah', you reply, ";
	func_togg_count_x(0);
	
	return read_response;
	
	
}
Feature1::~Feature1() {
	
}