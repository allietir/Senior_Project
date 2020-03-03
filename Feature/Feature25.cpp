//
// Feature25.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature25.h"

Feature25::Feature25() {
	set_name("\033[1;31mStove\033[0m");
	set_desc("There is a \033[1;31mstove\033[0m in this kitchen. It looks like it hasn't been used for years.");
	set_desc_no_obj("There is a \033[1;31mstove\033[0m in this kitchen. It looks like it hasn't been used for years.");
	set_index_id(24);
}
int Feature25::use(int obj_id){
	return 45+obj_id;
}
Feature25::~Feature25() {
	
}
