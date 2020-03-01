//
// Feature12.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature12.h"

Feature12::Feature12() {
	set_name("Dollhouse");
	set_desc("The dollhouse is dark on the inside and looks as cold and haunted as this house is.\n");
	set_index_id(11);
}
int Feature12::use(int int_feat_obj){
	if ((int_feat_obj==DOLL)&&((get_times_toggled(USE)==0))){
		func_togg_count_x(USE);
		printf("You can see the doll shrink within the house, and are astonished as she appears to become a real, tiny human.\nThrough the window you see the little girl walk through a replica of the hallway outside, and you see her turn back the clock.\n");
		return 41;
	}
	else if ((int_feat_obj==DOLL)&&((get_times_toggled(USE)>=1))){
		func_togg_count_x(USE);
		printf("Again, you can see the doll shrink within the house and become real\nThrough the window you see the little girl walk through a replica of the hallway outside, and you see her turn back the clock.\n");
		return 41;
	}
	return 4;
	
}
Feature12::~Feature12() {
	
}
