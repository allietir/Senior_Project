//
// Room.cpp
// Created by Claudia Rodriguez-Schroeder on 1/2/20.

#include "Room.h"
#include <string>
#include <cstdio>
#include <stdexcept>
Room::Room() {
	name = "nameless";
	
	short_description = "short desc";
	long_description = "long desc";
	extra_description = "extra desc";
	room_id = -100;
	for (int i = 0; i < MAX_EXITS; i++){
		exit_name[i]="no_exit";
		exit_ids[i]=-1;
		
	}
	exit_direction[0]="north";
	exit_direction[1]="south";
	exit_direction[2]="east";
	exit_direction[3]="west";
	
	init_exits();
	room_entered = 0;
	for (int i = 0; i < NUM_OBJECTS; i++){
		has_objects[i]=0;
	}
	obj_count = 0;
	num_exits = get_num_exits();
	init_long_short_desc();

}
string Room::get_name(){
	return name;
}
void Room::set_name(string set_name ){
	name = set_name;
}
string Room::get_short_description(){
	return short_description;
}
void Room::set_short_description(string set_description){
	short_description = set_description;
}
string Room::get_long_description(){
	return long_description;
}
void Room::set_long_description(string set_description){
	long_description = set_description;
}

string Room::get_extra_description(){

	return extra_description;
}
void Room::set_extra_description(string set_description){
	extra_description = set_description;
}

int Room::get_room_id(){
	return room_id;
}
void Room::set_room_id(int set_room_id){
	room_id = set_room_id;
}
Feature Room::get_feature_x(int x){
	return fixed_list[x];
}
void Room::set_feature_x(Feature set_feature_x, int x){
	fixed_list[x]=set_feature_x;
	//make sure it is set to fixed
	fixed_list[x].set_fixed(1);
}
string Room::get_exit_name(int direction){
	return exit_name[direction];
}
void Room::set_exit_name(string s_exit_name, int direction){
	exit_name[direction] = s_exit_name;
}
string Room::get_exit_dir(int exit_index){
	return exit_direction[exit_index];
}
void Room::set_exit_dir(string exit_dir, int exit_index){
	exit_direction[exit_index] = exit_dir;
}
string Room::get_exit_x(int direction, int x){
	if (x == 1){
		return exit_1[direction];
	}
	if (x==2){
		return exit_2[direction];
	}
	if (x==3){
		return exit_3[direction];
	}
	if (x==4){
		return exit_4[direction];
	}
	string no_exit="no_exit";
	return no_exit;
}
void Room::init_exits(){

	for (int i = 0; i < MAX_EXITS; i++){
		
		exit_1[i] = "go "+get_exit_dir(i);
		exit_2[i] = get_exit_dir(i);
		exit_3[i] = "go "+get_exit_name(i);
		exit_4[i] = get_exit_name(i);

	}
}
int Room::get_room_entered(){
	return room_entered;
}
void Room::set_room_entered(int s_room_entered){
	room_entered = s_room_entered;
}

int Room::get_has_objects(int object_index)
{
	return has_objects[object_index];
}
void Room::set_has_objects(int object_index, int val)
{
	has_objects[object_index]=val;
}
int Room::get_num_exits(){
	num_exits=0;
	for (int i = 0; i < MAX_EXITS; i++){
		if (exit_name[i]!="no_exit"){
			num_exits = num_exits + 1;
			
		}
		
	}
	return num_exits;
}
string Room::exit_text(){
	string exit_text = "You see: ";
	for (int i = 0; i < MAX_EXITS; i++){
		string exit_x = get_exit_name(i);
		if (exit_x !="no_exit"){
			exit_text = exit_text + exit_x + " in the " + get_exit_dir(i);
		}
		
	}
	return exit_text;
}
string Room::feature_text(){
	
	string feature_text = "You see: ";
	for (int i = 0; i < MAX_FIXED; i ++){
		if ((fixed_list[i].get_name()!="no feature name")&&(i<MAX_FIXED-1)){
			feature_text = feature_text + fixed_list[i].get_desc() + "and ";
		}
		if ((fixed_list[i].get_name()!="no feature name")&&(i==MAX_FIXED-1)){
			feature_text = feature_text + fixed_list[i].get_desc() + ".\n";
		}

	}
	return feature_text;
	
}
void Room::add_object_text(string name, string desc){
	string new_short_descs = get_short_description() + "You see: a " + name +  ". ";
	set_short_description(new_short_descs);
	
	string new_long_descs = get_long_description() + "You see: " + desc + ".";
	set_long_description(new_long_descs);
}
void Room::init_long_short_desc(){
	string short_descr = "This is " + get_name() + ". " + exit_text() + ".  " + feature_text();
	string long_descr = "This is " + get_name() + ". " + get_extra_description() + exit_text() + ". "+ feature_text();
	set_short_description(short_descr);
	set_long_description(long_descr);
	
}

int Room::get_num_obj()
{
	obj_count = 0;
	for (int i = 0; i < NUM_OBJECTS; i++){
		if (has_objects[i]==1){
			obj_count = obj_count + 1;
		}
	}
	return obj_count;
}
int Room::get_exit_id(int exit_index){
	return exit_ids[exit_index];
}
void Room::set_exit_id(int room_id, int exit_index){
	exit_ids[exit_index]=room_id;
}
string Room::look(){
	if (room_entered == 1)
	{
		return short_description;
		
	}
	else {
		room_entered = 1;

		return long_description;
			}
	return "error";
}
Room::~Room() {
	//printf("Destroying pure virtual base class 'Room'\n");
}