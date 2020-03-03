//
// Feature8.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature8.h"

Feature8::Feature8() {
	set_name("\033[1;31mTable\033[0m");
	set_desc("An elaborate banquate appears before you; the \033[1;31mtable\033[0m is laden with a centerpiece of fruit, and several delicious smelling dishes. There are about 10 places set. However, when you try to step forward to further look at the setting, everything fades away like a mirage. It looks like there is a single book placed at the edge of the \033[1;31mtable\033[0m.");
	set_index_id(7);
}
int Feature8::read(){
	printf("There is nothing to read on the \033[1;31mtable\033[0m.\n");		
	return 4;
}
int Feature8::smell(){
	
	printf("You try to smell the food and almost faint from how delicious it smells. You clutch the \033[1;31mtable\033[0m for support.\n");	
	func_togg_count_x(SMELL);
	return 4;
	
}
int Feature8::eat(){
	
	printf("You eat a cookie from the \033[1;31mtable\033[0m. Hmm, that delicious. oh no. What's happening? You feel yourself being moved somewhere. Where are you going?\n");
	func_togg_count_x(EAT);
	
	return 10;	

}

Feature8::~Feature8() {
	
}
