//
// Feature17.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature17.h"

Feature17::Feature17() {
	set_name("Mirror");
	set_desc("There is a mirror in the bathroom and there is writing on the mirror.\n");
	set_index_id(16);
}
int Feature17::read(){
	func_togg_count_x(READ);
	printf("So thirsty. So hungry. So cold.\n");
	return 4;
	
	
}
Feature17::~Feature17() {
	
}
