//
// Feature1.cpp
// Created by Claudia Rodriguez-Schroeder on 1/22/20.

#include "Feature1.h"

Feature1::Feature1() {
	set_name("\033[1;31mGravestone\033[0m");
	set_desc("A gray, dreary looking \033[1;31mgravestone\033[0m with vines covering the name of the deceased.\nSomething shiny is glinting on the floor behind the \033[1;31mgravestone\033[0m.\nWhat is it? A weapon of some sort? A \033[1;35mdagger\033[0m?\n");
	set_desc_no_obj("A gray, dreary looking \033[1;31mgravestone\033[0m with vines covering the name of the deceased.\nThe indent of the \033[1;35mdagger\033[0m you picked up is still in the grass.\n");
	set_desc_w_obj(get_desc());
	set_index_id(0);
}

int Feature1::read(){
	string read_response = "The \033[1;31mgravestone's\033[0m first name is too faded to read, but the last name says 'Smith'.\n 'Hey', says Alex. 'Wasn't that your mom's maiden name?'. 'Yeah', you reply.\n";
	func_togg_count_x(0);
	
	printf("%s\n", read_response.c_str());
	return 4;
} 
int Feature1::smell(){
	string smell_response = "The \033[1;31mgravestone\033[0m smells stony and earthy. It doesn't smell like death; it smells like life. \n";
	func_togg_count_x(SMELL);
	
	printf("%s\n", smell_response.c_str());
	return 4;
} 
int Feature1::use(int x){
	string use_response = "You can't use the \033[1;31mgravestone\033[0m right now. You can use it later, when you're dead.\n";
	func_togg_count_x(USE);
	
	printf("%s\n", use_response.c_str());
	return 4;
} 
int Feature1::eat(){
	string eat_response = "You can't eat the \033[1;31mgravestone\033[0m right now, unless you gain the power to digest stones \n";
	func_togg_count_x(EAT);
	
	printf("%s\n", eat_response.c_str());
	return 4;
} 
int Feature1::play(){
	string play_response = "Playing a \033[1;31mgravestone\033[0m makes no sense. \n";
	func_togg_count_x(PLAY);
	
	printf("%s\n", play_response.c_str());
	return 4;
}
int Feature1::open(int x, int y){
	string open_response = "The \033[1;31mgravestone\033[0m doesn't open. If it did, what would you do with the open \033[1;31mgravestone\033[0m? Are you some sort of graverobber?\n";
	func_togg_count_x(OPEN);
	printf("%s\n", open_response.c_str());
	return 4;
}
int Feature1::speak(){
	string speak_response = "The \033[1;31mgravestone's\033[0m body doesn't seem to have any sort of ghost attached you can speak to. Hey, that's a good thing. \n";
	func_togg_count_x(SPEAK);
	printf("%s\n", speak_response.c_str());
	return 4;
}
int Feature1::give(int x, int y){
	func_togg_count_x(GIVE);
	printf("A %s is not a proper gift for a \033[1;31mgravestone\033[0m.\n", get_obj_name(y).c_str());
	return 4;
}
int Feature1::climb(){
	string climb_response = "It's pretty bad form to climb a \033[1;31mgravestone\033[0m.\n";
	func_togg_count_x(CLIMB);
	printf("%s\n", climb_response.c_str());
	return 4;
}
int Feature1::attack(int obj_id){
	printf("Attacking with a %s is not effective. Luckily, the \033[1;31mgravestone\033[0m does not attack back.", get_obj_name(obj_id).c_str());
	func_togg_count_x(ATTACK);
	return 4;
}
Feature1::~Feature1() {
	
	
}
