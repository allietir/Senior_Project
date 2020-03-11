//
// Player.h
// Created by Claudia Rodriguez-Schroeder on 1/2/20.

#ifndef _Player_h_
#define _Player_h_
#include <string>
#include <cstdio>
#include "globals.h"
using namespace std;
class Player {
public:
	Player();
	virtual ~Player();
	
	string get_name();
	void set_name(string s_name);
	
	int get_current_room();//get_current room
	void set_current_room(int s_current_room);//set current room
	
	int get_has_objects(int item_index);
	void set_has_objects(int item_index, int val);
	
	int get_move_count();
	void set_move_count(int s_move_count); 
	
	int get_player_alive();
	void set_player_alive(int alive_val); 

	int get_can_take();
	void set_can_take(int s_can_take);
	
	int get_saving();
	void set_saving(int x);
	
	int get_loading();
	void set_loading(int x);
	
		
	
private:
	string name;
	int current_room;//corresponds to the room_id, which in turn corresponds to the room index in the Game room array. 
	//an array of 0 or 1 based on whether the player currently has those items
	int has_objects[NUM_OBJECTS];
	int move_count;
	int player_alive;
	int can_take;
	int player_loading;
	int player_saving;


	
	
	


	
	
	
};

#endif