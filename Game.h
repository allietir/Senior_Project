//
// Game.h
// Created by Claudia Rodriguez-Schroeder on 1/2/20.

#ifndef _Game_h_
#define _Game_h_
#include "Room.h"
#include "Player.h"
#include "Room1.h"
#include "Room2.h"
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