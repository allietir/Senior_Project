//
// Feature1.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature1.h"

Feature1::Feature1() {
	set_name("Gravestone");
	set_desc1("A gray, dreary looking Gravestone with vines covering the name of the deceased.\nSomething shiny is glinting on the floor behind the gravestone.\nWhat is it? A weapon of some sort? A dagger?\n");
	set_desc1_no_obj("A gray, dreary looking Gravestone with vines covering the name of the deceased.\nThe indent of the knife you picked up is still in the grass.\n");
	set_desc(desc1);
	set_index_id(0);
}

int Feature1::read(){
	string read_response = "The " + get_name() + "'s first name is too faded to read, but the last name says 'Smith'.\n 'Hey', says " + FRIEND_NAME + ". 'Wasn't that your mom's maiden name?'. 'Yeah', you reply, ";
	func_togg_count_x(0);
	
	printf("%s\n", read_response.c_str());
	return 0;	
	return 1;
} 
string Feature1::get_desc1(){
	return desc1;
}
string Feature1::get_desc1_no_obj(){
	return desc1_no_obj;
}
void Feature1::set_desc1(string x){
	desc1 = x;
}
void Feature1::set_desc1_no_obj(string x){
	desc1_no_obj = x;
}
void Feature1::remove_object_desc(){
	set_desc1(get_desc1_no_obj());
}
Feature1::~Feature1() {
	
	
}
