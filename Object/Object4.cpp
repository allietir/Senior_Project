//
// Object4.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Object4.h"

Object4::Object4() {
	set_name("Music");
	set_desc("Several sheets of paper with strange inscriptions on them--musical notes.");
	set_index_id(3);
}
int Object4::read(){
	string read_response = "Peer Gynt, Suite No. 1, Op. 46";
	func_togg_count_x(0);
	printf("%s\n", read_response.c_str());
	return 0;
}
Object4::~Object4() {
	
}
