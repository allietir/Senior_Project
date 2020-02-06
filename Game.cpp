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
	for (int i = 0; i < NUM_OBJECTS; i++){
		int room_id = room_obj_set[i];
		
		r_array[room_id]->set_has_objects(i, 1);
		
	}
	for (int i = 0; i < 8; i++){
		int room_id = room_needs_object1[i];
		r_array[room_id]->set_needs_objects(0, 1);
	}
	
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

	gen_feat_list();
}
//take implemented at game level, since objects are at game level
void Game::take(int object_id){
	//player 
	if (player1.get_can_take()==1){
		int p_has_item = player1.get_has_objects(object_id);
			int current_room = player1.get_current_room();
			int r_has_item = r_array[current_room]->get_has_objects(object_id);
			//if item is in the room and the player does not have the item
			if ((p_has_item == 0)&&(r_has_item==1)){
				player1.set_has_objects(object_id, 1);
				r_array[current_room]->set_has_objects(object_id, 0);
				set_obj_location(object_id, -1);
				printf("%s no longer has %s\n", r_array[current_room]->get_name().c_str(), o_array[object_id]->get_name().c_str());	
				printf("Updated player inventory...\n");
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
	else{
		printf("You can't take %s right now.\n", o_array[object_id]->get_name().c_str());
	}
	

	
}
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
		printf("Updated player inventory...\n");
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
	int empty = 1;
	printf("INVENTORY: \n");
	for (int i = 0; i < NUM_OBJECTS; i++){
		if (player1.get_has_objects(i)==1){
			printf("%s\n ", o_array[i]->get_name().c_str());
			empty = 0;
		}
	}
	if (empty)
	{
		printf("(empty)\n");
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

void Game::exit_room(int dir){
	
	
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
			//update player move count
			int mc = player1.get_move_count();
			mc = mc + 1;
			player1.set_move_count(mc);
				
			//update player
			if (player1.get_move_count()==2){
				
				event1();
			}

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
}
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
int Game::kill_player(){
	player1.set_player_alive(0);
	return 0;
}
void Game::gen_feat_list(){
	int x = 0 ;
	for (int i = 0; i < NUM_ROOMS; i++){
		
		feat_list[x]=r_array[i]->get_feature_x(0)->get_name();
		//printf("%s", feat_list[x].c_str());
		feat_list[x+1]=r_array[i]->get_feature_x(1)->get_name();
		//printf("%s", feat_list[x+1].c_str());
		x = x + 2;
		
	}
	
}
string Game::get_feat_list(int x){
	return feat_list[x];
}
void Game::output_feat_list(){
	for (int i = 0; i < TOTAL_FIXED; i++){
		printf("%i:%s\n",i, get_feat_list(i).c_str());
	}
}
//climb can only refer to FEATURES validly so get context_id from string 
int Game::run_func(string item, string obj_name, string verb){
	int res = -666;
	if (verb.compare(STR_VERB1)==0){ res = r_array[player1.get_current_room()]->get_feature_x(get_context_id_from_string(item))->VERB1(); }
	else if (verb.compare(STR_VERB2)==0){ res = r_array[player1.get_current_room()]->get_feature_x(get_context_id_from_string(item))->VERB2(); }
	else if (verb.compare(STR_VERB3)==0){ res = r_array[player1.get_current_room()]->get_feature_x(get_context_id_from_string(item))->VERB3(); }
	else if (verb.compare(STR_VERB4)==0){ res = r_array[player1.get_current_room()]->get_feature_x(get_context_id_from_string(item))->VERB4(); }
	else if (verb.compare(STR_VERB5)==0){ res = r_array[player1.get_current_room()]->get_feature_x(get_context_id_from_string(item))->VERB5(); }
	else if (verb.compare(STR_VERB6)==0){ res = r_array[player1.get_current_room()]->get_feature_x(get_context_id_from_string(item))->VERB6(player1.get_current_room(), get_obj_id_from_string(obj_name)); }
	else if (verb.compare(STR_VERB7)==0){ res = r_array[player1.get_current_room()]->get_feature_x(get_context_id_from_string(item))->VERB7(); }
	else if (verb.compare(STR_VERB8)==0){ res = r_array[player1.get_current_room()]->get_feature_x(get_context_id_from_string(item))->VERB8(player1.get_current_room(), get_obj_id_from_string(obj_name)); }
	else if (verb.compare(STR_VERB9)==0){ res = r_array[player1.get_current_room()]->get_feature_x(get_context_id_from_string(item))->VERB9(); }
	else if (verb.compare(STR_VERB10)==0){ res = r_array[player1.get_current_room()]->get_feature_x(get_context_id_from_string(item))->VERB10(obj_name); }

	printf("RES: %i\n", res);
	if ((res==0)||(res==1)||(res==2)){
		//rach player can have max 3 events, so get result (event 0->1, 1->2, 2->3), plus 3 times the current room you are in to set the value to EVENT TRIGGERED 
		room_events_triggered[res+(3*player1.get_current_room())]=1;
	}
	//player is DEAD
	else if (res==-1){
		player1.set_player_alive(0);//set to FALSE
	}
	//player can't TAKE anything
	if (res==-2){
		player1.set_can_take(0);//set to FALSE
	}
	//if anything else happens, the lock on take is nullified
	else
	{
		player1.set_can_take(1);//set to TRUE
	}
	if (res==4){
		//nothing happens; four is the "nothing" value
	}
	if (res==5){
		printf("----something unexpected has occured----\n");
	}
	return 0;
	
}
//helper for parse
Game::~Game() {

}