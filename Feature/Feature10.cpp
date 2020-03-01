//
// Feature10.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature10.h"

Feature10::Feature10() {
	set_name("Painting");
	set_desc("There is a painting of a beautiful women sleeping with her eyes closed.\n");
	set_index_id(9);
}
int Feature10::speak(){
	
	if (get_times_toggled(SPEAK)==0){
		if (get_desc().compare("There is a painting of a beautiful women sleeping with her eyes closed.\n")!=0){
				func_togg_count_x(SPEAK);
				printf("I am going to go look for my family. Thank you for believing in me.\n");
				return 1;
			}
	}
	
	else{
		printf("She is asleep and cannot speak.\n");
	}
	return 4;
}
int Feature10::open(int room_id, int obj_id){
	if (get_times_toggled(SPEAK)==1){
		printf("The portrait swings open and revelas a staircase\n");
		return 3;
	}
	return 4;
}
Feature10::~Feature10() {
	
}
