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
	desc_without_obj = desc;
	desc_with_obj = desc;

	error_message = "feature error";
	index_id = -666;
	fixed = 1;
	//init
	look_count = 0;
	for (int i = 0; i < NUM_VERB_FUNCS; i++){
		verb_func_toggled[i]=0;
	}
		
}
string Feature::get_read_response(){
	return read_response;
}
void Feature::set_read_response(string rr){
	read_response = rr;
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
string Feature::get_desc_w_obj(){
	return desc_with_obj;
}
void Feature::set_desc_w_obj(string s_desc){
	desc_with_obj = s_desc;
}
	
string Feature::get_desc_no_obj(){
	return desc_without_obj;
}
void Feature::set_desc_no_obj(string s_desc){
	desc_without_obj = s_desc;
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
int Feature::look()//print description
{
	look_count = look_count + 1;
	printf("%s", desc.c_str());
	return 4;
}
int Feature::read(){
	string response = get_name() + " cannot be read";
	printf("%s", response.c_str());
	return 4;

}

int Feature::smell(){
	string response = get_name() + " cannot be smelled";
	printf("%s", response.c_str());
	return 4;

}
int Feature::use(int obj_feat_id){
	
	if (obj_feat_id != -1){
		string response = get_name() + " cannot be used with " + get_obj_name(obj_feat_id);
	printf("%s", response.c_str());
	}
	if (obj_feat_id == -1){
		string response = get_name() + " cannot be used without an object";
		printf("%s", response.c_str());
	}
	return 4;

}

int Feature::eat(){
	string response = get_name() + " cannot be eaten";
	printf("%s", response.c_str());
	return 4;

}
int Feature::play(){
	string response = get_name() + " cannot be played";
	printf("%s", response.c_str());
	return 4;

}
int Feature::open(int room_id, int feat_obj_id){
	
	if (feat_obj_id == -1)
	{
		string response = get_name() + " cannot be opened without an object";
		printf("%s", response.c_str());
	}
	if (feat_obj_id != -1){
		string response = get_name() + " cannot be opened with " + get_obj_name(feat_obj_id);
		printf("%s", response.c_str());

	}
	return 4;

}
int Feature::speak(){
	string response = get_name() + " cannot be spoken to";
	printf("%s", response.c_str());
	return 4;
}
int Feature::give(int room_id, int feat_obj_id){
	if (feat_obj_id != -1){
		string response = get_name() + " cannot be given to " + get_obj_name(feat_obj_id);
		printf("%s", response.c_str());
	}
	if (feat_obj_id == -1){
		string response = get_name() + " needs something to be given to.";
		printf("%s", response.c_str());
	}
	
	return 4;

}//user to interact with some features or objects potentially
//will allow user to exit
int Feature::climb(){
	string response = get_name() + " cannot be climbed. ";
	printf("%s", response.c_str());
	return 4;
}//use to interact with some features to exit between rooms
int Feature::attack(int obj_id){
	if (obj_id!=-1){
		string response = get_name() + " cannot be attacked in this manner. ";
			printf("%s", response.c_str());
			return 4;
	}
	else{
		printf("You can't just attack %s.", get_name().c_str());
	}
	return 4;
	
}

int Feature::get_times_toggled(int function_id){
	return verb_func_toggled[function_id];
}
void Feature::remove_object_desc(){
	 set_desc(get_desc_no_obj());
}
int Feature::get_attack_obj_id(){
	return attack_obj_id;
}
void Feature::set_attack_obj_id(int obj_id){
	attack_obj_id = obj_id;
}
void Feature::set_func_togg_count(int bin_arr[NUM_VERB_FUNCS]){
	for (int i = 0; i < NUM_VERB_FUNCS; i++){
		set_togg_count_x(i, bin_arr[i]);
	}
}
string Feature::get_func_togg_count(){
	string bin_str_arr="";
	for (int i = 0; i < NUM_VERB_FUNCS; i++){
		if (i<NUM_VERB_FUNCS-1){
			bin_str_arr=bin_str_arr + to_string(get_times_toggled(i))+", ";
		}
		else{
			bin_str_arr=bin_str_arr + to_string(get_times_toggled(i));
		}	
	}
	return bin_str_arr;
}
string Feature::get_obj_name(int x){
	return obj_list[x];
}
string Feature::get_room_name(int x)
{
	return room_list[x];
}

int Feature::get_time(){
	printf("used in clock");
	return 4;
}//return desc
void  Feature::set_time(int time){
	printf("used in clock");
}//return desc
string  Feature::get_time_str(){
	printf("used in clock");
	return "null";
}//
Feature::~Feature() {
	
}
