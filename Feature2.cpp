//
// Feature2.cpp
// Created by Claudia Rodriguez-Schroeder on 1/25/20.

#include "Feature2.h"

Feature2::Feature2() {
	set_name("Gnarled Tree");
	desc1 = "A large, gnarled looking black tree without a single leaf. It looks like there is something stuck in the tree.";
	desc2 = "There appears to be a tattered cloth in the tree. It rustles in the wind";
	set_desc(desc1);//
	set_index_id(1);
}
string Feature2::look(){
	if (get_look_count()==1){
		set_desc(desc1);
	}

	if (get_look_count()==2){
		set_desc(desc2);
		set_look_count(1);
	}
	Feature::look();
	return get_desc();
	
}
Feature2::~Feature2() {
	
}