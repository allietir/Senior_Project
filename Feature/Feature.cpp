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
void Feature::pull(){
	string response = get_name() + " cannot be pulled\n";
	printf("%s\n", response.c_str());

}
void Feature::push(){
	string response = get_name() + " cannot be pushed\n";
	printf("%s\n", response.c_str());

}

void Feature::turn(){
	string response = get_name() + " cannot be turned\n";
	printf("%s\n", response.c_str());

}
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
void Feature::listen(){
	string response = get_name() + " cannot be listened to\n";
	printf("%s\n", response.c_str());


}//user to interact with some features or objects potentially
//will allow user to exit
void Feature::climb(){
	string response = get_name() + " cannot be climbed\n";
	printf("%s\n", response.c_str());


}//use to interact with some features to exit between rooms
void Feature::jump(){
	string response = get_name() + " cannot be jumped on or through\n";
	printf("%s\n", response.c_str());


}//user to interact with some features to exit between rooms
void Feature::attack(){
	string response = get_name() + " cannot be attacked\n";
	printf("%s\n", response.c_str());


}
int Feature::get_times_toggled(int function_id){
	return verb_func_toggled[function_id];
}

Feature::~Feature() {
	
}