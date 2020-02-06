//
// Game.h
// Created by Claudia Rodriguez-Schroeder on 1/2/20.

#ifndef _Game_h_
#define _Game_h_
#include "Room/Room.h"
#include "Player.h"
#include "Room/Room1.h"
#include "Room/Room2.h"
#include "Room/Room3.h"
#include "Room/Room4.h"
#include "Room/Room5.h"
#include "Room/Room6.h"
#include "Room/Room7.h"
#include "Room/Room8.h"
#include "Room/Room9.h"
#include "Room/Room10.h"
#include "Room/Room11.h"
#include "Room/Room12.h"
#include "Room/Room13.h"
#include "Room/Room14.h"
#include "Room/Room15.h"

#include "Object/Object.h"
#include "globals.h"


//OBJECT
#include "Object/Object1.h"
#include "Object/Object2.h"
#include "Object/Object3.h"
#include "Object/Object4.h"
#include "Object/Object5.h"
#include "Object/Object6.h"
#include "Object/Object7.h"
#include "Object/Object8.h"


class Game {
public:
	Game();
	virtual ~Game();
	
	void init_rooms();
	void init_objects();
	void init_player();
	
	void start();

	void set_save_version(int int_x);
	int get_save_version();
	
	void take(int object_id);
	void take_event(int object_id, int room_id);
	void drop(int object_id);
	void inventory();
	//so game can know where objects currently are, updated in "take" and "drop" functions
	void set_obj_location(int obj_id, int location);
	int get_obj_location(int obj_id);
	
	void exit_room(int dir);//take room of exit as parameter and update variables so that player is in new room
	//void exit_r1_r8();
	
	Object* get_object_x(int x);
	void set_object_x(Object obj, int x);
	Room* get_room_x(int x);
	void set_room_x(Room r, int x);
	
	int exit_valid(int next_room);
	
	void event1();
	void look();//trigger current room look
	
	//extra exits
	void climb(int context_id);//
	int attack(int context_id, int obj_id);//
	//------HELPERS FOR PARSER//
	int get_context_id_from_string(string feat_name);//return context_id 
	int get_obj_id_from_string(string obj_name);
	
	int kill_player();
	

	void gen_feat_list();
	string get_feat_list(int x);
	void output_feat_list();
	
	int run_func(string item, string obj_name, string verb);
	int exit_current_from_room_id(int room_id);
	
	
	//------HELPERS FOR LOADER----//
	


//todo:
	/*
		get connect string to feat_id in room for climb/jump
		start new game interface when player dies
	*/
	
//private:	
	Object* o_array[NUM_OBJECTS];
	Room* r_array[NUM_ROOMS];
	string event1_text;	
	
	Player player1;
	string save_text;
	string load_text;
	int save_version;
	int current_obj_location[NUM_OBJECTS];
	int room_obj_set[NUM_OBJECTS]={1, 3, 10, 6, 0, 11, 5, 9};
	int room_needs_object1[NUM_OBJECTS]={2, 3, 4, 5, 6, 7, 8, 13};
	
	int room_events_triggered[NUM_EVENTS];
	int times_rooms_visited[NUM_ROOMS];
	string feat_list[TOTAL_FIXED];
	
		
	
	

	
};

#endif