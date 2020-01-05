//
// Player.h
// Created by Claudia Rodriguez-Schroeder on 1/2/20.

#ifndef _Player_h_
#define _Player_h_
#include <string>
#include <cstdio>
using namespace std;
class Player {
public:
	Player();
	virtual ~Player();
	void move(int room_id);
	void toggle_has_items(int is_has_item);
	int get_has_items(int is_has_item);
	string name;
	int current_location;
	//an array of 0 or 1 based on whether the player currently has those items
	int has_items[8];
	
};

#endif