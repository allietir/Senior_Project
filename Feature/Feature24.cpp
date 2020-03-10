//
// Feature24.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature24.h"

Feature24::Feature24() {
	set_name("\033[1;31mGuardian\033[0m");
	set_desc("There is a \033[1;31mguardian\033[0m by the \033[1;31mfountain\033[0m, and appears to be an old man with a beard full of vines and a staff that seems to be forever changing, flowers growing and dying before your eyes. He is holding a silver \033[1;35mchalice\033[0m");
	set_desc_no_obj("There is a \033[1;31mguardian\033[0m by the \033[1;31mfountain\033[0m, and appears to be an old man with a beard full of vines and a staff that seems to be forever changing, flowers growing and dying before your eyes.");
	set_index_id(23);
}
int Feature24::speak(){
	if (get_times_toggled(SPEAK)==0){
		func_togg_count_x(SPEAK);
		printf("'Some things are keys, even if they don't look like keys! Please, take this \033[1;35mchalice\033[0m. It has more than once use!\n'");
		//trigger unlock chalice in GAME
		return -47;
	}
	else{
		printf("'I hope you can save your friend.\n'");
	}
	return 4;
}
Feature24::~Feature24() {
	
}
