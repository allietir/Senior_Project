//
// Feature26.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature26.h"

Feature26::Feature26() {
	set_name("Cupboard");
	set_desc("There is a cupboard in this kitchen with a handle on it.");
	set_index_id(25);
}
int Feature26::open(int room_id, int obj_id){
	if (get_times_toggled(OPEN)==0){
		func_togg_count_x(OPEN);
		printf("There doesn't appear to be anything of interest in this cupboard\n");
		set_desc("The open cupboard has nothing of interest inside it\n");
	}
	else{
		printf("The cupboard is already open.\n");
		
	}
	return 4;
	
	
}
Feature26::~Feature26() {
	
}
