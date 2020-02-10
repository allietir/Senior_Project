//
// Feature6.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature6.h"

Feature6::Feature6() {
	set_name("Carpet");
	set_desc("The carpet is long and dark, and there is an image of a house on a hill. There are words on the hill of the carpet.\n");
	set_index_id(5);
}
int Feature6::read(){
	string read_response = "There once was a house on a hill\nGo inside with a friend, if you will\nThere a terrible loss will take place\nYou had better get out, do have haste\nBut to save the dear soul within\nYou will have to fight several monsters within\n";
	func_togg_count_x(READ);
	printf("%s\n", read_response.c_str());
	return 4;
}
Feature6::~Feature6() {
	
}
