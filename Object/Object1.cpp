//
// Object1.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Object1.h"

Object1::Object1() {
	set_name("\033[1;35mLamp\033[0m");

	set_desc("A dusty old oil \033[1;35mlamp\033[0m, glass chipped and handle rusted. There is an inscription on the metal. ");

	set_index_id(0);
}
int Object1::read(){
	string read_response = "Vos postulo mihi tenebris. ";
	func_togg_count_x(READ);
	printf("%s\n", read_response.c_str());
	return 4;
}
int Object1::use(int obj_feat_obj){
	if (get_times_toggled(USE)==0){
		func_togg_count_x(USE);
		printf("The \033[1;35mlamp\033[0m turns on and you can see more clearly than before.");
	}
	else if (get_times_toggled(USE)==1){
		
		printf("The \033[1;35mlamp\033[0m is already on and you can see clearly in the room.");
	}
	return 4;
	
}

Object1::~Object1() {
	
}
