//
// Feature13.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature13.h"

Feature13::Feature13() {
	set_name("Mother");
	set_desc("There is a women lying in a bed. She looks extremely beautiful, and extremely pale. If you go up to her, she appears dead, but there is no smell of death, nor the appearance of being annything but asleep; excpet for the fact that she doesn't seem to be breathing.\n\n");
	set_desc_no_obj("There is a women lying in a bed. She looks extremely beautiful, and extremely pale. If you go up to her, she appears dead, but there is no smell of death, nor the appearance of being annything but asleep; excpet for the fact that she doesn't seem to be breathing.\n\n");
	set_index_id(12);
}
int Feature13::speak(){
	if (get_times_toggled(READ)==666){
		return 2;
	}
	else{
		printf("She is not ready to be spoken to. Perhaps if you free her from the mirror in the dresser?\n");
	}
	return 4;
}
Feature13::~Feature13() {
	
}
