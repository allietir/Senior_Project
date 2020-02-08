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
		//set all game events triggered to not triggered
		for (int i = 0; i < NUM_EVENTS; i++){
			set_room_events_triggered(i, 0);
		}
}
void Game::event1()
{
	printf("The chandelair beings to flicker; the wind you've been sensing seems to pick up. Suddenly the room goes completely dark and %s only has time to gasp before you feel suddenly like you are being watched. The light turn back on. 'What the hell was that' you say, turning to look at %s. But %s is gone.\n You have to find %s. \n\n\n", FRIEND_NAME, FRIEND_NAME, FRIEND_NAME, FRIEND_NAME);
	set_game_events_triggered(0, 1);
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
		//init obj_location
		set_obj_location(i, room_obj_set[i]);
		
	}
	for (int i = 0; i < 8; i++){
		int room_id = room_needs_object1[i];
		r_array[room_id]->set_needs_objects(0, 1);
	}
	//init times rooms visited to 0
	for (int i = 0; i < NUM_ROOMS; i++){
		set_times_rooms_visited(i,0);
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
	//set room visited to 1; 
	set_times_rooms_visited(0, 1);

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
				printf("You need the %s to enter %s.\n", o_array[i]->get_name().c_str(), r_array[next_room]->get_name().c_str());
				return -1;
			}
			else{
				printf("Success, you have the %s require to enter this room.\n", o_array[i]->get_name().c_str());
			}
		}
	}
	return 0;
}

void Game::exit_room(int dir){
	
	
	int current_room = player1.get_current_room();
	printf("You are attempting to exit: %s\n", r_array[current_room]->get_name().c_str());
	
	int get_next_room = r_array[current_room]->get_exit_id(dir);
	if (get_next_room == -1){
		printf("Error: %s has no exit to the %s\n", r_array[current_room]->get_name().c_str(),  r_array[dir]->get_exit_dir(dir).c_str());
	}
	else
	{
		if (exit_valid(get_next_room)==0){
		
			printf("Success, there is an exit from the %s to the %s\n\n", r_array[current_room]->get_name().c_str(), r_array[dir]->get_exit_dir(dir).c_str());
			player1.set_current_room(get_next_room);
			//update player move count
			int mc = player1.get_move_count();
			mc = mc + 1;
			//update player move count
			player1.set_move_count(mc);
			//update state of knowing how many times a room has been visited
			set_times_rooms_visited(get_next_room, get_times_room_visited(get_next_room)+1);
				
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
Player* Game::get_player()
{
	return &player1;
}
void Game::set_player(Player* playerx){
	player1 = *playerx;
}
string Game::get_feat_list(int x){
	return feat_list[x];
}
void Game::output_feat_list(){
	for (int i = 0; i < TOTAL_FIXED; i++){
		printf("#define FEAT%i %s\n",i+1, get_feat_list(i).c_str());
	}
	for (int i = 0; i < TOTAL_FIXED; i++){
			printf("#define STR_FEAT%i \"%s\"\n",i+1, get_feat_list(i).c_str());
		}
	for (int i = 0; i < TOTAL_FIXED; i++){
		printf("\"%s\", ", get_feat_list(i).c_str());
	}

}
void Game::output_obj_list(){
	for (int i = 0; i < NUM_OBJECTS; i++){
			printf("\"%s\", ", o_array[i]->get_name().c_str());
		}
}
void Game::output_verb_list(){
	for (int i = 0; i < NUM_VERB_FUNCS; i++){
		string x = "STR_VERB";
		printf("%s%i, ", x.c_str(), i+1);
	}
}
int Game::feat_valid(int feat_index_id){
	if (r_array[player1.get_current_room()]->get_feature_x(0)->get_index_id()==feat_index_id){
		return 0;
	}
	else if (r_array[player1.get_current_room()]->get_feature_x(1)->get_index_id()==feat_index_id){
			return 1;
	}
	else 
	{
		return -1;
	}
	
}
int Game::verb_index_from_string(string verbx){
	for (int i = 0; i < NUM_STR_VERBS; i++){
		if (verbx==verb_list[i]){
			return i;
		}
	}
	return -1;
}
string Game::verb_string_from_index(int verbx){
	return verb_list[verbx];
}
//climb can only refer to FEATURES validly so get context_id from string 
int Game::run_func(int feat_index_id, int obj_index_id, int verb_id){
	
	int res = -666;
	string verb="unset";
	
	//everyone has to use VERB
	if ((verb_id>=0)&&(verb_id<=NUM_STR_VERBS-1)){
		verb = verb_list[verb_id];
	}
	else{
		//if verb is invalid, just leave
		printf("Verb Invalid\n");
		return -1;
	}
	int item=feat_valid(feat_index_id);
	string feat_string;
	if (item!=-1){
		feat_string=r_array[player1.get_current_room()]->get_feature_x(item)->get_name(); 
	}
	if ((feat_index_id!=-1)&&(obj_index_id==-1))
	{
		
		
		if ((item>=0)&&(item<=1)){
			printf("Running %s on on FEAT %s that does NOT take OBJECT in room %s\n", verb.c_str(), feat_string.c_str(), r_array[player1.get_current_room()]->get_name().c_str());
			if (verb.compare(STR_VERB1)==0){ res = r_array[player1.get_current_room()]->get_feature_x(item)->VERB1(); }
			else if (verb.compare(STR_VERB2)==0){ res = r_array[player1.get_current_room()]->get_feature_x(item)->VERB2(); }
			else if (verb.compare(STR_VERB4)==0){ res = r_array[player1.get_current_room()]->get_feature_x(item)->VERB4(); }
			else if (verb.compare(STR_VERB5)==0){ res = r_array[player1.get_current_room()]->get_feature_x(item)->VERB5(); }
			else if (verb.compare(STR_VERB7)==0){ res = r_array[player1.get_current_room()]->get_feature_x(item)->VERB7(); }
			else if (verb.compare(STR_VERB9)==0){ res = r_array[player1.get_current_room()]->get_feature_x(item)->VERB9(); }
		}
		


		
	}
	else if ((feat_index_id!=-1)&&(obj_index_id!=-1)){
		printf("Running %s on FEAT %s that DOES take OBJECT with object %s in room %s\n", verb.c_str(), feat_string.c_str(), o_array[obj_index_id]->get_name().c_str(), r_array[player1.get_current_room()]->get_name().c_str());
		if ((obj_index_id <= 7)&&(obj_index_id>=0)&&(item>=0)&&(item<=1))
		{
			if (verb.compare(STR_VERB3)==0){ res = r_array[player1.get_current_room()]->get_feature_x(item)->VERB3(obj_index_id); }
			else if (verb.compare(STR_VERB6)==0){ res = r_array[player1.get_current_room()]->get_feature_x(item)->VERB6(player1.get_current_room(), obj_index_id); }
			else if (verb.compare(STR_VERB8)==0){ res = r_array[player1.get_current_room()]->get_feature_x(item)->VERB8(player1.get_current_room(), obj_index_id); }
			else if (verb.compare(STR_VERB10)==0){ res = r_array[player1.get_current_room()]->get_feature_x(item)->VERB10(o_array[obj_index_id]->get_name()); }
		}
	}
	else if ((feat_index_id==-1)&&(obj_index_id!=-1)){
		printf("Running %s on OBJECT %s in room %s\n", verb.c_str(), o_array[obj_index_id]->get_name().c_str(), r_array[player1.get_current_room()]->get_name().c_str());
		if ((obj_index_id <= 7)&&(obj_index_id>=0))
		{
			if (verb.compare(STR_VERB1)==0){ res = o_array[obj_index_id]->VERB1(); }
			else if (verb.compare(STR_VERB2)==0){ res = o_array[obj_index_id]->VERB2(); }
			else if (verb.compare(STR_VERB3)==0){ res = o_array[obj_index_id]->VERB3(-1); }
			else if (verb.compare(STR_VERB4)==0){ res = o_array[obj_index_id]->VERB4(); }
			else if (verb.compare(STR_VERB5)==0){ res = o_array[obj_index_id]->VERB5(); }
			else if (verb.compare(STR_VERB6)==0){ res = o_array[obj_index_id]->VERB6(player1.get_current_room(), -1); }
			else if (verb.compare(STR_VERB7)==0){ res = o_array[obj_index_id]->VERB7(); }
			else if (verb.compare(STR_VERB8)==0){ res = o_array[obj_index_id]->VERB8(player1.get_current_room(), -1); }
			else if (verb.compare(STR_VERB9)==0){ res = o_array[obj_index_id]->VERB9(); }
			else if (verb.compare(STR_VERB10)==0){ res = o_array[obj_index_id]->VERB10(o_array[obj_index_id]->get_name()); }
			
		}	
		

	}
	if (res!=-666){	
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
	return -1;
	
	
}
//helper for parse
int Game::exit_current_from_room_id(int room_id){
	if ((room_id < 0)||(room_id > 14))
	{
		printf("Error: Invalid room id\n");
	}
	else{
		//check each exit_index
			int exit_room_id =-666;
			for (int i = 0; i < MAX_EXITS; i++){
				exit_room_id = r_array[player1.get_current_room()]->get_exit_id(i);
				if (exit_room_id == room_id){
					printf("you are attempting to move to %s from %s\n", r_array[room_id]->get_name().c_str(), r_array[player1.get_current_room()]->get_name().c_str());
					exit_room(i);
					return 0;
				}
			}
			printf("Error: cannot exit to %s from %s\n", r_array[room_id]->get_name().c_str(), r_array[player1.get_current_room()]->get_name().c_str());
	}
	
	return -1;
}
//LOAD HELPER
void Game::set_times_rooms_visited(int room_id, int new_time){
	times_rooms_visited[room_id]=new_time;
}
int Game::get_times_room_visited(int room_id){
	return times_rooms_visited[room_id];
}

void Game::set_all_times_rooms_visited(int bin_arr[NUM_ROOMS]){
	for (int i = 0; i < NUM_ROOMS; i++){
		set_times_rooms_visited(i, bin_arr[i]);
	}
}
string Game::get_all_times_rooms_visited(){
	string bin_str_arr="";
	for (int i = 0; i < NUM_ROOMS; i++){
		if (i<NUM_ROOMS-1){
			bin_str_arr=bin_str_arr + to_string(get_times_room_visited(i))+", ";
		}
		else{
			bin_str_arr=bin_str_arr + to_string(get_times_room_visited(i));
		}
		
	}
	return bin_str_arr;
}
void Game::set_game_events_triggered(int event_index, int val){
	if ((event_index>-1)&&(event_index<NUM_GAME_EVENTS)){
		game_events_triggered[event_index]=val;
	}
	
}
int Game::get_game_events_triggered(int event_index){
	return game_events_triggered[event_index];
}

void Game::set_room_events_triggered(int event_index, int val){
	if ((event_index>-1)&&(event_index<NUM_EVENTS)){
		room_events_triggered[event_index]=val;
	}
	int room_id = 666;
	if (event_index%3==0){
		room_id = event_index/3;
		room_id = room_id - 1;
		r_array[room_id]->set_event_triggered(2, 1);
	}
	else {
		room_id = event_index/3;
		int which_event = event_index%3;
		if (which_event == 2){
			r_array[room_id]->set_event_triggered(1, 1);
		}
		else {
			r_array[room_id]->set_event_triggered(0, 1);
		}
		
	}
	
}
int Game::get_room_events_triggered(int event_index){
	return room_events_triggered[event_index];
}
void Game::set_all_game_events_triggered(int bin_arr[NUM_GAME_EVENTS]){
	for (int i = 0; i < NUM_GAME_EVENTS; i++){
			set_game_events_triggered(i, bin_arr[i]);
		}
}
string Game::get_all_game_events_triggered(){
	string bin_str_arr="";
	for (int i = 0; i < NUM_GAME_EVENTS; i++){
		if (i<NUM_GAME_EVENTS-1){
			bin_str_arr=bin_str_arr + to_string(get_game_events_triggered(i))+", ";
		}
		else{
			bin_str_arr=bin_str_arr + to_string(get_game_events_triggered(i));
		}	
	}
	return bin_str_arr;
}

	
void Game::set_all_player_objects(int bin_arr[NUM_OBJECTS]){
	for (int i = 0; i < NUM_OBJECTS; i++){
		player1.set_has_objects(i, bin_arr[i]);
	}
}
string Game::get_all_player_objects(){
	string bin_str_arr="";
	for (int i = 0; i < NUM_OBJECTS; i++){
		if (i<NUM_OBJECTS-1){
			bin_str_arr=bin_str_arr + to_string(player1.get_has_objects(i))+", ";
		}
		else{
			bin_str_arr=bin_str_arr + to_string(player1.get_has_objects(i));
		}	
	}
	return bin_str_arr;
}

void Game::set_all_room_objects(int bin_arr[NUM_OBJECTS]){
	for (int i = 0; i < NUM_OBJECTS; i++){
			for (int j = 0; j < NUM_ROOMS; j++){
				if (j==bin_arr[i]){
					r_array[j]->set_has_objects(i, 1);
					
			}
			else{
				r_array[j]->set_has_objects(i, 0);
			}
			
		}
	}
}
string Game::get_all_room_objects(){
	
	string bin_str_arr="";
	//for each objects
	for (int i = 0; i < NUM_OBJECTS; i++){
		//check if object is in room
		for (int j = 0; j < NUM_ROOMS; j++){
			//if i < num_objects -1...
			if (i<NUM_OBJECTS-1){
				//check if r_array[j] has object
				if (r_array[j]->get_has_objects(i)==1){
					//output "j" room
					bin_str_arr=bin_str_arr + to_string(j)+", ";
				}
				
			}
			else{
				if (r_array[j]->get_has_objects(i)==1){
					//output "j" room
					bin_str_arr=bin_str_arr + to_string(j);
				}
			}	
		}
		
	}
	return bin_str_arr;
}

void Game::set_all_room_events_triggered(int bin_arr[NUM_EVENTS]){
	for (int i = 0; i < NUM_EVENTS; i++){
		set_room_events_triggered(i, bin_arr[i]);
		//set original room too
		
	}
	int x = 0; 
	for (int i = 0; i < NUM_ROOMS; i++){
		
		r_array[i]->set_event_triggered(0, bin_arr[i+x]);
		x = x + 1;
		r_array[i]->set_event_triggered(1, bin_arr[i+x]);
		x = x + 1;
		r_array[i]->set_event_triggered(2, bin_arr[i+x]);

		
	}
}
string Game::get_all_room_events_triggered(){
	string bin_str_arr="";
	for (int i = 0; i < NUM_EVENTS; i++){
		if (i<NUM_EVENTS-1){
			bin_str_arr=bin_str_arr + to_string(get_room_events_triggered(i))+", ";
		}
		else{
			bin_str_arr=bin_str_arr + to_string(get_room_events_triggered(i));
		}	
	}
	return bin_str_arr;
}

Game::~Game() {

}