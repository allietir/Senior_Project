//
// Feature26.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature26.h"

Feature26::Feature26() {
	set_name("\033[1;31mCupboard\033[0m");
	set_desc("There is a \033[1;31mcupboard\033[0m in the \033[0;36mkitchen\033[0m with a handle on it. ");
	set_desc_no_obj("There is a \033[1;31mcupboard\033[0m in the \033[0;36mkitchen\033[0m with a handle on it. ");
	set_index_id(25);
}
int Feature26::open(int room_id, int obj_id){
	if (get_times_toggled(OPEN)==0){
		func_togg_count_x(OPEN);
		printf("There doesn't appear to be anything of interest in this \033[1;31mcupboard\033[0m. ");
		set_desc("The open \033[1;31mcupboard\033[0m contains nothing of interest. ");
	}
	else{
		printf("The \033[1;31mcupboard\033[0m is already open. ");
		
	}
	return 4;
}
int Feature26::use(int feat_obj){
	if (feat_obj==DIARY){
		printf("You chant the following spell:\'Ego tetigit hoc omnium sententia mea ut reveletur\' ");
		return 37;
	}
	else{
		printf("I believe a different object could be of use with this \033[1;31mcupboard\033[0m. ");
	}
	return 4;
}

Feature26::~Feature26() {
	
}
