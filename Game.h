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
class Game {
public:
	Game();
	virtual ~Game();
	void initialize_rooms();
	void init_objects();
	void start();
	void get_next_step();
	void init_verbs();
	void save();
	void load(string file_name);
	void get_input(string prompt, int input_size);
	
	Object o_array[8];
	Room r_array[15];
	Room1 room_1;
	Room2 room_2;
	Room3 room_3;
	Room4 room_4;
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
	Room15 room_15;
	Player player1;
	string prompt_1;
	//required & special verbs
	string look;//call LONG ROOM description
	string look_at_x;//call DESCRIPTION of FEATURE or OBJECT
	
	string exit_1;//text; go <exit>
	string exit_2;//text; <exit>
	string exit_3;//text; go <exit-description>
	string exit_4;//text; <exit-description>
	
	string take;//only applied to OBJECTS and toggles PLAYER inventory
	string help;//only called by GAME
	string inventory;//only applies to PLAYER
	
	
	//10 primary actions
	/*string verb1;
	string verb2;
	string verb3;
	string verb4;
	string verb5;
	string verb6;
	string verb7;
	string verb8;
	string verb9;
	string verb10;*/
	string verb_x[10];
	string save_text;
	
};

#endif