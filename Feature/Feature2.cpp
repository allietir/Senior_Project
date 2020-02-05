//
// Feature2.cpp
// Created by Claudia Rodriguez-Schroeder on 1/25/20.

#include "Feature2.h"

Feature2::Feature2() {
	set_name("Tree");
	desc1 = "A large, gnarled looking black tree without a single leaf. It seems to be as tall as the second floor.The branches seem to poke almost directly into the open window of the second story. \n";
	set_desc(desc1);//
	set_index_id(1);
}

int Feature2::climb(){
	if (get_times_toggled(8)==0){
		printf("You climb up the tree and are able to see that a second story window is open. The room is so dark but it looks like a master bedroom.\n");
		func_togg_count_x(8);
		return -2;//indicate to Game that you are not able to do other things.
	}
	else if (get_times_toggled(8)==1){
		printf("You climb down the tree and you are back on the ground\n");
		set_togg_count_x(8, 0);
		return 10;
	}
	return 10;
}
Feature2::~Feature2() {
	
}
