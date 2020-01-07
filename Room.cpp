//
// Room.cpp
// Created by Claudia Rodriguez-Schroeder on 1/2/20.

#include "Room.h"
#include <string>
#include <cstdio>
#include <stdexcept>
Room::Room() {
	//printf("Constructing base class 'Room'\n");
	//printf("name %s\n", feature_1.name.c_str());
	set_next_room(666);
	set_exit_dir("No Direction");
}

Room::~Room() {
	//printf("Destroying pure virtual base class 'Room'\n");
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
	//printf("Setting long description\n");
	long_description = set_description;
	//printf("long_description: %s", long_description.c_str());
	
}

int Room::get_room_id(){
	return room_id;
}

void Room::set_room_id(int set_room_id){
	room_id = set_room_id;
}
Feature Room::get_feature_1(){
	return feature_1;
}
void Room::set_feature_1(Feature set_feature_1){
	feature_1 = set_feature_1;
}
Feature Room::get_feature_2(){
	return feature_2;
}
void Room::set_feature_2(Feature set_feature_2){
	feature_2 = set_feature_2;
}

string Room::get_exit(){
	return exit;
}
void Room::set_exit(string is_exit){
	exit = is_exit;
}

int Room::get_next_room(){
	return next_room;
}
void Room::set_next_room(int is_next_room){
	next_room = is_next_room;
}

int Room::get_room_entered(){
	return room_entered;
}
void Room::set_room_entered(int is_room_entered){
	room_entered = is_room_entered;
}

int Room::get_has_items(int is_has_items)
{
	return has_items[is_has_items];
}
void Room::set_all_has_items(int x){
	for (int i = 0; i < 8; i++){
		has_items[i]=x;
	}
}
void Room::toggle_has_items(int is_has_items){
	
	if (has_items[is_has_items]==0)
	{
		has_items[is_has_items]=1;
	}
	else {
		has_items[is_has_items]=0;
	}
	
}
void Room::init_long_short_desc(){
	string short_descr = "This is " + get_name() + "." + " You see " + get_exit() + " in the " + get_exit_dir() + ". You see " + get_feature_1().description + " and " + get_feature_2().description;
	string long_descr = "LONG DESC: This is " + get_name() + "." + " You see " + get_exit() + " in the " + get_exit_dir() +  ". You see " + get_feature_1().description + " and " + get_feature_2().description;
	set_short_description(short_descr);
	set_long_description(long_descr);
	
}

void Room::init_exits(){
	exit_1 = "go "+exit_direction;
	exit_2 = exit_direction;
	exit_3 = "go "+get_exit();
	exit_4 = get_exit();
}

string Room::get_alt_exp(int x){
	return alt_desc[x];
}
void Room::set_alt_exp(int x, string exper){
	alt_desc[x]=exper;
}


string Room::get_exit_dir(){
	return exit_direction;
}
void Room::set_exit_dir(string exit_dir){
	exit_direction = exit_dir;
}