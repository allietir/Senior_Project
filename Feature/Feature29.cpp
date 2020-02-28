//
// Feature29.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature29.h"

Feature29::Feature29() {
	set_name("Alex");
	set_desc("Alex looks transfixed and bodyless; they aren't tied up and they aren't screaming, but they are standing like a dead person would stand, like a zombie and a ghost; her eyes completely white, staring at the demon before her as he seems to be sucking some sort of life force from her");
	set_desc_no_obj(get_desc());
	set_index_id(28);
}
//you can also trigger the wining event by giving alex all the objects
int Feature29::give(int room_id, int obj_feat_id){
	
	if (get_times_toggled(GIVE)==obj_feat_id){
		printf("You give Alex the %s and it merges with their being, strengthening them.", get_obj_name(obj_feat_id).c_str());
		set_togg_count_x(GIVE, obj_feat_id+1);
		return -45;
	}
	if (get_times_toggled(GIVE)!=obj_feat_id){
		printf("The sequence is not correct; %s is not the next item to give. \n", get_obj_name(obj_feat_id).c_str());
	}
	if (get_times_toggled(GIVE)==NUM_OBJECTS)
	{
		return 0;
	}
	return 4;

	
}
Feature29::~Feature29() {
	
}
