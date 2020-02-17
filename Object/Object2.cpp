//
// Object2.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Object2.h"

Object2::Object2() {
	set_name("Diary");
	set_desc("The diary is some type of leather, dark and stained with something. Is it ink or is it blood? ");
	set_index_id(1);
}
int Object2::read(){
	string read_response = "The first page says 'Property of S--' but the rest of the name cannot be seen, faded by water "
		"damage and time.\n You open it to a worn page and read the following...\n\n\"If you are reading this, "
		"then you too have found yourself in this wretched house. Please, listen closely. There is a monster in this house, but it is not easily defeated. "
		"There is an object that can trap the monster. It is a small, magical object that fits into the palm of your hand. "
		"As for myself... I cannot escape. I have failed. And now, I will die. Find the object and live. Do not meet the same miserable fate "
		"as me. \n\nGood luck.\"\n\n";
	func_togg_count_x(READ);
	printf("%s\n", read_response.c_str());
	return 4;
	
}
Object2::~Object2() {
	
}
