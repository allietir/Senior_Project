//
// Object7.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Object7.h"

Object7::Object7() {
	set_name("\033[1;35mKey\033[0m");

	set_desc("The \033[1;35mkey\033[0m is large and encrusted with a jewel. It must be able to open something... ");

	set_index_id(6);
}
int Object7::read(){
	string read_response = "caeli desuper";
	func_togg_count_x(0);
	printf("%s\n", read_response.c_str());
	return 4;
	
	
}
Object7::~Object7() {
	
}
