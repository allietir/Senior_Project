//
// Feature15.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature15.h"

Feature15::Feature15() {
	set_name("\033[1;31mVampire\033[0m");
	set_desc("A sleeping \033[1;31mvampire\033[0m that doesn't seem to adhere to the rule of sleeping in a coffin.");
	set_desc_no_obj(get_desc());
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
		printf("The \033[1;35mchalice\033[0m needs to be filled with something the \033[1;31mvampire\033[0m can be nourished with");
		
	}
	else if (obj_id!=CHALICE){
		printf("You can't give the \033[1;31mvampire\033[0m this object");
	}
	return 4;
}
int Feature15::speak(){
	func_togg_count_x(SPEAK);
	printf("I refuse to hurt a single soul. I am so hungry.");
	return 4;
}
int Feature15::attack(int object_id){
	func_togg_count_x(ATTACK);
	if (object_id==DAGGER){
		printf("You pierce the \033[1;36mdagger\033[0m into the \033[1;31vampire's\033[0m heart. His eyes open.\n I will not hurt an innocent, but one who attacks is not innocent. Goodbye.");
	}
	else{
		printf("This object is not effective in attacking the \033[1;31mvampire\033[0m.\nHe continues to sleep.");
		return 4;
	}
	return -1;
}
Feature15::~Feature15() {
	
}
