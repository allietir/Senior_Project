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
	void get_input(string prompt, int input_size);
	
	Object o_array[8];
	Room r_array[15];
	Room1 room_1;
	Room2 room_2;
	Player player1;
	string prompt_1;
	//required verbs
	string look;
	string look_at_x;
	string exit_1;
	string exit_2;
	string exit_3;
	string exit_4;
	string take;
	string help;
	string inventory;
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
	
};

#endif