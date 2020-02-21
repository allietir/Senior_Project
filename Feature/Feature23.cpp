//
// Feature23.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature23.h"

Feature23::Feature23() {
	set_name("Fountain");
	set_desc("Water pours from the fountain, sparkling even though the room is as dark as the rest of the house.\n");
	set_index_id(22);
}
int Feature23::use(int obj_id){
	if (get_times_toggled(USE)==0){
		printf("The chalice fills with water. Alright, now what?\n");
		func_togg_count_x(USE);
	}
	else{
		printf("The chalice is already filled with water.\n");
	}
	return 4;
}
int Feature23::eat(){
	if (get_times_toggled(USE)>1){
		func_togg_count_x(EAT);
		printf("You are transported to the basement.\n");
		printf("There is no longer water in the chalice\n");
		set_togg_count_x(USE, 0);
		return BASEMENT + 10;
	}
	return 4;
}
Feature23::~Feature23() {
	
}
