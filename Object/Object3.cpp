//
// Object3.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Object3.h"

Object3::Object3() {
	set_name("Locket");
	set_desc("The locket is silver and small; it looks surprisingly shiny and new for what appears to be an very old fashioend design. ");
	set_index_id(2);
}
int Object3::read(){
	func_togg_count_x(READ);
	printf("The locket has a tiny inscription that says 'Open me below'\n");
	return 4;
}
int Object3::open(int room_id, int feat_id){	
	
	if (room_id == CRYPT)
	{
		printf("You open the locket. This is the room. This is what all the signs meant.\n");
		func_togg_count_x(OPEN);
		//triggers event 0;
		return 0;
		
	}
	else{
		printf("You struggle to open the locket, but it's no use.\n");
		return 4;
		//idea: if you try to open the locket too many times it breaks and there is no more locket. 
	}
	return 4;

	
}
Object3::~Object3() {
	
}
