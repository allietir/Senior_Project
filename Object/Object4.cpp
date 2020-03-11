//
// Object4.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Object4.h"

Object4::Object4() {
	set_name("\033[1;35mMusic\033[0m");
	set_desc("Several sheets of \033[1;35mpaper\033[0m with strange inscriptions on them -- musical notes.");
	set_index_id(3);
}
int Object4::read(){
	string read_response = "Peer Gynt, Suite No. 1, Op. 46 ";
	func_togg_count_x(0);
	printf("%s\n", read_response.c_str());
	return 4;
}
int Object4::play(){
	
	return 42;
	
}
Object4::~Object4() {
	
}
