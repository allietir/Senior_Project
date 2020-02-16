//
// Feature25.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature25.h"

Feature25::Feature25() {
	set_name("Stove");
	set_desc("There is a stove in this kitchen. It looks like it hasn't been used for years.");
	set_index_id(24);
}
int Feature25::use(int obj_id){
	return 45+obj_id;
}
Feature25::~Feature25() {
	
}
