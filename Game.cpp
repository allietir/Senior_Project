//
// Game.cpp
// Created by Claudia Rodriguez-Schroeder on 1/2/20.

#include "Game.h"
#include <cstdio>
#include <string>
#include <cstring>
#include <fstream>

Game::Game() {
	
}
void Game::init_rooms() {
	init_objects();
	//place individual rooms in the array
	r_array[0]=room_1;
	r_array[1]=room_2;
	r_array[2]=room_3;
//	r_array[3]=room_4;
//	r_array[4]=room_5;
//	r_array[5]=room_6;
//	r_array[6]=room_7;
//	r_array[7]=room_8;
//	r_array[8]=room_9;
//	r_array[9]=room_10;
//	r_array[10]=room_11;
//	r_array[11]=room_12;
//	r_array[12]=room_13;
//	r_array[13]=room_14;
//	r_array[14]=room_15;
	//add objects to array
	r_array[0].set_has_objects(0, 1);
	//add description
	r_array[0].add_object_text(o_array[0].get_name(), o_array[0].get_desc());
	
}
void Game::init_objects()
{

	//place individual 
	o_array[0]=object_1;
	
	
//	o_array[1]=object_2;
//	o_array[2]=object_3;
//	o_array[3]=object_4;
//	o_array[4]=object_5;
//	o_array[5]=object_6;
//	o_array[6]=object_7;
//	o_array[7]=object_8;
	for (int i = 0; i < NUM_OBJECTS; i++){
		o_array[i].set_index_id(i);
	}
}

void Game::start(){
	
	init_rooms();
	printf("Welcome %s\n", player1.get_name().c_str());
	printf("Current location is %s\n", r_array[player1.get_current_room()].get_name().c_str());
	
	string sd = r_array[player1.get_current_room()].look();
	printf("%s", sd.c_str());
	printf("%s", "-----GET INPUT FUNCTION HERE------");
}
//take implemented at game level, since objects are at game level
void Game::take(int object_id){
	//player 
	int p_has_item = player1.get_has_objects(object_id);
	int current_room = player1.get_current_room();
	int r_has_item = r_array[current_room].get_has_objects(object_id);
	//if item is in the room and the player does not have the item
	if ((p_has_item == 0)&&(r_has_item==1)){
		player1.set_has_objects(object_id, 1);
		r_array[current_room].set_has_objects(object_id, 0);
		set_obj_location(object_id, -1);
		printf("%s no longer has %s\n", r_array[current_room].get_name().c_str(), o_array[object_id].get_name().c_str());	
		printf("Updated player inventory:");
		inventory();
		
	}
	if (p_has_item == 1){
		printf("You already have this item");
	}
	else if (r_has_item == 0){
		printf("Item is not in this room");
	}

	
}
void Game::drop(int object_id){
	//player 
	int p_has_item = player1.get_has_objects(object_id);
	int current_room = player1.get_current_room();
	int r_has_item = r_array[current_room].get_has_objects(object_id);
	//if item is in the room and the player does not have the item
	if ((p_has_item == 1)&&(r_has_item==0)){
		player1.set_has_objects(object_id, 0);
		r_array[current_room].set_has_objects(object_id, 1);
		set_obj_location(object_id, -1);
		printf("%s now has %s\n", r_array[current_room].get_name().c_str(), o_array[object_id].get_name().c_str());	
		printf("Updated player inventory:");
		inventory();
		
	}
	if (p_has_item == 0){
		printf("You do not have this item");
	}
	else if (r_has_item == 1){
		printf("Item is already in this room");
	}

	
}
void Game::inventory(){
	printf("INVENTORY: ");
	for (int i = 0; i < NUM_OBJECTS; i++){
		if (player1.get_has_objects(i)==1){
			printf("%s\n ", o_array[i].get_name().c_str());
		}
	}
}
void Game::set_obj_location(int obj_id, int location){
	current_obj_location[obj_id]=location;
}
int Game::get_obj_location(int obj_id){
	return current_obj_location[obj_id];
}

Game::~Game() {

}