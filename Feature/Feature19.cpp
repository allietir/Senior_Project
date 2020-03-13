//
// Feature19.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature19.h"

Feature19::Feature19() {
	set_name("\033[1;31mChest\033[0m");
	set_desc("There is a large \033[1;31mchest\033[0m with a keyhole. ");
	set_desc_no_obj("There is nothing else in the \033[1;31mchest\033[0m. ");
	set_index_id(18);
}
int Feature19::open(int room_id, int object_id){
	
	if (get_times_toggled(OPEN)>=1){
		printf("The chest is already open");
	}
	else if (object_id==KEY){
		if (get_times_toggled(OPEN)==0){
			func_togg_count_x(OPEN);
			set_desc("There is a \033[1;35mdoll\033[0m in the \033[1;31mchest\033[0m, and nothing else. ");
			printf("You open the \033[1;31mchest\033[0m with the \033[1;35mkey\033[0m. ");
		}
		else{
			printf("The chest is already open");
		}
		//triggers first room event that trickes event3() in game
		return 1;
	}
	else {
		printf("You can't open the \033[1;31mchest\033[0m with that object. ");
		return 4;
	}
	return 4;
}
int Feature19::use(int object_id){
	
	if (get_times_toggled(OPEN)>=1){
			printf("The chest is already open");
		}
	else if (object_id==KEY){
		if (get_times_toggled(OPEN)==0){
			func_togg_count_x(OPEN);
			set_desc("There is a \033[1;35mdoll\033[0m in the \033[1;31mchest\033[0m, and nothing else. ");
			printf("You open the \033[1;31mchest\033[0m with the \033[1;35mkey\033[0m. ");
		}
		else{
			printf("The chest is already open");
		}
		//triggers first room event that trickes event3() in game
		return 1;
	}
	else {
		printf("You can't open the \033[1;31mchest\033[0m with that object. ");
		return 4;
	}
	return 4;
}


Feature19::~Feature19() {
	
}
