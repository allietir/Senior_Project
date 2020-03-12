//
// Feature16.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature16.h"

Feature16::Feature16() {
	set_name("\033[1;31mBranch\033[0m");
	set_desc("A \033[1;31mbranch\033[0m attached to a tree leading out the window into the front garden. ");
	set_desc_no_obj(get_desc());
	set_index_id(15);
}
int Feature16::climb(){
	string climb_response = "You climb down the \033[1;31mbranch\033[0m back down into the garden. ";
	func_togg_count_x(CLIMB);
	
	printf("%s\n", climb_response.c_str());
	return 10;
}
Feature16::~Feature16() {
	
}
