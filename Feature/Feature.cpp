//
// Feature.cpp
// Created by Claudia Rodriguez-Schroeder on 1/2/20.

#include "Feature.h"
#include <string>
#include <cstdio>

using namespace std;
Feature::Feature() {
	
	name = "no feature name";
	desc = "no feature description";

	error_message = "feature error";
	index_id = -666;
	fixed = 1;
	//init
	look_count = 0;
	for (int i = 0; i < NUM_VERB_FUNCS; i++){
		verb_func_toggled[i]=0;
	}
		
}
string Feature::get_name(){
	return name;
}
void Feature::set_name(string s_name){
	name = s_name;	
}
	
int Feature::get_index_id(){
	return index_id;
}
void Feature::set_index_id(int s_index_id){
	index_id = s_index_id;
}
string Feature::get_desc(){
	return desc;
}
void Feature::set_desc(string s_desc){
	desc = s_desc;
}
	
int Feature::get_feature_examined(){
	return feature_examined;
}
void Feature::set_feature_examined(int s_feature_examined){
	feature_examined = s_feature_examined;
}

int Feature::get_fixed(){
	return fixed;
}
void Feature::set_fixed(int s_fixed){
	fixed = s_fixed;
}
int Feature::get_current_room(){
	return current_room;
}
void Feature::set_current_room(int s_current_room){
	current_room = s_current_room;
}

int Feature::get_look_count()
{
	return look_count;
}
void Feature::set_look_count(int x){
	look_count = x;
}
int Feature::func_togg_count_x(int x){
	
	verb_func_toggled[x]=verb_func_toggled[x] + 1;
	return verb_func_toggled[x];
}
void Feature::set_togg_count_x(int x, int new_count){
	
	verb_func_toggled[x]=new_count;
	
}

void Feature::read(){
	string response = get_name() + " cannot be read\n";
	printf("%s\n", response.c_str());

}
void Feature::look()//print description
{
	look_count = look_count + 1;
	printf("%s\n", desc.c_str());
}

/*
void Feature::pull(){
	string response = get_name() + " cannot be pulled\n";
	printf("%s\n", response.c_str());
}*/

/*
void Feature::push(){
	string response = get_name() + " cannot be pushed\n";
	printf("%s\n", response.c_str());

}
*/

/*
void Feature::turn(){
	string response = get_name() + " cannot be turned\n";
	printf("%s\n", response.c_str());

}
*/

void Feature::play(){
	string response = get_name() + " cannot be played\n";
	printf("%s\n", response.c_str());

}

void Feature::open(){
	string response = get_name() + " cannot be open\n";
	printf("%s\n", response.c_str());

}//for cat features

void Feature::speak(){
	string response = get_name() + " cannot be spoken to\n";
	printf("%s\n", response.c_str());


}//talk to a feature or object 

/*
void Feature::listen(){
	string response = get_name() + " cannot be listened to\n";
	printf("%s\n", response.c_str());


}//user to interact with some features or objects potentially
*/
//will allow user to exit
int Feature::climb(){
	string response = get_name() + " cannot be climbed\n";
	printf("%s\n", response.c_str());
	return -1;

}//use to interact with some features to exit between rooms

/*
int Feature::jump(){
	string response = get_name() + " cannot be jumped on or through\n";
	printf("%s\n", response.c_str());
	return -1;

}//user to interact with some features to exit between rooms
*/

int Feature::attack(string object_name){
	string response = get_name() + " cannot be attacked with " + object_name + "\n";
	printf("%s\n", response.c_str());
	return 0;
}

/*
void Feature::light(){
	string response = get_name() + " cannot be lit\n";
		printf("%s\n", response.c_str());
}//11light the lamp or rooms that have switches
*/

void Feature::fill(){
	string response = get_name() + " cannot be filled\n";
	printf("%s\n", response.c_str());
}//12used to fill chalice with blood or holy water within the conservatory feature and vampire blood feature
	
void Feature::use(){
	string response = get_name() + " cannot be used\n";
		printf("%s\n", response.c_str());
}//13
void Feature::give(){
	string response = get_name() + " cannot be given\n";
		printf("%s\n", response.c_str());
}//14
void Feature::eat(){
	string response = get_name() + " cannot be eaten\n";
		printf("%s\n", response.c_str());
}//15
void Feature::smell(){
	string response = get_name() + " cannot be smelled\n";
		printf("%s\n", response.c_str());
}//16
int Feature::get_times_toggled(int function_id){
	return verb_func_toggled[function_id];
}
void Feature::remove_object_desc(){
	//nothing changes
}
int Feature::get_attack_obj_id(){
	return attack_obj_id;
}
void Feature::set_attack_obj_id(int obj_id){
	attack_obj_id = obj_id;
}

Feature::~Feature() {
	
}