//
// Feature18.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature18.h"

Feature18::Feature18() {
	set_name("\033[1;31mSink\033[0m");
	set_desc("There is a \033[1;31msink\033[0m in the bathroom. It is on. There is a liquid pouring from the faucet. It is a deep red and appears to have the viscocity and coppery smell of hot blood. ");
	set_desc_no_obj(get_desc());
	set_index_id(17);
}
int Feature18::use(int obj_int){
	
	if (obj_int==-1){
		if (get_times_toggled(USE)==0){
				func_togg_count_x(USE);
				printf("The \033[1;31msink\033[0m turns off and the blood stops pouring. ");
				set_desc("There is a \033[1;31msink\033[0m in the bathroom. It is off. The \033[1;31msink\033[0m is still stained with the blood. ");
				
			}
			else if (get_times_toggled(USE)==1){
				set_togg_count_x(USE, 0);
				set_desc("There is a \033[1;31msink\033[0m in the bathroom. It is on. There is a liquid pouring from the faucet. It is a deep, deep red and appears to have the viscocity and coppery smell of hot blood. ");

				printf("The \033[1;31msink\033[0m turns back on and the blood continues to pour out. ");
			}
			else{
				printf("The use of the \033[1;31msink\033[0m isn't available at this time ");
			}

	}
	else if (obj_int==CHALICE){
		//return an event trigger event that makes the chalice an offering to the vampire that fortifies him and lets him unite with the woman. 
		return 0;
		
	}
	else{
		printf("There is an object you can use with this, but that isn't it. ");
	}
	return 4;
}
int Feature18::smell(){
	func_togg_count_x(SMELL);
	printf("The smell of the blood makes you want to faint, it is so strong and coppery. ");
	return 4;
}
int Feature18::eat(){
	func_togg_count_x(EAT);
	printf("You are poisoned by the blood. You die. ");
	return -1;
}
Feature18::~Feature18() {
	
}
