//
// Object.cpp
// Created by Claudia Rodriguez-Schroeder on 1/5/20.

#include "Object.h"

Object::Object() {

	set_fixed(0);
	for(int i = 0; i < NUM_ROOMS; i ++){
		set_works_with_room(i, 0);
		
	}
	for(int i = 0; i < TOTAL_FIXED; i ++){
		set_works_with_feature(i, 0);
	}
	
	
}
int Object::get_works_with_room(int room_num){
	if ((room_num>=0)&&(room_num<=NUM_ROOMS)){
		return works_with_room[room_num];
	}
	return -1;
}
void Object::set_works_with_room(int room_num, int val){
if ((room_num>=0)&&(room_num<=NUM_ROOMS)){
		works_with_room[room_num]=val;
}
}
int Object::get_works_with_feature(int feature_num){
	if ((feature_num>=0)&&(feature_num<= TOTAL_FIXED )){
		return works_with_feature[feature_num];	
	}
	return -1;
	
}
void Object::set_works_with_feature(int feature_num, int val){
	if ((feature_num>=0)&&(feature_num<= TOTAL_FIXED )){
		works_with_feature[feature_num]=val;
	}
}

Object::~Object() {
	
}