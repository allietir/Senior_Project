//
// Object7.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Object7.h"

Object7::Object7() {
	set_name("Key");
	set_desc("The key is large and jewel encrusted. It must open something previous. ");
	set_index_id(6);
}
int Object7::read(){
	string read_response = "caeli desuper";
	func_togg_count_x(0);
	printf("%s\n", read_response.c_str());
	return 0;
	
	
}
Object7::~Object7() {
	
}
