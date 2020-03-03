//
// Feature23.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature23.h"

Feature23::Feature23() {
	set_name("\033[1;31mFountain\033[0m");
	set_desc("Water pours from the \033[1;31mfountain\033[0m, sparkling even though the room is as dark as the rest of the house.\n");
	set_index_id(22);
}
int Feature23::use(int obj_id){
	if (get_times_toggled(USE)==0){
		
		func_togg_count_x(USE);
		return 1;
	}
	else{
		printf("The \033[1;35mchalice\033[0m is already filled with water.\n");
	}
	return 4;
}
int Feature23::eat(){
	if (get_times_toggled(USE)>=1){
		func_togg_count_x(EAT);
		printf("You are transported to the basement.\n");
		printf("There is no longer water in the \033[1;35mchalice\033[0m\n");
		set_togg_count_x(USE, 0);
		return BASEMENT + 10;
	}
	return 4;
}
Feature23::~Feature23() {
	
}
