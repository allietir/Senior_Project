//
// Feature15.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature15.h"

Feature15::Feature15() {
	set_name("Vampire");
	set_desc("A sleeping vampire that doesn't seem to adhere to the rule of sleeping in a coffin.\n");
	set_index_id(14);
	//let the 
}
int Feature15::give(int event_occured, int obj_id){
	//only allow this to occur if a certain event has been triggered. 
	if ((obj_id==CHALICE)&&(event_occured==1)){
		return 0;
	}
	else if ((obj_id==CHALICE)&&(event_occured==0)){
		printf("The chalice needs to be filled with something the vampire can be nourished with\n");
		
	}
	else if (obj_id!=CHALICE){
		printf("You can't give the vampire this object\n");
	}
	return 4;
}
Feature15::~Feature15() {
	
}
