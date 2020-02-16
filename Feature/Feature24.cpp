//
// Feature24.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature24.h"

Feature24::Feature24() {
	set_name("Guardian");
	set_desc("There is a guardian by the fountain, and appears to be an old man with a beard full of vines and a staff that seems to be forever changing, flowers growing and dying before your eyes. He is holding a silver chalice");
	set_desc_no_obj("There is a guardian by the fountain, and appears to be an old man with a beard full of vines and a staff that seems to be forever changing, flowers growing and dying before your eyes.");
	set_index_id(23);
}
int Feature24::speak(){
	if (func_togg_count_x(SPEAK)==0){
		func_togg_count_x(SPEAK);
		printf("'Some things are keys, even if they don't look like keys! Please, take this chalice. It has more than once use!\n'");
		//trigger unlock chalice in GAME
		return 35;
	}
	else{
		printf("'I hope you can save your friend.\n'");
	}
	return 4;
}
Feature24::~Feature24() {
	
}
