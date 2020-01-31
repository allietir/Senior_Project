//
// Object5.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Object5.h"

Object5::Object5() {
	set_name("Gilded dagger");
	set_desc("The dagger appears impossilby sharp, like it could cut through the very fabric of reality. ");
	set_index_id(4);
}
string Object5::read(){
	string read_response = "Memento mori";
	func_togg_count_x(0);
	return read_response;
	
	
}
Object5::~Object5() {
	
}
