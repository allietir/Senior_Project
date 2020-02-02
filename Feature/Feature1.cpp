//
// Feature1.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature1.h"

Feature1::Feature1() {
	set_name("Gravestone");
	desc1 = "A gray, dreary looking Gravestone with vines covering the name of the deceased. ";
	desc2 = "Something shiny is glinting on the floor behind the gravestone. What is it? A weapon of some sort?\n";
	set_desc(desc1);
	set_index_id(0);
}
void Feature1::read(){
	string read_response = "The " + get_name() + "'s first name is too faded to read, but the last name says 'Smith'.\n 'Hey', says" + FRIEND_NAME + ". 'Wasn't that your mom's maiden name?'. 'Yeah', you reply, ";
	func_togg_count_x(0);
	
	printf("%s\n", read_response.c_str());	
}
void Feature1::look(){
	if (get_look_count()==0){
		set_desc(desc1);
		set_look_count(1);
	}

	else if (get_look_count()==1){
		set_desc(desc2);
;
		set_look_count(0);
	}
		
	printf("%s\n", get_desc().c_str());
	
}
Feature1::~Feature1() {
	
	
}