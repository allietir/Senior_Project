//
// Feature29.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature29.h"

Feature29::Feature29() {
	set_name("\033[1;31mAlex\033[0m");
	set_desc("\033[1;31mAlex\033[0m looks transfixed and bodyless; she isn't tied up and she isn't screaming, but she is standing like a dead person would stand, like a zombie or a ghost. Her eyes are completely white, staring at the demon before her as it seems to be sucking something out from her. ");
	set_desc_no_obj(get_desc());
	set_index_id(28);
}
//you can also trigger the wining event by giving alex all the objects
int Feature29::give(int room_id, int obj_feat_id){
	
	if (get_times_toggled(GIVE)==obj_feat_id){
		printf("You give \033[1;31mAlex\033[0m the %s and it merges with their being, strengthening her. ", get_obj_name(obj_feat_id).c_str());
		set_togg_count_x(GIVE, obj_feat_id+1);
		return -45;
	}
	if (get_times_toggled(GIVE)!=obj_feat_id){
		printf("The sequence is not correct; %s is not the next item to give. ", get_obj_name(obj_feat_id).c_str());
	}
	if (get_times_toggled(GIVE)==NUM_OBJECTS)
	{
		return 0;
	}
	return 4;

	
}
Feature29::~Feature29() {
	
}
