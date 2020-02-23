//
// Feature21.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature21.h"

Feature21::Feature21() {
	set_name("Bookshelf");
	set_desc("There is a single bookshelf in the library\nThere are a few books on there, but there is a peculiar quality to them. What makes this bookshelf so strange?\n");
	set_index_id(20);
}
int Feature21::read(){
	
	if (get_times_toggled(READ)==0){
		//
		func_togg_count_x(READ);
		return 38;
	}
	else if (get_times_toggled(READ)==1){
		//
		func_togg_count_x(READ);
		return 39;
	}
	else if (get_times_toggled(READ)==2){
		//
		set_togg_count_x(READ, 0);
		printf("Here is some text from book three\n");
		
	}	
	
	return 4;
}
Feature21::~Feature21() {
	
}
