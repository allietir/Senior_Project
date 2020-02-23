//
// Game.h
// Created by Claudia Rodriguez-Schroeder on 1/2/20.

#ifndef _Game_h_
#define _Game_h_
#include "Room/Room.h"
#include "Player.h"
#include "Room/Room1.h"
#include "Room/Room2.h"
#include "Room/Room3.h"
#include "Room/Room4.h"
#include "Room/Room5.h"
#include "Room/Room6.h"
#include "Room/Room7.h"
#include "Room/Room8.h"
#include "Room/Room9.h"
#include "Room/Room10.h"
#include "Room/Room11.h"
#include "Room/Room12.h"
#include "Room/Room13.h"
#include "Room/Room14.h"
#include "Room/Room15.h"

#include "Object/Object.h"
#include "globals.h"


//OBJECT
#include "Object/Object1.h"
#include "Object/Object2.h"
#include "Object/Object3.h"
#include "Object/Object4.h"
#include "Object/Object5.h"
#include "Object/Object6.h"
#include "Object/Object7.h"
#include "Object/Object8.h"


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
	void take_event(int object_id, int room_id);
	void drop(int object_id);
	void inventory();
	//so game can know where objects currently are, updated in "take" and "drop" functions
	void set_obj_location(int obj_id, int location);
	int get_obj_location(int obj_id);
	
	void exit_room(int dir);//take room of exit as parameter and update variables so that player is in new room
	//void exit_r1_r8();
	
	Object* get_object_x(int x);
	void set_object_x(Object obj, int x);
	Room* get_room_x(int x);
	void set_room_x(Room r, int x);
	
	int user_or_room_has_item(int item_id);
	int user_has_item(int item_id);
	int room_has_item(int item_id);
	
	int exit_valid(int next_room);
	
	void event1();
	void event2();
	void event3();
	void event4();
	void event5();
	void event6(int obj_id);
	void event7();
	void event8();
	void event9();
	void event10();
	void event11();
	void look();//trigger current room look
	
	//extra exits
	void climb(int context_id);//
	int attack(int context_id, int obj_id);//
	
	
	Player* get_player();
	void set_player(Player* playerx);
	
	//------HELPERS FOR PARSER//
	int get_context_id_from_string(string feat_name);//return context_id 
	int get_obj_id_from_string(string obj_name);
	
	int kill_player();
	

	void gen_feat_list();
	string get_feat_list(int x);
	void output_feat_list();
	
	int run_func(int feat_index_id, int obj_index_id, int verb_id);
	int exit_current_from_room_id(int room_id);
	
	void set_times_rooms_visited(int room_id, int new_time);
	int get_times_room_visited(int room_id);
	
	void set_game_events_triggered(int event_index, int val);
	int get_game_events_triggered(int event_index);
	
	void set_room_events_triggered(int event_index, int val);
	int get_room_events_triggered(int event_index);
	
	void trigger_take_event(int obj_id);
	
	//------HELPERS FOR LOADER----//
	//wrappers
	void set_all_times_rooms_visited(int bin_arr[NUM_ROOMS]);
	string get_all_times_rooms_visited();
	
	void set_all_game_events_triggered(int bin_arr[NUM_GAME_EVENTS]);
	string get_all_game_events_triggered();
	
	void set_all_player_objects(int bin_arr[NUM_OBJECTS]);
	string get_all_player_objects();
	
	void set_all_room_objects(int bin_arr[NUM_OBJECTS]);
	string get_all_room_objects();
	
	void set_all_room_events_triggered(int bin_arr[NUM_EVENTS]);
	string get_all_room_events_triggered();
	
	
	void output_obj_list();
	void output_verb_list();
	void output_room_list();
	
	int feat_valid(int feat_index_id);
	int verb_index_from_string(string verbx);
	string verb_string_from_index(int verbx);
	
	void help();
	
	int get_is_locked(int obj_index);
	void set_is_locked(int obj_index, int val);
	
	string get_all_is_locked();
	void set_all_is_locked(int bin_arr[NUM_OBJECTS]);

	int get_needs_event(int room_index);
	void set_needs_event(int roov_index, int event_numbers);
	
	void print_all_feature_desc();

	void set_player_has_all_objects(int set[NUM_OBJECTS]);
	string concat_obj_descs();
	
	void output_current_object_locations();
	void output_feature_list_locations();
//todo:
	/*
		get connect string to feat_id in room for climb/jump
		start new game interface when player dies
	*/
	
private:	
	Object* o_array[NUM_OBJECTS];
	Room* r_array[NUM_ROOMS];
	string event1_text;	
	
	int game_events_triggered[NUM_GAME_EVENTS];
	//on start, locket is locked, doll, chalice is locked
	int is_locked[NUM_OBJECTS]={0, 0, 1, 0, 0, 1, 0, 1};
	
	Player player1;
	string save_text;
	string load_text;
	int save_version;
	int current_obj_location[NUM_OBJECTS];
	int room_obj_set[NUM_OBJECTS]={ENTRANCEWAY, DINING, NURSURY, GUEST, FRONT, ATTIC, LIBRARY, CONSERVATORY};
	int room_needs_object1[NUM_OBJECTS]={2, 3, 4, 5, 6, 7, 8, 13};
	

	//room i needs event at index to occur before you can enter. if -1, no event needed
	int room_needs_event_x[NUM_ROOMS]={-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 39};
	
	string verb_list[NUM_STR_VERBS]={STR_VERB1, STR_VERB2, STR_VERB3, STR_VERB4, STR_VERB5, STR_VERB6, STR_VERB7, STR_VERB8, STR_VERB9, STR_VERB10};
	string req_verb_list[NUM_REQ_VERBS]={STR_RVERB1, STR_RVERB2, STR_RVERB3, STR_RVERB4, STR_RVERB5, STR_RVERB6, STR_RVERB7, STR_RVERB8, STR_RVERB9, STR_RVERB10, STR_RVERB11, STR_RVERB12};
	string total_verb_list[NUM_STR_VERBS+NUM_REQ_VERBS]={STR_VERB1, STR_VERB2, STR_VERB3, STR_VERB4, STR_VERB5, STR_VERB6, STR_VERB7, STR_VERB8, STR_VERB9, STR_VERB10, STR_RVERB1, STR_RVERB2, STR_RVERB3, STR_RVERB4, STR_RVERB5, STR_RVERB6, STR_RVERB7, STR_RVERB8, STR_RVERB9, STR_RVERB10, STR_RVERB11, STR_RVERB12};
	
	int room_events_triggered[NUM_EVENTS];
	int times_rooms_visited[NUM_ROOMS];
	
	
	string feat_list[TOTAL_FIXED];
	
	int event8counter;

	
	
		
	
	

	
};

#endif