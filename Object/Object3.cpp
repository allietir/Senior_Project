//
// Object3.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Object3.h"

Object3::Object3() {
	set_name("\033[1;35mLocket\033[0m");
	set_desc("The \033[1;35mlocket\033[0m is silver and small. The design appears to be very old fashioned, but it is in good condition. ");
	set_index_id(2);
}
int Object3::read(){
	func_togg_count_x(READ);
	printf("The \033[1;35mlocket\033[0m has a tiny inscription that says \'I will open when you need me most.\' ");
	return 4;
}
int Object3::open(int room_id, int feat_id){	
	
	if (room_id == CRYPT)
	{
		printf("You open the \033[1;35mlocket\033[0m. This is the room. This is what all the signs meant. ");
		func_togg_count_x(OPEN);
		//triggers event 0;
		return 0;
		
	}
	else{
		printf("You struggle to open the \033[1;35mlocket\033[0m, but it's no use. ");
		return 4;
		//idea: if you try to open the locket too many times it breaks and there is no more locket. 
	}
	return 4;

	
}
Object3::~Object3() {
	
}
