//
// Feature11.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature11.h"

Feature11::Feature11() {
	set_name("Child");
	set_desc("The child looks haunted and afraid. She wears a silver locket");
	set_desc_no_obj("The child is holding her doll close. She seems happier than before.");
	set_index_id(10);
}
int Feature11::give(int room_id, int feat_obj_id){
	if ((feat_obj_id == DOLL)&&(room_id == NURSURY)){
		printf("The child receives the doll and smiles gratefully.");
		//triggers event one for Room6 which triggers in Game as the unlocking of locket and the locking of doll
		return 1;
	}
	return 4;
}
Feature11::~Feature11() {
	
}
