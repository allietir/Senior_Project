//
// Object2.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Object2.h"

Object2::Object2() {
	set_name("\033[1;35mDiary\033[0m");
	set_desc("The \033[1;35mdiary\033[0m is made of leather, dark and stained with something. Is it ink or blood? ");
	set_index_id(1);
	string read_response = "The first page says 'Property of S--' but the rest of the name cannot be seen, faded by water "
			"damage and time. You open it to a worn page and read the following...\"If you are reading this, "
			"then you too have found yourself in this wretched house. Please, listen closely. There is a great evil here that cannot be easily defeated. "
			"Find an object that can trap it. It is a small object that fits into the palm of your hand. "
			"As for myself... I cannot escape. I have failed. And now, I will die. Find the object and live. Do not meet the same miserable fate "
			"as me. \n\nGood luck. ";
		func_togg_count_x(READ);
		set_read_response(read_response);

}
int Object2::read(){
	printf("%s", get_read_response().c_str());
	return 4;
}

Object2::~Object2() {
	
}
