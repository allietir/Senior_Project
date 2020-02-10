//
// Feature16.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature16.h"

Feature16::Feature16() {
	set_name("Branch");
	set_desc("A branch attached to a tree leading out the window into the front garden");
	set_index_id(15);
}
int Feature16::climb(){
	string climb_response = "You climb down the branch back down into the garden";
	func_togg_count_x(CLIMB);
	
	printf("%s\n", climb_response.c_str());
	return 11;
}
Feature16::~Feature16() {
	
}
