//
// Knife.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Knife.h"

Knife::Knife() {
	set_name("Knife");
	set_desc("A sharp silver knife with a worn handle. ");
	set_index_id(0);
}
string Knife::read(){
	string read_response = "The " + get_name() + "'s first name is too faded to read, but the last name says 'Smith'.\n 'Hey', says" + FRIEND_NAME + ". 'Wasn't that your mom's maiden name?'. 'Yeah', you reply, ";
	func_togg_count_x(0);
	return read_response;
	
	
}
Knife::~Knife() {
	
}