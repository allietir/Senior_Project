//
// Object8.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Object8.h"

Object8::Object8() {
	set_name("\033[1;35mChalice\033[0m");
	set_desc("The \033[1;35mchalice\033[0m shines bright. It looks newer than anything else in the house.");
	set_index_id(7);
}
int Object8::read(){
	string read_response = "Sanguis seu spiritus";
	func_togg_count_x(READ);
	printf("%s\n", read_response.c_str());
	return 4;	
}
Object8::~Object8() {
	
}
