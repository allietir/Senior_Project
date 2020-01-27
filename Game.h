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
#include "Room4.h"
#include "Room5.h"
#include "Room6.h"
#include "Room7.h"
#include "Room8.h"
#include "Room9.h"
#include "Room10.h"
#include "Room11.h"
#include "Room12.h"
#include "Room13.h"
#include "Room14.h"
#include "Room15.h"

#include "Object.h"
#include "globals.h"


//OBJECT
#include "Object1.h"
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
	
	void exit_room(int dir);//take room of exit as parameter and update variables so that player is in new room
	
	Object* get_object_x(int x);
	void set_object_x(Object obj, int x);
	Room* get_room_x(int x);
	void set_room_x(Room r, int x);
	
	void event1();
	

//private:	
	Object* o_array[NUM_OBJECTS];
	Room* r_array[NUM_ROOMS];
	string event1_text;

	//Room3 room_3;
	//Object1 object_1;
//	Object2 object_2;
//	Object3 object_3;
//	Object4 object_4;
//	Object5 object_5;
//	Object6 object_6;
//	Object7 object_7;
//	Object8 object_8;

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