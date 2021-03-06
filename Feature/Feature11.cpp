//
// Feature11.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature11.h"

Feature11::Feature11() {
	set_name("\033[1;31mChild\033[0m");
	set_desc("The \033[1;31mchild\033[0m looks haunted and afraid. She wears a silver locket. ");
	set_desc_no_obj("The \033[1;31mchild\033[0m is holding her doll close. She seems happier than before. ");
	set_index_id(10);
}
int Feature11::give(int room_id, int feat_obj_id){
	if (get_times_toggled(GIVE)==0){
		if (feat_obj_id==DOLL){
				func_togg_count_x(GIVE);
				printf("The \033[1;31mchild\033[0m smiles gratefully.");
				//triggers event one for Room6 which triggers in Game as the unlocking of locket and the locking of doll
				return 1;
			}
		else {
				printf("This is not what the \033[1;31mchild\033[0m needs. ");
			}
	}
	
	else {
		printf("This is not what the \033[1;31mchild\033[0m needs. ");
	}
	return 4;
}
int Feature11::speak()
{
	if (get_times_toggled(GIVE)>=1){
		printf("The \033[1;31mchild\033[0m has nothing more to say. ");
	}
	else{
		func_togg_count_x(SPEAK);
		printf("The \033[1;31mchild\033[0m points to the \033[1;31mdollhouse\033[0m. \"No one lives there anymore. My \033[1;35mdoll\033[0m left home. Can you bring her back to me?\"");
		return 4;
		
	}
	return 4;
	
	
}
Feature11::~Feature11() {
	
}
