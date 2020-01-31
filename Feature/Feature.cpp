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
string Feature::look()//retunr description
{
	look_count = look_count + 1;
	return desc;
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

string Feature::read(){
	string read_response = get_name() + " cannot be read\n";
	verb_func_toggled[0]=verb_func_toggled[0]+1;
	return read_response;
}

string Feature::pull(){
	string read_response = get_name() + " cannot be pulled\n";
	verb_func_toggled[1]=verb_func_toggled[2]+1;
	return read_response;
}
string Feature::push(){
	string read_response = get_name() + " cannot be pushed\n";
	verb_func_toggled[2]=verb_func_toggled[2]+1;
	return read_response;
}
string Feature::turn(){
	string read_response = get_name() + " cannot be turned\n";
	verb_func_toggled[3]=verb_func_toggled[3]+1;
	return read_response;

}
string Feature::peel(){
	string read_response = get_name() + " cannot be peeled\n";
	verb_func_toggled[4]=verb_func_toggled[4]+1;
	return read_response;

}
string Feature::pet(){
	string read_response = get_name() + " cannot be pet\n";
	verb_func_toggled[5]=verb_func_toggled[5]+1;
	return read_response;
}//for cat features
string Feature::speak(){
	string read_response = get_name() + " cannot be spoken to\n";
	verb_func_toggled[6]=verb_func_toggled[6]+1;
	return read_response;

}//talk to a feature or object 
string Feature::listen(){
	string read_response = get_name() + " cannot be listened to\n";
	verb_func_toggled[7]=verb_func_toggled[7]+1;
	return read_response;

}//user to interact with some features or objects potentially
//will allow user to exit
string Feature::climb(){
	string read_response = get_name() + " cannot be climbed\n";
	verb_func_toggled[8]=verb_func_toggled[8]+1;
	return read_response;

}//use to interact with some features to exit between rooms
string Feature::jump(){
	string read_response = get_name() + " cannot be jumped on or through\n";
	verb_func_toggled[9]=verb_func_toggled[9]+1;
	return read_response;

}//user to interact with some features to exit between rooms
string Feature::consider(){
	string read_response = get_name() + " cannot be considered\n";
	verb_func_toggled[10]=verb_func_toggled[10]+1;
	return read_response;

}

Feature::~Feature() {
	
}