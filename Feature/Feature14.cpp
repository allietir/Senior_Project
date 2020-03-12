//
// Feature14.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature14.h"

Feature14::Feature14() {
	set_name("\033[1;31mDresser\033[0m");
	set_desc("The \033[1;31mdresser\033[0m mirror shows a terrifying reflection; the \033[1;31mwoman\033[0m in the bed behind you is reflected there, but beside her in the mirror of the \033[1;31mdresser\033[0m is a horrifying ghoul. The \033[1;31mwoman\033[0m is in white and her eyes and mouth are black and gaping. She isn't moving, just floating by her body. On the \033[1;31mdresser\033[0m there is some sheet \033[1;35mmusic\033[0m. The \033[1;31mdresser\033[0m appears to be fragile. Maybe you can break it? ");
	set_desc_no_obj("The \033[1;31mdresser\033[0m mirror shows a terrifying reflection; the \033[1;31mwoman\033[0m in the bed behind you is reflected there, but beside her in the mirror of the \033[1;31mdresser\033[0m is a horrifying ghoul. The \033[1;31mwoman\033[0m is in white and her eyes and mouth are black and gaping. She isn't moving, just floating by her body. The \033[1;31mdresser\033[0m appears to be fragile. Maybe you can break it? ");
	set_index_id(13);
}
int Feature14::attack(int obj_id){
	
	if (obj_id==DAGGER){
		
		return 1;
	}
	else{
		printf("You cannot attack with this object. Perhaps a sharper one? ");
	}
	return 4;
	
}
Feature14::~Feature14() {
	
}
