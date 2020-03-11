//
// Feature12.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature12.h"

Feature12::Feature12() {
	set_name("\033[1;31mDollhouse\033[0m");
	set_desc("The \033[1;31mdollhouse\033[0m is dark on the inside and looks as cold and haunted as this house is. ");
	set_desc_no_obj(get_desc());
	set_index_id(11);
}
int Feature12::use(int int_feat_obj){
	if ((int_feat_obj==DOLL)&&((get_times_toggled(USE)==0))){
		func_togg_count_x(USE);
		printf("You can see the \033[1;35mdoll\033[0m shrink within the houseand are astonished as she appears to become a real, tiny human.\nThrough the window you see the little girl walk through a replica of the hallway outside, and you see her turn back the clock. ");
		return 41;
	}
	else if ((int_feat_obj==DOLL)&&((get_times_toggled(USE)>=1))){
		func_togg_count_x(USE);
		printf("Again, you can see the \033[1;35mdoll\033[0m shrink within the house and become real\nThrough the window you see the little girl walk through a replica of the hallway outside, and you see her turn back the clock. ");
		return 41;
	}
	else{
		printf("You can't use this this dollhouse under these conditions.");
	}
	return 4;
	
}
Feature12::~Feature12() {
	
}
