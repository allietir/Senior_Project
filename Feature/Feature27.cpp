//
// Feature27.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature27.h"

Feature27::Feature27() {
	set_name("Pedestal");
	set_desc("There's a pedestal by the statue, made with a similar greek aesthetic in mind. It looks like a pillar that could have held up a temple to Zeus or Athena. \n");
	set_index_id(26);
}
int Feature27::use(int obj_id){
	if (obj_id == CHALICE){
		printf("You place the silver chalice onto the pedestal.\n");
		func_togg_count_x(USE);
		//triggers event one.
		return 0;
	}
	else
	{
		printf("hmm, nothing happens. Looks like you may need to use a differnet object.\n");
		return 4;
	}
	return 4;
	
}
Feature27::~Feature27() {
	
}
