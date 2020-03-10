//
// Feature10.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature10.h"

Feature10::Feature10() {
	set_name("\033[1;31mPainting\033[0m");
	set_desc("There is a \033[1;31mpainting\033[0m of a beautiful women sleeping with her eyes closed. ");
	set_index_id(9);
}
int Feature10::speak(){
	
	if (get_times_toggled(SPEAK)==0){
		if (get_desc().compare("There is a \033[1;31mpainting\033[0m of a beautiful women sleeping with her eyes closed. ")!=0){
				func_togg_count_x(SPEAK);
				printf("I am going to go look for my family. Thank you for believing in me. ");
				return 1;
			}
	}
	
	else{
		printf("She is asleep and cannot speak. ");
	}
	return 4;
}
int Feature10::open(int room_id, int obj_id){
	if (get_times_toggled(SPEAK)==1){
		printf("The \033[1;31mpainting\033[0m swings open and revelas a staircase. ");
		return 3;
	}
	return 4;
}
Feature10::~Feature10() {
	
}
