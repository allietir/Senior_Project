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
	string read_response = "The gravestone's first name is too faded to read, but the last name says 'Smith'.\n 'Hey', says Alex. 'Wasn't that your mom's maiden name?'. 'Yeah', you reply.\n";
	func_togg_count_x(0);
	
	printf("%s\n", read_response.c_str());
	return 4;
} 
int Feature1::smell(){
	string smell_response = "The gravestone smells stony and earthy. It doesn't smell like death; it smells like life. \n";
	func_togg_count_x(SMELL);
	
	printf("%s\n", smell_response.c_str());
	return 4;
} 
int Feature1::use(int x){
	string use_response = "You can't use the gravestone right now. You can use it later, when you're dead.\n";
	func_togg_count_x(USE);
	
	printf("%s\n", use_response.c_str());
	return 4;
} 
int Feature1::eat(){
	string eat_response = "You can't eat the gravestone right now, unless you gain the power to digest stones \n";
	func_togg_count_x(EAT);
	
	printf("%s\n", eat_response.c_str());
	return 4;
} 
int Feature1::play(){
	string play_response = "Playing a gravestone makes no sense. \n";
	func_togg_count_x(PLAY);
	
	printf("%s\n", play_response.c_str());
	return 4;
}
int Feature1::open(int x, int y){
	string open_response = "The gravestone doesn't open. If it did, what would you do with the open gravestone? Are you some sort of graverobber?\n";
	func_togg_count_x(OPEN);
	printf("%s\n", open_response.c_str());
	return 4;
}
int Feature1::speak(){
	string speak_response = "The gravestone's body doesn't seem to have any sort of ghost attached you can speak to. Hey, that's a good thing. \n";
	func_togg_count_x(SPEAK);
	printf("%s\n", speak_response.c_str());
	return 4;
}
int Feature1::give(int x, int y){
	func_togg_count_x(GIVE);
	printf("A %s is not a proper give for a gravestone.\n", get_obj_name(y).c_str());
	return 4;
}
int Feature1::climb(){
	string climb_response = "It's pretty bad form to climb a gravestone.\n";
	func_togg_count_x(CLIMB);
	printf("%s\n", climb_response.c_str());
	return 4;
}
int Feature1::attack(int obj_id){
	printf("Attacking with a %s is not effective. Luckily, the gravestone does not attack back.", get_obj_name(obj_id).c_str());
	func_togg_count_x(ATTACK);
	return 4;
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
