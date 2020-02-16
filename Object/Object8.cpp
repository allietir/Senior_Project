//
// Object8.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Object8.h"

Object8::Object8() {
	set_name("Chalice");
	set_desc("The chalice shines bright. It looks newer than anything else in the house.");
	set_index_id(7);
}
int Object8::read(){
	string read_response = "Sanguis seu spiritus";
	func_togg_count_x(0);
	printf("%s\n", read_response.c_str());
	return 0;
	
	
}
Object8::~Object8() {
	
}
