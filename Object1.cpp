//
// Object1.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Object1.h"

Object1::Object1() {
	set_name("Oil Lamp");
	set_desc("A dusty old oil lamp, glass chipped and handle rusted. It looks like there is an enscription on the metal");
	set_index_id(0);
}
string Object1::read(){
	string read_response = "Vos postulo mihi tenebris";
	func_togg_count_x(0);
	return read_response;
}
Object1::~Object1() {
	
}