//
// Feature17.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature17.h"

Feature17::Feature17() {
	set_name("\033[1;31mMirror\033[0m");
	set_desc("There is a \033[1;31mmirror\033[0m in the bathroom and there is writing on the \033[1;31mmirror\033[0m. ");
	set_desc_no_obj(get_desc());
	set_index_id(16);
}
int Feature17::read(){
	func_togg_count_x(READ);
	printf("So thirsty. So hungry. So cold. I just want someone to speak to me. ");
	return 4;
	
	
}
int Feature17::speak(){
	if (get_times_toggled(SPEAK)==0){
		func_togg_count_x(SPEAK);
		printf("\"I'm in the \033[0;36mmaster\033[0m bedroom, but I am too weak to speak to anyone except through magic, and this \033[1;31mmirror\033[0m.\nCan I trust you?\nI believe in dreams.\nI dreamt I could trust the human with the beautiful song. Do you have a song for me? Maybe play me some \033[1;35mMusic\033[0m \" ");
	}
	else if (get_times_toggled(PLAY)==666){
		printf("\"Thank you. I can tell your spirit is good. Please take some blood from the sink; I will be able to be free then. Come to the \033[0;36mmaster bedroom\033[0m.\" ");
	}

	else if (get_times_toggled(USE)==666){
		printf("\"That song meant a lot to me, thank you.\nTo really know I can trust you, I need you to give me your blood.\nI can tell a person's spirit through their blood.\" Oh god, what can he mean? Your blood? Maybe if you use something sharp...");
	}
	else{
		printf("None of the conditions to speak to \033[1;31mmirror\033[0m in a productive way exist at this time. ");
	}
	return 4;
}
Feature17::~Feature17() {
	
}
