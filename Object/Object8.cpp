//
// Object8.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Object8.h"

Object8::Object8() {
	set_name("Chalice");
	set_desc("The cup shines brigher than anything in the home has shone, like it is new. ");
	set_index_id(7);
}
void Object8::read(){
	string read_response = "Sanguis seu spiritus";
	func_togg_count_x(0);
	printf("%s\n", read_response.c_str());
	
	
}
Object8::~Object8() {
	
}
