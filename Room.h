//
// Room.h
// Created by Claudia Rodriguez-Schroeder on 1/2/20.

#ifndef _Room_h_
#define _Room_h_
#include <string>
#include <cstdio>
#include "Feature.h"

#include "globals.h"
using namespace std;
//an abstract class
class Room {
public:
	Room();
	virtual ~Room();

	string get_name();
	void set_name(string name);
	
	int get_room_id();
	void set_room_id(int room_id);
	
	string get_short_description();
	void set_short_description(string description);
	
	string get_long_description();
	void set_long_description(string description);
	
	string get_extra_description();
	void set_extra_description(string description);
	
	Feature get_feature_x(int x);
	void set_feature_x(Feature s_feature_x, int x);
	
	string get_exit_name(int direction);//0 = north, 1 = south; 2 = east; 3 west;
	void set_exit_name(string s_exit_name, int direction);//0 = north, 1 = south; 2 = east; 3 west;
	string get_exit_dir(int exit_index);
	void set_exit_dir(string exit_dir, int exit_index);
	
	
	string get_exit_x(int direction, int x);//x being exit_1 : go + direction, exit_2 : direction, exit_3 : exit_namae
	void init_exits();
	
	
	int get_room_entered();
	void set_room_entered(int s_room_entered);
	
	int get_has_objects(int object_index);
	void set_has_objects(int object_index, int val);
	
	int get_exit_id(int exit_index);
	void set_exit_id(int room_id, int exit_index);
	

	string exit_text();
	string feature_text();
	void add_object_text(string object_name, string object_desc);
	int get_num_exits();
	int get_num_obj();

	void init_long_short_desc();
	string look();//if user has been there before, return short desc;

	
	
	

	
	
private:
	
	string name;//name of room
	int room_id;//room id corresponding to its index within the Game class array of rooms. 
	string long_description;//include exit name & long description, exit direction FIXED feature description, UNFIXED object description
	string short_description;//include exit name & short description, exit direction FIXED feature description, UNFIXED object descriptoin
	string extra_description; //the piece added to the short description to make it longer
	
	string exit_name[MAX_EXITS];//name for each exit for north = 0, south = 1; east = 2; west = 3; if no exit, "no_exit"
	string exit_desc[MAX_EXITS];//exit description
	string exit_direction[MAX_EXITS];//for ease of setting exit_1 and exit_2; 
	int exit_ids[MAX_EXITS];//array of exits on north, south, east, west; if none, number is -1;
	
	string exit_1[MAX_EXITS];//go + direction
	string exit_2[MAX_EXITS];//direction
	string exit_3[MAX_EXITS];//go + name
	string exit_4[MAX_EXITS];//name
		
	//Number of features
	Feature fixed_list[MAX_FIXED];
	int room_entered;


	//an array of 0 or 1 based on whether the item is in that room at that time; for purpose of accurate room description
	int has_objects[NUM_OBJECTS];
	
	int obj_count;
	int num_exits;
	
	

	
};




#endif