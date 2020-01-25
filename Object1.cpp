//
// Object1.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Object1.h"

Object1::Object1() {
	set_name("Knife");
	string desc = "A sharp silver " + get_name() + " with a worn handle";
	set_desc(desc);
	set_index_id(0);
}
string Object1::read(){
	string read_response = "The " + get_name() + "'s first name is too faded to read, but the last name says 'Smith'.\n 'Hey', says" + FRIEND_NAME + ". 'Wasn't that your mom's maiden name?'. 'Yeah', you reply, ";
	func_togg_count_x(0);
	return read_response;
	
	
}
Object1::~Object1() {
	
}