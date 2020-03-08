//
// Feature9.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature9.h"

Feature9::Feature9() {
	set_name("\033[1;31mPiano\033[0m");
	set_desc("The \033[1;31mpiano\033[0m is large and ornate; it is a grand \033[1;31mpiano\033[0m.");
	set_index_id(8);
}
int Feature9::play(){
	if (get_times_toggled(USE)>=1){
		printf("You play the \033[1;31mpiano\033[0m and feel soothed by the music.");
		return 4;
	}
	else{
		printf("You can't play the \033[1;31mpiano\033[0m without sheet music.");
		return 4;
	}
	
}
int Feature9::use(int obj_id){
	if (obj_id == MUSIC)
	{
		printf("Now you can use the music to play the \033[1;31mpiano\033[0m!");
		func_togg_count_x(USE);
		return 0;
	}
	else{
		printf("You can't use this object with the \033[1;31mpiano\033[0m.");
		return 4;
	}
}
Feature9::~Feature9() {
	
}
