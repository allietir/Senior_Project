//
// Feature14.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature14.h"

Feature14::Feature14() {
	set_name("\033[1;31mDresser\033[0m");
	set_desc("The \033[1;31mdresser\033[0m mirror shows a terrifying reflection; the \033[1;31mwoman\033[0m in the bed behind you is still there, but besides her is a horrifying ghoul; the \033[1;31mwoman\033[0m, in white, but her eyes and mouth are black and gaping. She isn't moving, just floating by her body. The \033[1;31mdresser\033[0m has some sheet music on there.");
	set_desc_no_obj("The \033[1;31mdresser\033[0m mirror shows a terrifying reflection; the \033[1;31mwoman\033[0m in the bed behind you is still there, but besides her is a horrifying ghoul; the \033[1;31mwoman\033[0m, in white, but her eyes and mouth are black and gaping. She isn't moving, just floating by her body.");
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
