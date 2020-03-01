//
// Object1.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Object1.h"

Object1::Object1() {
	set_name("Lamp");
	set_desc("A dusty old oil lamp, glass chipped and handle rusted. It looks like there is an enscription on the metal");
	set_index_id(0);
}
int Object1::read(){
	string read_response = "Vos postulo mihi tenebris";
	func_togg_count_x(READ);
	printf("%s\n", read_response.c_str());
	return 4;
}
int Object1::use(int obj_feat_obj){
	printf("----------------here------------------\n");
	if (get_times_toggled(USE)==0){
		func_togg_count_x(USE);
		printf("The lamp turns on and you can see more clearly than before.\n");
	}
	else if (get_times_toggled(USE)==1){
		
		printf("The lamp is already on and you can see more clearly in the room\n");
	}
	return 4;
	
}

Object1::~Object1() {
	
}
