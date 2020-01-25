//
// Feature.h
// Created by Claudia Rodriguez-Schroeder on 1/2/20.

#ifndef _Feature_h_
#define _Feature_h_
#include <string>
#include <cstdio>
#include "globals.h"

using namespace std;
class Feature {
public:
	Feature();
	void init_attributes(string atts[10], string alts[10]);
	
	string get_name();
	void set_name(string s_name);
	
	int get_index_id();
	void set_index_id(int s_index_id);
	
	string get_desc();
	void set_desc(string s_desc);
	
	int get_feature_examined();
	void set_feature_examined(int s_feature_examined);
	
	int get_fixed();
	void set_fixed(int s_fixed);
	
	int get_current_room();
	void set_current_room(int s_current_room);
	string look();//return desc
	string read();//verb func 0: verb_func_toggled[0]
	
	int func_togg_count_x(int x);
	
	//TO ADD:
		// a list of functions that correspond to each verb within the game
	
virtual ~Feature();
private:
	string name;//Feature or Object Name
	int index_id;//Feature or object id so that it is easy for an object to see if it works with that feature or object; this is set in the Game class and corresponds exactly to its poisiton within an array; features and objects will have separate arrays to reference 
	string desc;//Description of Feature or Object 
	//IDEA:  that can be up to MAX_DESC; each will be revealed each time the user "look"s at it. 
	int feature_examined;//indicate whether a feature or object has been examined 
	
	int fixed;//indicate whether the feature can be removed from the room; some bojects can't be removed unless the game is in a specific state. fixed = 1, unfixed = 0;
	string error_message;
	
	//GAME STATE VARIABLES
	int current_room; //take note of the ith room you are in; coresponds exactly to an index array set in Game

	int look_count;//a measure of how many times "look" is toggled 
	int verb_func_toggled[NUM_VERB_FUNCS];//keep track of how many times the function is toggled. 
	
friend class Room;
};

#endif