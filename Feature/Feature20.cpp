//
// Feature20.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature20.h"

Feature20::Feature20() {
	set_name("\033[1;31mPirate\033[0m");
	set_desc("There is a strange \033[1;31mpirate\033[0m ghost in the attic. He seems strangely out of place, but you assume there is some reason he is here.");
	set_desc_no_obj(get_desc());
	set_index_id(19);
}
int Feature20::speak(){
	if (get_times_toggled(SPEAK)==0){
		func_togg_count_x(SPEAK);
		printf("I have some information for you. In this room, you may see a \033[1;31mchest\033[0m. This \033[1;31mchest\033[0m requires a \033[1;35mkey\033[1;31m. If you have this \033[1;35mkey\033[0m, you will be able to get a treasure that may not seem important to you, but there is a little \033[1;31mgirl\033[0m in this house to whom this is a precious treasure indeed.");
	}
	else if (get_times_toggled(SPEAK)==1){
		set_togg_count_x(SPEAK, 0);
		printf("And who am I? The little \033[1;31mgirl\033[0m that lived in this house used to love tales of adventure and romance. Her father--you may find him in the master bedroom of this house--used to tell her tales of a \033[1;31mpirate\033[0m whom would adventure over the world and find treasure. I am the guardian of her treasure now.");
	}
	return 4;
}
Feature20::~Feature20() {
	
}
