//
// Feature19.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature19.h"

Feature19::Feature19() {
	set_name("Chest");
	set_desc("There is a large chest with a keyhole.\n");
	set_desc_no_obj("There is nothing else in the chest.\n");
	set_index_id(18);
}
int Feature19::open(int room_id, int object_id){
	if (object_id==KEY){
		if (get_times_toggled(OPEN)==0){
			func_togg_count_x(OPEN);
			set_desc("There is a doll in the chest, and nothing else.\n");
			printf("You open the chest with the key\n");
		}
		//triggers first room event that trickes event3() in game
		return 1;
	}
	else {
		printf("You can't open the chest with that object.\n");
		return 4;
	}
	return 4;
}


Feature19::~Feature19() {
	
}
