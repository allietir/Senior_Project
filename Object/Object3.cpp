//
// Object3.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Object3.h"

Object3::Object3() {
	set_name("Object3");
	set_desc("Object3 description");
	set_index_id(2);
}
void Object3::read(){
	string read_response = "The " + get_name() + "'s first name is too faded to read, but the last name says 'Smith'.\n 'Hey', says" + FRIEND_NAME + ". 'Wasn't that your mom's maiden name?'. 'Yeah', you reply, ";
	func_togg_count_x(0);
	printf("%s\n", read_response.c_str());
}
Object3::~Object3() {
	
}
