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
	event8counter = 0;
	
}
void Game::event1()
{
	printf("The chandelair beings to flicker; the wind you've been sensing seems to pick up. Suddenly the room goes completely dark and %s only has time to gasp before you feel suddenly like you are being watched. The light turn back on. 'What the hell was that' you say, turning to look at %s. But %s is gone.\n You have to find %s. \n\n\n", FRIEND_NAME, FRIEND_NAME, FRIEND_NAME, FRIEND_NAME);
	set_game_events_triggered(0, 1);
}
void Game::event2(){
	printf("You give the child the doll. She releases the locket\n");
	set_game_events_triggered(1, 1);
	//unlock locket 
	set_is_locked(LOCKET, 0);
	//lock doll
	set_is_locked(DOLL, 1);

}
void Game::event3(){
	printf("You can try to take the doll and maybe return it to the girl.\n");
	set_game_events_triggered(2, 1);
	//unlock doll
	set_is_locked(DOLL, 0);
	
}
void Game::event4(){
	printf("----------You have freed your friend and won the game! Objective completed-----.\n");
	set_game_events_triggered(3, 1);
}
void Game::event5(){
	printf("----------You have re-united the ghost family! Side quest completed--------.\n");
	set_game_events_triggered(4, 1);
}
void Game::event6(int obj_id){
	printf("-------You have destroyed the %s-------\n", o_array[obj_id]->get_name().c_str());
	set_game_events_triggered(5, 1);
	int curr_room = player1.get_current_room();
	player1.set_current_room(LIBRARY);
	drop(obj_id);
	player1.set_current_room(curr_room);
	set_is_locked(obj_id, 1);
}

void Game::event7(){
	set_game_events_triggered(6, 1);
	o_array[LOCKET]->open(CRYPT, -1);
}

void Game::event8(){
	set_game_events_triggered(7, 1);
	event8counter = 1;
}
void Game::event9(){
	for (int i = 0; i < NUM_OBJECTS; i++){
		
		if (get_is_locked(i)==0){
			current_obj_location[i]=KITCHEN;
			r_array[KITCHEN]->set_has_objects(i, 1);
		}
	}
	string x = concat_obj_descs();
	string desc = "The cupboard now has the following items within it:" + x;
	r_array[KITCHEN]->get_feature_x(1)->set_desc(desc);
	look();
	set_game_events_triggered(8, 1);
	
}
void Game::event10(){
	output_current_object_locations();
	set_game_events_triggered(9, 1);
}
void Game::event11(){
	output_feature_list_locations();
	set_game_events_triggered(10, 1);
}
void Game::event12(){
	string x = o_array[DIARY]->get_read_response() + ret_curr_feat_list() + ret_curr_obj_loc();
	o_array[DIARY]->set_read_response(x);
	set_game_events_triggered(11, 1);
}
void Game::event13(){
	r_array[UPSTAIRS]->trigger_event(0);
	get_player()->set_current_room(UPSTAIRS);
}
void Game::output_current_object_locations(){
	string str = ret_curr_obj_loc();
	printf("%s", str.c_str());
}
string Game::ret_curr_obj_loc(){
	string str = "";
	int curr_room;
	string room_name;
	string obj_name;
	for (int i = 0; i < NUM_OBJECTS; i++){
		curr_room = current_obj_location[i];
		obj_name = o_array[i]->get_name();
		if (curr_room!=-1){
			room_name = r_array[curr_room]->get_name();
			
			str = str + "The " + obj_name + " is in the " + room_name + ".\n";
		}
		else if (curr_room==-1){
			str = str + "The " + obj_name + " is in your inventory\n";
		}
		
	}
	return str;
}
void Game::output_feature_list_locations(){
	
	string str = ret_curr_feat_list();
	printf("%s", str.c_str());
}
string Game::ret_curr_feat_list(){
	string str = "";

	string room_name;
	string feat_name0;
	string feat_name1;
	
	for (int i = 0; i < NUM_ROOMS; i++){
		
		room_name = r_array[i]->get_name();
		feat_name0 = r_array[i]->get_feature_x(0)->get_name();
		feat_name1 = r_array[i]->get_feature_x(1)->get_name();
		str = str + "The " + feat_name0 + " is in the " + room_name + ".\n";
		str = str + "The " + feat_name1 + " is in the " + room_name + ".\n";
	}
	return str;
}
string Game::concat_obj_descs(){
	string x = "";
	for (int i = 0; i < NUM_OBJECTS; i++){
		if (current_obj_location[i]==player1.get_current_room()){
			x = x + o_array[i]->get_name() + "\n";
		}
	}
	return x;
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
	//TO DO: set "needs event" to open room
	//init times rooms visited to 0
	for (int i = 0; i < NUM_ROOMS; i++){
		set_times_rooms_visited(i,0);
	}
	gen_feat_list();
}
void Game::trigger_take_event(int obj_id){
	int room_id = room_obj_set[obj_id];
	printf("=========room_id: %i========\n", room_id);

	r_array[room_id]->trigger_event(0);
	int event_index = (3*player1.get_current_room());
	printf("=====triggering %i=====", event_index);
	room_events_triggered[event_index]=1;
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
	//set game events to 0;
	set_game_events_triggered(0, 0);

	printf("%s\n", "-----GET INPUT FUNCTION HERE------");

}
//take implemented at game level, since objects are at game level
void Game::take(int object_id){
	//player 
	//
	printf("----we are in take----");
	if (is_locked[object_id]==0){
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
					
					//update feature description:
					r_array[current_room]->get_feature_x(0)->remove_object_desc();
					r_array[current_room]->get_feature_x(1)->remove_object_desc();
					//reinitialize room description
					r_array[current_room]->init_long_short_desc();
					printf("get_event_triggerd: %i\n", r_array[player1.get_current_room()]->get_event_triggered(0));
					if (r_array[player1.get_current_room()]->get_event_triggered(0)==0){
						printf("triggering event");
						trigger_take_event(object_id);
					}
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
	else{
		printf("You can't take %s right now.\n", o_array[object_id]->get_name().c_str());
	}
	if (get_game_events_triggered(8)==1){
		//if the cupboard is open, user can take one object; then the cupboard will close again and description will reset; AND all items except that which the user has grabbed will be set back to their original location
		for (int i = 0; i < NUM_OBJECTS; i++){
			if (i!=object_id){
				current_obj_location[i]=room_obj_set[i];
			}
		}
	
		r_array[KITCHEN]->get_feature_x(1)->set_desc(r_array[KITCHEN]->get_feature_x(1)->get_desc_no_obj());
		r_array[KITCHEN]->get_feature_x(0)->set_desc(r_array[KITCHEN]->get_feature_x(0)->get_desc_no_obj());
		r_array[KITCHEN]->init_long_short_desc();
	}
	if (get_game_events_triggered(11)==1){
		event12();
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
		set_obj_location(object_id, current_room);
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
	if (get_game_events_triggered(11)==1){
		event12();
	}

	
}

void Game::inventory(){
	int empty = 1;
	printf("INVENTORY: \n");
	for (int i = 0; i < NUM_OBJECTS; i++){
		if (player1.get_has_objects(i)==1){
			printf("%s\n", o_array[i]->get_name().c_str());
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
	//Check that user has objects needed
	for (int i = 0; i < NUM_OBJECTS; i++){
		
		if (r_array[next_room]->get_needs_objects(i)==1){
			int has_obj = player1.get_has_objects(i);
			if (has_obj!=1){
				printf("You need the %s to enter %s.\n", o_array[i]->get_name().c_str(), r_array[next_room]->get_name().c_str());
				
				return -1;
			}
			else{
				if (i==LAMP){
					//make sure player turned lamp on
					if (o_array[LAMP]->get_times_toggled(USE)>=1){
						printf("Success, you have the %s require to enter this room.\n", o_array[i]->get_name().c_str());
					}
					else{
						printf("Perhaps turn on the lamp before venturing into the darkness.\n");
						return -1;
					}
				}
				

			}
		}
	}
	//check that certain events have been triggered
	printf("needs event: %i", get_needs_event(next_room));
	printf("value of needs event %i is %i:", get_needs_event(next_room), room_events_triggered[get_needs_event(next_room)]);
	if (get_needs_event(next_room)!=-1){
		
		if (room_events_triggered[get_needs_event(next_room)]==1){
				printf("The correct event has been triggered to allow you to enter this room.\n");
				return 0;

			}
			else{
				printf("You need to trigger the correct event to allow you to enter this room\n");
				return -1;
			}
	}
	else{
		return 0;
	}
	
	
	return -1;
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
			//update clock in upstairs hallway
			r_array[UPSTAIRS]->get_feature_x(0)->set_time(mc);
			r_array[UPSTAIRS]->init_long_short_desc();
		
			//update state of knowing how many times a room has been visited
			set_times_rooms_visited(get_next_room, get_times_room_visited(get_next_room)+1);
				
			//update player
			if (player1.get_move_count()==2){
				
				event1();
			}
			if (player1.get_move_count()==15){
				
				event13();
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
				int get_attack_result=r_array[player1.get_current_room()]->get_feature_x(feature_x)->attack(obj_id);
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
void Game::output_room_list(){
	for (int i = 0; i < NUM_ROOMS; i++){
		printf("\"%s\", ", r_array[i]->get_name().c_str());
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

Room* Game::get_room_x(int x){
	return r_array[x];
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
int Game::user_or_room_has_item(int obj_id){
	if ((player1.get_has_objects(obj_id)==1)||(r_array[player1.get_current_room()]->get_has_objects(obj_id))==1){
		return 1;
	}
	return 0;
}
int Game::user_has_item(int obj_id){
	return player1.get_has_objects(obj_id);
}
int Game::room_has_item(int obj_id){
	return r_array[player1.get_current_room()]->get_has_objects(obj_id);
}
//climb can only refer to FEATURES validly so get context_id from string 
int Game::run_func(int feat_index_id, int obj_index_id, int verb_id){
	//printf("=============Running Func==========\n%i %i %i\n", feat_index_id, obj_index_id, verb_id);
	int res = -666;
	string verb="unset";
	
	//everyone has to use VERB
	if ((verb_id>=0)&&(verb_id<=RUN_FUNC_VERBS-1)){
		verb = verb_list[verb_id];
	}
	else{
		//if verb is invalid, check whether it is one of the required verbs
		
		printf("Verb Invalid\n");
		return -1;
	}
	
	int item=feat_valid(feat_index_id);
	string feat_string;
	if (item!=-1){
		feat_string=r_array[player1.get_current_room()]->get_feature_x(item)->get_name(); 
	}
	else if (item==-1){
		printf("You cannot access this feature within %s.\n", r_array[player1.get_current_room()]->get_name().c_str());
	}
	
	if (verb_id>=NUM_VERB_FUNCS){
		if ((feat_index_id!=-1)&&(obj_index_id==-1))
		{
			if ((item>=0)&&(item<=1)){
				printf("Running %s on on FEAT %s in room %s\n", verb.c_str(), feat_string.c_str(), r_array[player1.get_current_room()]->get_name().c_str());
//				if (user_or_room_has_item(obj_index_id)==0){
				if (verb.compare(STR_RVERB1)==0){ res = r_array[player1.get_current_room()]->get_feature_x(item)->RVERB1(); }
//				}
				
				else if (verb.compare(STR_RVERB2)==0){ printf("You can't take that\n"); }
				else if (verb.compare(STR_RVERB3)==0){ printf("You can't drop that\n"); }
			}
		}
		else if ((feat_index_id==-1)&&(obj_index_id!=-1)){
			
			if ((obj_index_id <= 7)&&(obj_index_id>=0))
			{	printf("Running %s on OBJECT %s in room %s\n", verb.c_str(), o_array[obj_index_id]->get_name().c_str(), r_array[player1.get_current_room()]->get_name().c_str());
				if (user_or_room_has_item(obj_index_id)==0){
					if (verb.compare(STR_RVERB1)==0){ res = o_array[obj_index_id]->RVERB1(); }//look
				}
				else if (verb.compare(STR_RVERB2)==0){ RVERB2(obj_index_id); }//take
				else if (verb.compare(STR_RVERB3)==0){ RVERB3(obj_index_id); }//drop	
			}	
		}
	}
	if ((verb_id>=0)&&(verb_id<=NUM_VERB_FUNCS-1))
	{
		//if ((feat_index_id!=-1)&&(obj_index_id==-1))
			//{
				
				
				if ((item>=0)&&(item<=1))
				{
				//	printf("Running %s on on FEAT %s that does NOT take OBJECT in room %s\n", verb.c_str(), feat_string.c_str(), r_array[player1.get_current_room()]->get_name().c_str());
					if (verb.compare(STR_VERB1)==0){ res = r_array[player1.get_current_room()]->get_feature_x(item)->VERB1(); }
					else if (verb.compare(STR_VERB2)==0){ res = r_array[player1.get_current_room()]->get_feature_x(item)->VERB2(); }
					else if (verb.compare(STR_VERB4)==0){ res = r_array[player1.get_current_room()]->get_feature_x(item)->VERB4(); }
					else if (verb.compare(STR_VERB5)==0){ res = r_array[player1.get_current_room()]->get_feature_x(item)->VERB5(); }
					else if (verb.compare(STR_VERB7)==0){ res = r_array[player1.get_current_room()]->get_feature_x(item)->VERB7(); }
					else if (verb.compare(STR_VERB9)==0){ res = r_array[player1.get_current_room()]->get_feature_x(item)->VERB9(); }

				//printf("Running %s on FEAT %s that DOES take OBJECT with object %s in room %s\n", verb.c_str(), feat_string.c_str(), o_array[obj_index_id]->get_name().c_str(), r_array[player1.get_current_room()]->get_name().c_str());
	
					if (verb.compare(STR_VERB3)==0){ res = r_array[player1.get_current_room()]->get_feature_x(item)->VERB3(obj_index_id); }
					else if (verb.compare(STR_VERB6)==0){ res = r_array[player1.get_current_room()]->get_feature_x(item)->VERB6(player1.get_current_room(), obj_index_id); }
					else if (verb.compare(STR_VERB8)==0){ 
						if ((feat_index_id==VAMPIRE)&&(obj_index_id==CHALICE)){
							res = r_array[player1.get_current_room()]->get_feature_x(item)->VERB8(get_room_events_triggered(24), obj_index_id); 
						}
						else if ((feat_index_id==DEMON)&&(r_array[player1.get_current_room()]->get_feature_x(item)->get_times_toggled(USE)==1)){
							//if chalice has been "used" once i.e. "filled" and it has not been "emptied" by traveling to the library...
							res = r_array[player1.get_current_room()]->get_feature_x(item)->VERB8(player1.get_current_room(), obj_index_id); 
						}
						else if ((feat_index_id==DEMON)&&(r_array[player1.get_current_room()]->get_feature_x(item)->get_times_toggled(USE)!=1))
						{
							printf("There is nothing special in this cup to protect you. The demon notices you and you know you are done for\n");
							res = -1;
						}
						else{
							res = r_array[player1.get_current_room()]->get_feature_x(item)->VERB8(player1.get_current_room(), obj_index_id); 
						}
					}
					else if (verb.compare(STR_VERB10)==0){ res = r_array[player1.get_current_room()]->get_feature_x(item)->VERB10(obj_index_id); }
				}
				else if ((feat_index_id==-1)&&(obj_index_id!=-1)){
				printf("Running %s on OBJECT %s in room %s\n", verb.c_str(), o_array[obj_index_id]->get_name().c_str(), r_array[player1.get_current_room()]->get_name().c_str());
				if ((obj_index_id <= 7)&&(obj_index_id>=0))
				{
					if (verb.compare(STR_VERB1)==0){ 
						
						 
						if (event8counter>=1){
							printf("You open the book to the correct spell and read:\n'As sure as the demon is evil'\n'We will trap the dark soul and his smallness reveal'\n");
							res=35;
							
							
						}
						else{
							res = o_array[obj_index_id]->VERB1();
							event8counter = 0;
						}
						
					}
					else if (verb.compare(STR_VERB2)==0){ res = o_array[obj_index_id]->VERB2(); }
					else if (verb.compare(STR_VERB3)==0){ res = o_array[obj_index_id]->VERB3(-1); }
					else if (verb.compare(STR_VERB4)==0){ res = o_array[obj_index_id]->VERB4(); }
					else if (verb.compare(STR_VERB5)==0){ res = o_array[obj_index_id]->VERB5(); }
					else if (verb.compare(STR_VERB6)==0){ res = o_array[obj_index_id]->VERB6(player1.get_current_room(), -1); }
					else if (verb.compare(STR_VERB7)==0){ res = o_array[obj_index_id]->VERB7(); }
					else if (verb.compare(STR_VERB8)==0){ res = o_array[obj_index_id]->VERB8(player1.get_current_room(), -1); }
					else if (verb.compare(STR_VERB9)==0){ res = o_array[obj_index_id]->VERB9(); }
					else if (verb.compare(STR_VERB10)==0){ res = o_array[obj_index_id]->VERB10(obj_index_id); }
					
				}	
				

			}
			
	}
	
	if (res!=-666){	
			printf("RES: %i\n", res);
			if ((res==0)||(res==1)||(res==2)){
				printf("----about to trigger event----\n");
				//rach player can have max 3 events, so get result (event 0->1, 1->2, 2->3), plus 3 times the current room you are in to set the value to EVENT TRIGGERED 
				int event_index = res+(3*player1.get_current_room());
				printf("triggering %i", event_index);
				room_events_triggered[event_index]=1;
				printf("get events triggered val now: %i", get_room_events_triggered(event_index));
				
				//trigger the events now
				printf("rval: %i", r_array[player1.get_current_room()]->get_event_triggered(res));
				if (r_array[player1.get_current_room()]->get_event_triggered(res)==0){
					printf("event has been triggered\n");
					res = r_array[player1.get_current_room()]->trigger_event(res);
					printf("res:%i", res);
				}
				
			}
			//player is DEAD
			if (res==-1){
				printf("You have died\n");
				player1.set_player_alive(0);//set to FALSE
				
				return -1;
				
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
			//for events that trigger exits
			if ((res >=10)&&(res <=10+NUM_ROOMS)){
				
				player1.set_current_room(res-10);
				look();
			} 
			if (res==31){
				
				event2();
			}
			if (res==32){
				event3();
			}
			if (res==33){
				event4();
			}
//			if (res==34){
//				event5();
//			}
			if (res==35){
				event7();
			}
			if (res==36){
				event8();
			}
			if (res==37){
				//transports all items to the Kitchen and changes the description to account for all objects. 
				event9();
			}
			if (res==38){
				event10();
			}
			if (res==39){
				event11();
			}
			if (res==40){
				event12();
			}
			if (res==45+obj_index_id){
				event6(res-45);
			}
			if(((room_events_triggered[13]==1)&&(room_events_triggered[15]==1)&&(room_events_triggered[21]==1))|| ((room_events_triggered[20]==1)&&(room_events_triggered[15]==1)&&(room_events_triggered[21]==1)))
			{
				event5();
			}
			
			//21, 13, 15
			printf("FINAL RES:%i\n", res);
			return 0;
		
	}
	printf("FINAL RES:%i\n", res);
	return 4;
	
	
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
		r_array[room_id]->set_event_triggered(2, val);
	}
	else {
		room_id = event_index/3;
		int which_event = event_index%3;
		if (which_event == 2){
			r_array[room_id]->set_event_triggered(1, val);
		}
		else {
			r_array[room_id]->set_event_triggered(0, val);
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
void Game::help(){
	for (int i = 0; i < NUM_VERB_FUNCS; i++){
		printf("%s, ", verb_list[i].c_str());
	}
	for (int i = 0; i < NUM_REQ_VERBS; i++){
		printf("%s, ", req_verb_list[i].c_str());
	}
}
int Game::get_is_locked(int obj_index){
	return is_locked[obj_index];
}
void Game::set_is_locked(int obj_index, int val){
	is_locked[obj_index] = val;
}
int Game::get_needs_event(int room_index){
	return room_needs_event_x[room_index];
}
void Game::set_needs_event(int room_index, int event_number)
{
	room_needs_event_x[room_index]=event_number;
}
void Game::print_all_feature_desc(){
	for (int i = 0; i < NUM_ROOMS; i++)
	{
		printf("%i-0:%s\n", i+1, r_array[i]->get_feature_x(0)->get_desc().c_str());
		printf("%i-1:%s\n", i+1, r_array[i]->get_feature_x(1)->get_desc().c_str());
	}
}
string Game::get_all_is_locked(){
	string bin_str_arr="";
	for (int i = 0; i < NUM_OBJECTS; i++){
		bin_str_arr=bin_str_arr + to_string(get_is_locked(i));	
	}
	return bin_str_arr;
}
void Game::set_all_is_locked(int bin_arr[NUM_OBJECTS]){
	for (int i = 0; i < NUM_OBJECTS; i++){
		set_is_locked(i, bin_arr[i]);
	}
}
void Game::set_player_has_all_objects(int set[NUM_OBJECTS]){
	for (int i = 0; i < NUM_OBJECTS; i++){
		player1.set_has_objects(i, set[i]);
		
		current_obj_location[i]=-1;
		
	}
	for (int i = 0; i < NUM_ROOMS; i++){
		for (int j=0; j<NUM_OBJECTS; j++){
			if (set[j]==1){
				r_array[i]->set_has_objects(j, 0);
			}
			
		}
		
	}
}
Game::~Game() {

}