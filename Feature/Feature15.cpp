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
	func_togg_count_x(GIVE);
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
int Feature15::speak(){
	func_togg_count_x(SPEAK);
	printf("I refuse to hurt a single soul. I am so hungry.\n");
	return 4;
}
int Feature15::attack(int object_id){
	func_togg_count_x(ATTACK);
	if (object_id==DAGGER){
		printf("You pierce the dagger into the vampires heart. His eyes open.\n I will not hurt an innocent, but one who attacks is not innocent. Goodbye.\n");
	}
	else{
		printf("This object is not effective in attacking the vampire.\nHe continues to sleep.\n");
		return 4;
	}
	return -1;
}
Feature15::~Feature15() {
	
}
