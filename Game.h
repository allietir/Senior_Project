//
// Game.h
// Created by Claudia Rodriguez-Schroeder on 1/2/20.

#ifndef _Game_h_
#define _Game_h_
#include "Room.h"
#include "Player.h"
#include "Room1.h"
#include "Room2.h"
#include "Room3.h"
#include "Object.h"
#include "globals.h"


//OBJECT
#include "Knife.h"
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
	void drop(int object_id);
	void inventory();
	//so game can know where objects currently are, updated in "take" and "drop" functions
	void set_obj_location(int obj_id, int location);
	int get_obj_location(int obj_id);
	

	
	Object o_array[NUM_OBJECTS];
	Room r_array[NUM_ROOMS];
	Room1 room_1;
	Room2 room_2;
	Room3 room_3;
	Knife object_1;
	/*Room4 room_4;
	Room5 room_5;
	Room6 room_6;
	Room7 room_7;
	Room8 room_8;
	Room9 room_9;
	Room10 room_10;
	Room11 room_11;
	Room12 room_12;
	Room13 room_13;
	Room14 room_14;
	Room15 room_15;*/
	
	Player player1;
	
	
	
	string save_text;
	string load_text;
	int save_version;
	int current_obj_location[NUM_OBJECTS];
	
	
	
};

#endif