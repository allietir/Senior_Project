//
// Object6.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Object6.h"

Object6::Object6() {
	set_name("Doll");
	set_desc("A doll that seems simultaneously innocent and menacing. ");
	set_index_id(5);
}
int Object6::give(int room_id, int feat_obj_id){
	if (feat_obj_id == CHILD){
		//
	}
	return 4;
}
Object6::~Object6() {
	
}
