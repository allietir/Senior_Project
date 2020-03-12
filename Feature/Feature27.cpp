//
// Feature27.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature27.h"

Feature27::Feature27() {
	set_name("\033[1;31mPedestal\033[0m");
	set_desc("There's a Greek \033[1;31mpedestal\033[0m by the \033[1;31mstatue\033[0m. Though short, it looks like a pillar that could hold a temple to the gods. ");
	set_index_id(26);
}
int Feature27::use(int obj_id){
	if ((obj_id == CHALICE)&&(get_times_toggled(USE)==0)){
		printf("You place the silver \033[1;35mchalice\033[0m onto the \033[1;31mpedestal\033[0m. ");
		func_togg_count_x(USE);
		//triggers event one.
		return 0;
	}
	if (obj_id==-1){
		printf("You may need to use something. ");
		return 4;
	}
	else
	{
		printf("Hmm, nothing happens. Looks like you may need to use a different object. ");
		return 4;
	}
	return 4;
	
}
Feature27::~Feature27() {
	
}
