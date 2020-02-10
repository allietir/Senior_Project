//
// Object2.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Object2.h"

Object2::Object2() {
	set_name("Diary");
	set_desc("The diary is some type of leather, dark and stained with something. Is it ink or is it blood? ");
	set_index_id(0);
}
int Object2::read(){
	string read_response = "The first page says 'Property of S--' but the rest of the name cannot be seen, faded by water damage and time.\n You open it to a worn page and see the following information.\n\"Dear diary; it it my final day in this wretched house. I am seeing that I am going to be unable to escape, as I lay dying, but perhaps the next person who finds this journal will be able to learn from my mistakes. I have learned that there is a special object within this house that will trap the creature. My studies have revelaed that it is no cage, no great chest, but a small, magical object that you could hold in the palm of your hand.\"\n\n";
	func_togg_count_x(READ);
	printf("%s\n", read_response.c_str());
	return 4;
	
	
}
Object2::~Object2() {
	
}
