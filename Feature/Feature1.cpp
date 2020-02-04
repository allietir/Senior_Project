//
// Feature1.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature1.h"

Feature1::Feature1() {
	set_name("Gravestone");
	set_desc1(
		"A gray, dreary looking Gravestone with vines covering the name of the deceased. "
		"Something shiny is glinting on the floor behind the gravestone. "
		"What is it? A weapon of some sort? A dagger?\n"
		);
	//set_desc2("Something shiny is glinting on the floor behind the gravestone. What is it? A weapon of some sort?\n");

	set_desc1_no_obj(
		"A gray, dreary looking Gravestone with vines covering the name of the deceased. "
		"The indent of the knife you picked up is still in the grass.\n"
		);
	set_desc(desc1);
	set_index_id(0);
}

void Feature1::read(){
	string read_response = "The " + get_name() + "'s first name is too faded to read, but the last name says 'Smith'.\n 'Hey', says " + FRIEND_NAME + ". 'Wasn't that your mom's maiden name?'. 'Yeah', you reply, ";
	func_togg_count_x(0);
	
	printf("%s\n", read_response.c_str());	
} 

void Feature1::look(){
	set_desc(get_desc1());
	//set_look_count(1);
	printf("%s\n", get_desc().c_str());
}

/*void Feature1::look(){
	if (get_look_count()==0){
		set_desc(get_desc1());
		set_look_count(1);
		printf("%s\n", get_desc().c_str());
	}

	else if (get_look_count()==1){
		
		set_desc(get_desc2());
		set_look_count(0);
		printf("%s\n", get_desc().c_str());
	}
	else{
		printf("\n====ERROR=====\n");
	}
			
}*/

string Feature1::get_desc1(){
	return desc1;
}

/*string Feature1::get_desc2()
{
	return desc2;
}*/

/*string Feature1::get_desc2_no_obj(){
	return desc2_no_obj;
}*/

string Feature1::get_desc1_no_obj(){
	return desc1_no_obj;
}

void Feature1::set_desc1(string x){
	desc1 = x;
}

/*void Feature1::set_desc2(string x){
	desc2 = x;
}*/

/*void Feature1::set_desc2_no_obj(string x){
	desc2_no_obj = x;
}*/

void Feature1::set_desc1_no_obj(string x){
	desc1_no_obj = x;
}

/*void Feature1::remove_object_desc(){
	set_desc2(get_desc2_no_obj());
}*/
void Feature1::remove_object_desc(){
	set_desc1(get_desc1_no_obj());
}

Feature1::~Feature1() {
	
	
}