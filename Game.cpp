//
// Game.cpp
// Created by Claudia Rodriguez-Schroeder on 1/2/20.

#include "Game.h"
#include <cstdio>
#include <string>
#include <cstring>
#include <fstream>

Game::Game() {
		init_rooms();
}
void Game::event1()
{
	printf("The chandelair beings to flicker; the wind you've been sensing seems to pick up. Suddenly the room goes completely dark and %s only has time to gasp before you feel suddenly like you are being watched. The light turn back on. 'What the hell was that' you say, turning to look at %s. But %s is gone.\n You have to find %s. \n\n\n", FRIEND_NAME, FRIEND_NAME, FRIEND_NAME, FRIEND_NAME);
}
void Game::init_rooms() {
	init_objects();
	//place individual rooms in the array
	r_array[0]= new Room1;
	r_array[1]= new Room2;
	r_array[2]= new Room3;
	r_array[3]= new Room4;
	r_array[4]= new Room5;
	r_array[5]= new Room6;
	r_array[6]= new Room7;
	r_array[7]= new Room8;
	r_array[8]= new Room9;
	r_array[9]= new Room10;
	r_array[10]= new Room11;
	r_array[11]= new Room12;
	r_array[12]= new Room13;
	r_array[13]= new Room14;
	r_array[14]= new Room15;

	//add objects to array
	//int room_obj_set[]={1, 3, 10, 6, 0, 11, 5, 9};
	for (int i = 0; i < NUM_OBJECTS; i++){
		int room_id = room_obj_set[i];
		
		r_array[room_id]->set_has_objects(i, 1);
		//only add object text after object is LOOKED at
		//r_array[room_id]->add_object_text(o_array[i]->get_name(), o_array[i]->get_desc());
		if (r_array[room_id]->get_has_objects(i)==1){
			//printf("%s now has %s\n", r_array[room_id]->get_name().c_str(), o_array[i]->get_name().c_str());
		}
		
	}
	//int room_needs_object1[]={2, 3, 4, 5, 6, 7, 8, 13};
	for (int i = 0; i < 8; i++){
		int room_id = room_needs_object1[i];
		//printf("setting %s to require %s\n", r_array[room_id]->get_name().c_str(), o_array[0]->get_name().c_str());
		r_array[room_id]->set_needs_objects(0, 1);
		/*if (r_array[room_id]->get_needs_objects(0)==1){
			printf("%s now needs %s\n", r_array[room_id]->get_name().c_str(), o_array[0]->get_name().c_str());
		}*/
	}
	
	
//	r_array[0]->set_has_objects(0, 1);//entrance has oilamp
//	r_array[3]->set_has_objects(1, 1);//dining room has diary
//	r_array[10]->set_has_objects(2, 1);//library has crystal ball 
//	r_array[6]->set_has_objects(3, 1);//guest bedroom has sheet music
//	r_array[7]->set_has_objects(4, 1);//master bedroom has gilded dagger'
//	r_array[11]->set_has_objects(5, 1);//conservatory has doll
//	r_array[5]->set_has_objects(6, 1);//nursuery has chest key
//	r_array[9]->set_has_objects(7, 1);//attick has silver challice
	//add description
//	r_array[0]->add_object_text(o_array[0]->get_name(), o_array[0]->get_desc());
//	//add description
//	r_array[3]->add_object_text(o_array[2]->get_name(), o_array[2]->get_desc());	
}
void Game::init_objects()
{
	//place individual 
	o_array[0]= new Object1;
	o_array[1]= new Object2;
	o_array[2]= new Object3;
	o_array[3]= new Object4;
	o_array[4]= new Object5;
	o_array[5]= new Object6;
	o_array[6]= new Object7;
	o_array[7]= new Object8;

}

void Game::start(){
	

	printf("Welcome %s\n", player1.get_name().c_str());
	printf("Current location is %s\n", r_array[player1.get_current_room()]->get_name().c_str());
	
	r_array[player1.get_current_room()]->look();

	printf("%s", "-----GET INPUT FUNCTION HERE------");
}
//take implemented at game level, since objects are at game level
void Game::take(int object_id){
	//player 
	int p_has_item = player1.get_has_objects(object_id);
	int current_room = player1.get_current_room();
	int r_has_item = r_array[current_room]->get_has_objects(object_id);
	//if item is in the room and the player does not have the item
	if ((p_has_item == 0)&&(r_has_item==1)){
		player1.set_has_objects(object_id, 1);
		r_array[current_room]->set_has_objects(object_id, 0);
		set_obj_location(object_id, -1);
		printf("%s no longer has %s\n", r_array[current_room]->get_name().c_str(), o_array[object_id]->get_name().c_str());	
		printf("Updated player inventory:");
		inventory();
		printf("\n");
		//update room description:
		r_array[current_room]->remove_object_text();
		//update feature description:
		r_array[current_room]->get_feature_x(0)->remove_object_desc();
		r_array[current_room]->get_feature_x(1)->remove_object_desc();
	}
	if (p_has_item == 1){
		printf("You already have this item\n");
	}
	else if (r_has_item == 0){
		printf("Item is not in this room\n");
	}

	
}
//trigger take event
//void Game::check_take_event(int obj_id, int room_id){
//	//check initail array;
//	//if this is the room the object was taken in...
//	if (room_obj_set[obj_id]==room_id){
//		if (r_array[room_id]->get_event_triggered(0)==0){
//			r_array[room_id]->event_one();
//		}
//		
//	}
//	
//}
void Game::drop(int object_id){
	//player 
	int p_has_item = player1.get_has_objects(object_id);
	int current_room = player1.get_current_room();
	int r_has_item = r_array[current_room]->get_has_objects(object_id);
	//if item is in the room and the player does not have the item
	if ((p_has_item == 1)&&(r_has_item==0)){
		player1.set_has_objects(object_id, 0);
		r_array[current_room]->set_has_objects(object_id, 1);
		set_obj_location(object_id, -1);
		printf("%s now has %s\n", r_array[current_room]->get_name().c_str(), o_array[object_id]->get_name().c_str());	
		printf("Updated player inventory:");
		inventory();
		//add object text
		r_array[current_room]->add_object_text(o_array[object_id]->get_name(), o_array[object_id]->get_desc());
		
		
	}
	if (p_has_item == 0){
		printf("You do not have this item\n");
	}
	else if (r_has_item == 1){
		printf("Item is already in this room\n");
	}

	
}
void Game::inventory(){
	printf("INVENTORY: ");
	for (int i = 0; i < NUM_OBJECTS; i++){
		if (player1.get_has_objects(i)==1){
			printf("%s\n ", o_array[i]->get_name().c_str());
		}
	}
}
void Game::set_obj_location(int obj_id, int location){
	current_obj_location[obj_id]=location;
}
int Game::get_obj_location(int obj_id){
	return current_obj_location[obj_id];
}
int Game::exit_valid(int next_room)
{
	for (int i = 0; i < NUM_OBJECTS; i++){
		if (r_array[next_room]->get_needs_objects(i)==1){
			int has_obj = player1.get_has_objects(i);
			if (has_obj!=1){
				printf("You need the %s to enter this room.", o_array[i]->get_name().c_str());
				return -1;
			}
		}
	}
	return 0;
}
//void Game::exit_r1_r8(){
//	
//	player1.set_current_room(7);
//	printf("You are entering: %s\n", r_array[7]->get_name().c_str());
//	r_array[7]->look();
//}

void Game::exit_room(int dir){
	
	
	//update player move count
	int mc = player1.get_move_count();
	mc = mc + 1;
	player1.set_move_count(mc);
		
	//update player
	if (player1.get_move_count()==2){
		
		event1();
	}
	int current_room = player1.get_current_room();
	printf("You are exiting: %s\n", r_array[current_room]->get_name().c_str());
	
	int get_next_room = r_array[current_room]->get_exit_id(dir);
	if (get_next_room == -1){
		printf("%s has no exit to the %s\n", r_array[current_room]->get_name().c_str(),  r_array[current_room]->get_exit_dir(dir).c_str());
	}
	else
	{
		if (exit_valid(get_next_room)==0){
			printf("Success, you have the object required to enter the next room.\n\n");
			player1.set_current_room(get_next_room);
			//intro room
			current_room = player1.get_current_room();
			printf("You are entering: %s\n", r_array[current_room]->get_name().c_str());
			r_array[current_room]->look();
		}
		else{
			printf("------Failure----\n");
		}
		
	}

}
void Game::look(){
	r_array[player1.get_current_room()]->look();
}
void Game::climb(int feature_x){

	int get_next_room = r_array[player1.get_current_room()]->get_feature_x(feature_x)->climb();
	if (get_next_room != -1){
		player1.set_current_room(get_next_room);
		//intro room
		int current_room = player1.get_current_room();
		printf("You are entering: %s\n", r_array[current_room]->get_name().c_str());
		r_array[current_room]->look();
	}
}/*
void Game::jump(int feature_x){

	int get_next_room = r_array[player1.get_current_room()]->get_feature_x(feature_x)->jump();
	if (get_next_room != -1){
		player1.set_current_room(get_next_room);
		//intro room
		int current_room = player1.get_current_room();
		printf("You are entering: %s\n", r_array[current_room]->get_name().c_str());
		r_array[current_room]->look();
	}
}*/
int Game::attack(int feature_x, int obj_id){
	
	//get attack item
	//if you attack with the correct object..
	int needed_object = r_array[player1.get_current_room()]->get_feature_x(feature_x)->get_attack_obj_id();
	if (player1.get_has_objects(obj_id)){
		if (obj_id==needed_object)
			{
				int get_attack_result=r_array[player1.get_current_room()]->get_feature_x(feature_x)->attack(o_array[obj_id]->get_name());
				if (get_attack_result == -1){
					//player dead, game over, exit game totally. 
					player1.set_player_alive(0);
					printf("------GAME OVER; YOU HAVE DIED------\n");
					return -1;
					
					
				}
				else if (get_attack_result == 0){
					//
					//nothin
				}
				else if (get_attack_result == 1)
				{
					printf("You won!");
				}
			}
			else{
				printf("You can't attack with %s", o_array[obj_id]->get_name().c_str());
			}
	
	}
	else{
		printf("you don't have the %s", o_array[needed_object]->get_name().c_str());
	}
	return 0;
}
int Game::get_context_id_from_string(string feat_name){
	for (int i = 0; i < MAX_FIXED; i++){
		if (r_array[player1.get_current_room()]->get_feature_x(i)->get_name().compare(feat_name)==0){
			return i;
		}
	}
	return -1;
}
int Game::get_obj_id_from_string(string obj_name){
	for (int i = 0; i < NUM_OBJECTS; i++){
		if (o_array[i]->get_name().compare(obj_name))
		{
			return o_array[i]->get_index_id();
		}
	}
	return -1;
}
//helper for parse
Game::~Game() {

}