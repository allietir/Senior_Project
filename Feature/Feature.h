//
// Feature.h
// Created by Claudia Rodriguez-Schroeder on 1/2/20.

#ifndef _Feature_h_
#define _Feature_h_
#include <string>
#include <cstdio>
#include "../globals.h"

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
	
	int get_look_count();
	void set_look_count(int x);
	
	virtual void look();//return desc
	
	/*Your game must support an action vocabulary space (verbs) of at least ten primary actions (hit, pull, go, eat, etc.). These verbs must allow interaction with each feature in each room (a generic "you can't eat that" type of message is OK to use with some verbs).
	Some verbs must cause the player to move between rooms.*/
	
	
	//objec verbs
	virtual void read();//verb func 0: verb_func_toggled[0]
	//virtual void light();//light the lamp or rooms that have switches
	//virtual void fill();//used to fill chalice with blood or holy water within the conservatory feature and vampire blood feature
	
	//
	virtual void pull();//1
	virtual void push();//2

	virtual void turn();//3
	virtual void play();//4
	virtual void open();//5
	virtual void speak();//6talk to a feature or object 
	virtual void listen();//7user to interact with some features or objects potentially
	//will allow user to exit
	virtual void climb();//8use to interact with some features to exit between rooms
	virtual void jump();//9user to interact with some features to exit between rooms
	virtual void attack();//10 
	

		
		
	//object plus feature
	//virtual void place(int feature_index);//called on an object verb you use in conjunction with a feature
	//will allow user to exit
	//virtual void open(int object_index);//called on a feature that needs to use a KEY object 
	//virtual void attack(int feature_index);//called on object plus a feature; attack something using a feature id
		
	
	
	
	int func_togg_count_x(int x);
	
	int get_times_toggled(int function_id);
	void set_togg_count_x(int x, int new_count);
	
	
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