//
// Feature26.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature26.h"

Feature26::Feature26() {
	set_name("\033[1;31mCupboard\033[0m");
	set_desc("There is a \033[1;31mcupboard\033[0m in this kitchen with a handle on it.\n");
	set_desc_no_obj("There is a \033[1;31mcupboard\033[0m in this kitchen with a handle on it.\n");
	set_index_id(25);
}
int Feature26::open(int room_id, int obj_id){
	if (get_times_toggled(OPEN)==0){
		func_togg_count_x(OPEN);
		printf("There doesn't appear to be anything of interest in this \033[1;31mcupboard\033[0m\n");
		set_desc("The open \033[1;31mcupboard\033[0m has nothing of interest inside it\n");
	}
	else{
		printf("The \033[1;31mcupboard\033[0m is already open.\n");
		
	}
	return 4;
}
int Feature26::use(int feat_obj){
	if (feat_obj==DIARY){
		printf("You chant the following spell:'Ego tetigit hoc omnium sententia mea ut reveletur'\n");
		return 37;
	}
	return 4;
}

Feature26::~Feature26() {
	
}
