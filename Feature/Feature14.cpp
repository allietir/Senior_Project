//
// Feature14.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature14.h"

Feature14::Feature14() {
	set_name("Dresser");
	set_desc("The dresser mirror shows a terrifying reflection; the woman in the bed behind you is still there, but besides her is a horrifying ghoul; the woman, in white, but her eyes and mouth are black and gaping. She isn't moving, just floating by her body. The dresser has some sheet music on there.");
	set_desc_no_obj("The dresser mirror shows a terrifying reflection; the woman in the bed behind you is still there, but besides her is a horrifying ghoul; the woman, in white, but her eyes and mouth are black and gaping. She isn't moving, just floating by her body.");
	set_index_id(13);
}
int Feature14::attack(int obj_id){
	
	if (obj_id==DAGGER){
		
		return 1;
	}
	else{
		printf("You cannot attack with this object. Perhaps a sharper one?\n");
	}
	return 4;
	
}
Feature14::~Feature14() {
	
}
