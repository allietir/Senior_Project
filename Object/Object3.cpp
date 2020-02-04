//
// Object3.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Object3.h"

Object3::Object3() {
	set_name("Locket");
	set_desc("The locket is silver and small; it looks surprisingly shiny and new for what appears to be an very old fashioend design. ");
	set_index_id(2);
}
void Object3::read(){
	string read_response = "The locket has a tiny inscription that says 'Open me below\n' ";
	func_togg_count_x(0);
	printf("%s\n", read_response.c_str());
}
void Object3::open(int room_id, int feat_id){	
	string open_response = "The ";
	func_togg_count_x(0);
	printf("%s\n", open_response.c_str());
}
Object3::~Object3() {
	
}
