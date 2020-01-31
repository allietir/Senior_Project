//
// Object2.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Object2.h"

Object2::Object2() {
	set_name("Diary");
	set_desc("The diary is some type of leather, dark and stained with something. Is it ink or is it blood? ");
	set_index_id(0);
}
string Object2::read(){
	string read_response = "The first page says 'Property of S--' but the rest of the name can't be seen, faded by water damage and time. ";
	func_togg_count_x(0);
	return read_response;
	
	
}
Object2::~Object2() {
	
}
