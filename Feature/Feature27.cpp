//
// Feature27.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature27.h"

Feature27::Feature27() {
	set_name("\033[1;31mPedestal\033[0m");
	set_desc("There's a \033[1;31mpedestal\033[0m by the \033[1;31mstatue\033[0m, made with a similar greek aesthetic in mind. It looks like a pillar that could have held up a temple to Zeus or Athena. ");
	set_index_id(26);
}
int Feature27::use(int obj_id){
	if (obj_id == CHALICE){
		printf("You place the silver \033[1;35mchalice\033[0m onto the \033[1;31mpedestal\033[0m.");
		func_togg_count_x(USE);
		//triggers event one.
		return 0;
	}
	else
	{
		printf("hmm, nothing happens. Looks like you may need to use a differnet object.");
		return 4;
	}
	return 4;
	
}
Feature27::~Feature27() {
	
}
