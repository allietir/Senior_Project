//
// Room.h
// Created by Claudia Rodriguez-Schroeder on 1/2/20.

#ifndef _Room_h_
#define _Room_h_
#include <string>
#include <cstdio>
#include "Feature.h"
using namespace std;

//an abstract class
class Room {
public:
	Room();
	virtual ~Room();
//get/set
	string get_name();
	void set_name(string name);
	
	int get_room_id();
	void set_room_id(int room_id);
	
	string get_short_description();
	void set_short_description(string description);
	
	string get_long_description();
	void set_long_description(string description);
	
	string get_exit();
	void set_exit(string exit);
	
	Feature get_feature_1();
	void set_feature_1(Feature feature_1);
	
	
	Feature get_feature_2();
	void set_feature_2(Feature feature_1);
	
	int get_next_room();
	void set_next_room(int next_room);
	
	int get_room_entered();
	void set_room_entered(int room_entered);
	
	int get_has_items(int is_has_items);
	void set_all_has_items(int x);
	void toggle_has_items(int is_has_items);
	
	
private:
	string name;
	int room_id;
	
	string long_description;//describes exit
	string short_description;//describes exit
	
	string exit;
	string entrance;
	
	Feature feature_1;
	Feature feature_2;
	
	
	int next_room;
	
	int room_entered;
	//an array of 0 or 1 based on whether the item is in that room at that time 
	int has_items[8];
	//value at index denotes whether or not the item can be dropped in that room
	int can_drop_item[8];
	
};




#endif