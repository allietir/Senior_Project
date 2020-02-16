//
// Feature9.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature9.h"

Feature9::Feature9() {
	set_name("Piano");
	set_desc("The piano is large and ornate; it is a grand piano.\n");
	set_index_id(8);
}
int Feature9::play(){
	if (get_times_toggled(USE)>=1){
		printf("You play the piano and feel soothed by the music.");
		return 4;
	}
	else{
		printf("You can't play the piano without sheet music.\n");
		return 4;
	}
	
}
int Feature9::use(int obj_id){
	if (obj_id == MUSIC)
	{
		printf("Now you can use the music to play the piano!\n");
		func_togg_count_x(USE);
		return 4;
	}
	else{
		printf("You can't use this object with the piano.\n");
		return 4;
	}
}
Feature9::~Feature9() {
	
}
