//
// Object5.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Object5.h"

Object5::Object5() {
	set_name("\033[1;35mDagger\033[0m");
	set_desc("The \033[1;35mdagger\033[0m appears impossilby sharp, like it could cut through the very fabric of reality. ");
	set_index_id(4);
}
int Object5::read(){
	string read_response = "Memento mori ";
	func_togg_count_x(0);
	printf("%s", read_response.c_str());
	return 4;
	
	
}
int Object5::use(int current_room){
	if (current_room==BATHROOM){
		return 43;
	}
	else {
		Object::use(current_room);
	}
	return 4;
}
Object5::~Object5() {
	
}
