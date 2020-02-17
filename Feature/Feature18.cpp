//
// Feature18.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature18.h"

Feature18::Feature18() {
	set_name("Sink");
	set_desc("There is a sink in the bathroom. It is on. There is a liquid pouring from the faucet. It is a deep, deep red and appears to have the viscocity and coppery smell of hot blood.\n");
	set_index_id(17);
}
int Feature18::use(int obj_int){
	
	if (obj_int==-1){
		if (get_times_toggled(USE)==0){
				func_togg_count_x(USE);
				printf("The sink turns off and the blood stops pouring.\n");
				set_desc("There is a sink in the bathroom. It is off. The sink is still stained with the blood that comes out.\n");
				
			}
			else if (get_times_toggled(USE)==1){
				set_togg_count_x(USE, 0);
				set_desc("There is a sink in the bathroom. It is on. There is a liquid pouring from the faucet. It is a deep, deep red and appears to have the viscocity and coppery smell of hot blood.\n");

				printf("The sink turns back on and the blood continues to pour out.\n");
			}

	}
	else if (obj_int==CHALICE){
		//return an event trigger event that makes the chalice an offering to the vampire that fortifies him and lets him unite with the woman. 
		
	}
	return 4;
}
int Feature18::smell(){
	func_togg_count_x(SMELL);
	printf("The smell of the blood makes you want to faint, it is so strong and coppery.\n");
	return 4;
}
int Feature18::eat(){
	func_togg_count_x(EAT);
	printf("You are poisoned by the blood. You die.\n");
	return -1;
}
Feature18::~Feature18() {
	
}
