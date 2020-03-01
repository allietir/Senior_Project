//
// Feature17.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature17.h"

Feature17::Feature17() {
	set_name("Mirror");
	set_desc("There is a mirror in the bathroom and there is writing on the mirror.\n");
	set_index_id(16);
}
int Feature17::read(){
	func_togg_count_x(READ);
	printf("So thirsty. So hungry. So cold.\n");
	return 4;
	
	
}
int Feature17::speak(){
	if (get_times_toggled(SPEAK)==0){
		func_togg_count_x(SPEAK);
		printf("I'm in the master bedroom, but I am too weak to speak to anyone except through magic, and this mirror.\nCan I trust you?\nI believe in dreams\nI dreamt I could trust the human with the beuatiful song. Do you have a song for me?\n");
	}
	else if (get_times_toggled(PLAY)==666){
		printf("That song meant a lot to me, thank you.\nTo really know I can trust you, I need you to give me your blood.\nI can tell a person's spirit through their blood.\n");
	}
	else if (get_times_toggled(USE)==666){
		printf("Thank you. I can tell your spirit is good. Please take some blood from the sink; I will be able to be free then. Come to the master bedroom.\n");
	}
	return 4;
}
Feature17::~Feature17() {
	
}
