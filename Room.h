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
	
	void init_long_short_desc();
	
	string get_alt_exp(int x);
	void set_alt_exp(int x, string exper);
	
	string get_exit_dir();
	void set_exit_dir(string exit_dir);
	
	void init_exits();
	
private:
	string name;
	int room_id;
	
	string long_description;//describes exit
	string short_description;//describes exit
	
	string exit;
	string exit_direction;
	
	string exit_1;
	string exit_2;
	string exit_3;
	string exit_4;
	
	string entrance;
	
	Feature feature_1;
	Feature feature_2;
	
	
	int next_room;
	
	int room_entered;
	
	string alt_desc[5];//You can also have additional explanations after the long or short-form description that talk about something that happens to occur while you're there (e.g. "A train whistle sounds across the lonely field").

	//an array of 0 or 1 based on whether the item is in that room at that time 
	int has_items[8];
	//value at index denotes whether or not the item can be dropped in that room
	int can_drop_item[8];
	
};




#endif