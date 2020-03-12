//
// Feature13.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature13.h"

Feature13::Feature13() {
	set_name("\033[1;31mMother\033[0m");
	set_desc("There is a \033[1;31mwoman\033[0m lying in a bed. She looks so beautiful but extremely pale. If you go up to her, she appears dead, but there is no smell of death, nor the appearance of being anything but asleep except for the fact that she doesn't seem to be breathing. ");
	set_desc_no_obj("There is a \033[1;31mwoman\033[0m lying in a bed. She looks so beautiful but extremely pale. If you go up to her, she appears dead, but there is no smell of death, nor the appearance of being anything but asleep except for the fact that she doesn't seem to be breathing. ");
	set_index_id(12);
}
int Feature13::speak(){
	if (get_times_toggled(READ)==666){
		return 2;
	}
	else{
		printf("She is not ready to be spoken to. Perhaps if you free her in some way..... ");
	}
	return 4;
}
Feature13::~Feature13() {
	
}
